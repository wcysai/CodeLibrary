#include<bits/stdc++.h>
#define MAXV 100005
#define MAXE 200005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll to,cap,rev,id;};
ll V,E;
vector<edge> G[MAXV];
ll level[MAXV];
ll iter[MAXV];
ll ans[MAXV];
void add_edge(ll from,ll to,ll cap,ll id)
{
    G[from].push_back((edge){to,cap,(int)G[to].size(),id});
    G[to].push_back((edge){from,0,(int)G[from].size()-1,-id});
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
                if(e.id>0) ans[e.id]+=d; else ans[-e.id]-=d;
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
int main()
{
    scanf("%lld%lld",&V,&E);
    for(ll i=1;i<=E;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add_edge(u,v,w,i);add_edge(v,u,w,-i);
    }
    printf("%lld\n",max_flow(1,V));
    for(ll i=1;i<=E;i++) printf("%lld\n",ans[i]); 
    return 0;
}
