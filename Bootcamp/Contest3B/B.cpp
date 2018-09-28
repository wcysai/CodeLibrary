#include<bits/stdc++.h>
#define MAXV 100005
#define MAXE 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll to,cap,rev,id,type;};
ll V,E;
vector<edge> G[MAXV];
ll level[MAXV];
ll iter[MAXV];
bool vis[MAXV];
P a[MAXE];
void add_edge(ll from,ll to,ll cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
void bfs(ll s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        ll v=que.front(); que.pop();
        for(ll i=0;i<(int)G[v].size();i++)
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

ll dfs(ll v,ll t,ll f)
{
    if(v==t) return f;
    for(ll &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            ll d=dfs(e.to,t,min(f,e.cap));
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
ll max_flow(ll s,ll t)
{
    ll flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        ll f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
void DFS(ll v)
{
    vis[v]=true;
    for(auto it:G[v])
    {
        if(it.cap<=0||vis[it.to]) continue;
        DFS(it.to);
    }
}
vector<ll> cut;
int main()
{
    scanf("%lld%lld",&V,&E);
    for(ll i=1;i<=E;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);a[i].F=u;a[i].S=v;
        add_edge(u,v,w);add_edge(v,u,w);
    }
    ll ans=max_flow(1,V),cnt=0;
    memset(vis,false,sizeof(vis));
    DFS(1);
    for(ll i=1;i<=E;i++) 
        if(vis[a[i].F]^vis[a[i].S]) {cnt++; cut.push_back(i);}
    printf("%lld %lld\n",cnt,ans);
    for(auto it:cut) printf("%lld ",it);
    return 0;
}
