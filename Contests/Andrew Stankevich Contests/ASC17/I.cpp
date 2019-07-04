#include<bits/stdc++.h>
#define MAXN 2005
#define MAXV 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev,id;};
int V;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
void add_edge(int from,int to,int cap,int id)
{
    G[from].push_back((edge){to,cap,(int)G[to].size(),id});
    G[to].push_back((edge){from,0,(int)G[from].size()-1,-1});
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
int n,w;
vector<int> v;
int l[MAXN],r[MAXN];
int nxt[MAXN];
vector<int> start;
int main()
{
    freopen("wall.in","r",stdin);
    freopen("wall.out","w",stdout);
    scanf("%d%d",&n,&w);
    v.push_back(w); v.push_back(0);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&l[i],&r[i]);
        v.push_back(l[i]); v.push_back(r[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)
    {
        l[i]=lower_bound(v.begin(),v.end(),l[i])-v.begin();
        r[i]=lower_bound(v.begin(),v.end(),r[i])-v.begin();
    }
    w=lower_bound(v.begin(),v.end(),w)-v.begin();
    V=2*w;
    int s=0,t=V-1;
    for(int i=1;i<=w-1;i++) add_edge(2*i-1,2*i,1,0);
    for(int i=1;i<=n;i++)
    {
        if(l[i]==0&&r[i]==w) add_edge(s,t,1,i);
        else if(l[i]==0) add_edge(s,2*r[i]-1,1,i);
        else if(r[i]==w) add_edge(2*l[i],t,1,i);
        else add_edge(2*l[i],2*r[i]-1,1,i);
    }
    printf("%d\n",max_flow(s,t));
    for(int i=0;i<V;i++)
    {
        for(auto e:G[i])
        {
            if(e.id<=0) continue;
            if(e.cap==0)
            {
                if(l[e.id]==0) start.push_back(e.id);
                else nxt[l[e.id]]=e.id;
            }
        }
    }
    for(auto x:start)
    {
        int now=x,pos=0;
        while(pos!=w)
        {
            printf("%d ",now);
            pos=r[now];
            now=nxt[pos];
        }
        puts("");
    }
    return 0;
}
