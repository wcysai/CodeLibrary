#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{
	cerr << " " << H;
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
#else
	#define debug(...) 42
#endif
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char s[MAXN][MAXN],t[MAXN][MAXN];
int id[MAXN][MAXN];
int same[MAXN*MAXN],dif[MAXN*MAXN];
int w,b,tot;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
set<P> edges;
void bfs(int x,int y)
{
    queue<P> que;
    tot++;
    id[x][y]=tot; que.push(P(x,y));
    while(que.size())
    {
        P p=que.front(); que.pop();
        if(s[p.F][p.S]==t[p.F][p.S]) same[tot]++; else dif[tot]++;
        for(int k=0;k<4;k++)
        {
            int nx=p.F+dx[k],ny=p.S+dy[k];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!id[nx][ny]&&s[nx][ny]==s[x][y])
            {
                id[nx][ny]=tot;
                que.push(P(nx,ny));
            }
        }
    }
}
struct edge{int to,cap,rev;};
vector<edge> G[MAXN*MAXN];
int level[MAXN*MAXN];
int iter[MAXN*MAXN];
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
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
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++) scanf("%s",t[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!id[i][j]&&s[i][j]=='0') bfs(i,j);
    w=tot;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!id[i][j]&&s[i][j]=='1') bfs(i,j);
    int source=tot+1,sink=tot+2,ans=0;
    int sum=0;
    for(int i=1;i<=w;i++)
    {
        ans+=dif[i];
        if(same[i]<dif[i]) 
        {
            sum+=(dif[i]-same[i]);
            add_edge(source,i,dif[i]-same[i]);
        }
    }
    for(int i=w+1;i<=tot;i++)
    {
        ans+=dif[i];
        if(same[i]<dif[i]) 
        {
            sum+=(dif[i]-same[i]);
            add_edge(i,sink,dif[i]-same[i]);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
            {
                int nx=i+dx[k],ny=j+dy[k];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[nx][ny]!=s[i][j])
                {
                    int u=id[i][j],v=id[nx][ny];
                    if(u>v) swap(u,v);
                    edges.insert(P(u,v));
                }
            }
        }
    //debug(ans);
    for(auto p:edges) add_edge(p.F,p.S,INF);
    printf("%d\n",ans-sum+max_flow(source,sink));
    return 0;
}