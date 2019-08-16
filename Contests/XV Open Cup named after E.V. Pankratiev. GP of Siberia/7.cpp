#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define MAXV 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev,id;};
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
int n,m;
int w[MAXV];
char mp[MAXN][MAXN];
int s,t,S,T;
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size(),1});
    G[to].push_back((edge){from,0,(int)G[from].size()-1,0});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front(); que.pop();
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
void paint(P p,P q)
{
    if(p.F>q.F) swap(p,q);
    if(p.S>q.S) swap(p,q);
    if(p.F==q.F) mp[p.F][p.S]='<',mp[q.F][q.S]='>';
    else mp[p.F][p.S]='^',mp[q.F][q.S]='v';
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0) flow+=f;
    }
}
int tot;
int label[MAXN][MAXN];
int par[MAXM];
int indeg[26],outdeg[26];
vector<int> vert[26];
P pos[MAXM];
P edges[MAXV];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main()
{
    s=49997; t=49998; S=49999; T=50000;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]!='.') {label[i][j]=++tot; pos[tot]=P(i,j); par[tot]=(i+j)&1;}
            else continue;
            if(mp[i][j]>='A'&&mp[i][j]<='Z') vert[(int)(mp[i][j]-'A')].push_back(label[i][j]);
            else
            {
                if(par[tot]) { w[s]++; w[tot]--;}
                else { w[tot]++; w[t]--;}
            }
        }
    int st=tot+1;
    for(int i=0;i<26;i++)
        for(auto v:vert[i])
        {
            if(par[v]) {add_edge(st+i,v,1);  indeg[i]++;}
            else {add_edge(v,st+i,1); outdeg[i]++;}
        }
    tot+=26;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if((i+j)%2==0) continue;
            if(mp[i][j]=='.') continue;
            for(int k=0;k<4;k++)
            {
                int nx=i+dx[k],ny=j+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&mp[nx][ny]!='.') add_edge(label[i][j],label[nx][ny],1);
            }
        }
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        assert((!indeg[i])||(!outdeg[i]));
        if((!indeg[i])&&(!outdeg[i])) continue;
        if(indeg[i]) {add_edge(s,i+st,0); w[s]++; w[i+st]--;}
        else {add_edge(i+st,t,0); w[i+st]++; w[t]--;}
    }
    for(int i=1;i<=50000;i++)
    {
        if(w[i]>0) {add_edge(i,T,w[i]); cnt+=w[i];}
        else if(w[i]<0) add_edge(S,i,-w[i]);
    }
    add_edge(t,s,INF);
    int f=max_flow(S,T);
    if(f!=cnt) {puts("No"); return 0;}
    puts("Yes");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if((i+j)%2==0) continue;
            if(mp[i][j]=='.') continue;
            int v=label[i][j];
            for(auto e:G[v])
            {
                if(e.cap==1||!e.id) continue;
                paint(pos[v],pos[e.to]);
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]>='A'&&mp[i][j]<='Z') mp[i][j]='@';
    for(int i=0;i<n;i++) printf("%s\n",mp[i]);
    return 0;
}
