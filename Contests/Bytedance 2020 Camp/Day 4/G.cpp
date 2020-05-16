#include<bits/stdc++.h>
#define MAXN 305
#define MAXV 3005
#define MAXE 50000
#define INF 1000000000000LL
using namespace std;
typedef long long ll;
struct edge{int to; ll cap; int rev;};
int V,n,m,p[MAXN];
vector<edge> G[MAXV];
vector<int> H[MAXN];
int color[MAXN];
int level[MAXV];
int iter[MAXV];
void add_edge(int from,int to,ll cap)
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

int dfs(int v,int t,ll f)
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
bool dfs2(int v,int c)
{
    color[v]=c;
    for(auto to:H[v])
    {
        if(color[to]==c) return false;
        if(!color[to]&&!dfs2(to,-c)) return false;
    }
    return true;
}
void solve()
{
    for(int i=1;i<=n;i++)
        if(!color[i])
            dfs2(i,1);
}
vector<int> ans;
int vis[MAXN];
void dfs3(int v)
{
    vis[v]=1;
    for(auto e:G[v])
        if(!vis[e.to]&&e.cap!=0) 
            dfs3(e.to);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        H[u].push_back(v); H[v].push_back(u);
    }
    solve();
    int s=n+1,t=n+2;
    V=n+2;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==1)
        {
            add_edge(s,i,1000000-p[i]);
            for(auto to:H[i]) add_edge(i,to,INF);
        }
        else add_edge(i,t,1000000-p[i]);
    }
    ll res=max_flow(s,t);
    printf("%lld %lld\n",1000000-res%1000000,res/1000000+1);
    memset(vis,0,sizeof(vis));
    dfs3(s);
    for(auto e:G[s])
        if(!vis[e.to]) ans.push_back(e.to);
    for(auto e:G[t])
        if(vis[e.to]) ans.push_back(e.to);
    sort(ans.begin(),ans.end());
    for(auto x:ans) printf("%d ",x);
    return 0;
}

