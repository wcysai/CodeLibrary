#include<bits/stdc++.h>
#define MAXN 605
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,s,t;
struct edge{ll to,cap,cost,rev,id;};
ll dist[MAXN],h[MAXN],prevv[MAXN],preve[MAXN];
ll V;
vector<edge> G[MAXN];
void add_edge(ll from,ll to,ll cap,ll cost,ll id=0)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size(),id});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1,0});
}
ll min_cost_flow(ll s,ll t,ll f)
{
    ll res=0;
    fill(h+1,h+V+1,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist+1,dist+V+1,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top(); que.pop();
            ll v=p.second;
            if(dist[v]<p.first) continue;
            for(ll i=0;i<(int)G[v].size();i++)
            {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF)
        {
            return -1;
        }
        for(ll v=1;v<=V;v++) h[v]+=dist[v];
        ll d=f;
        for(ll v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(ll v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
ll cost[MAXN];
ll ans[MAXN];
int main()
{
    freopen("gas.in","r",stdin);
    freopen("gas.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    ll s=n+1,t=n+2;
    V=n+2;
    ll c=0;
    for(ll i=0;i<m;i++)
    { 
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        c+=w;
        add_edge(u,v,INF-w,1,i+1);
        cost[u]+=w; cost[v]-=w;
    }
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        if(cost[i]>0) {add_edge(i,t,cost[i],0); sum+=cost[i];}
        else add_edge(s,i,-cost[i],0);
    }
    ll f=min_cost_flow(s,t,sum);
    if(f==-1)
    {
        puts("-1");
        return 0;
    }
    for(ll i=1;i<=n;i++)
    {
        for(auto e:G[i])
        {
            if(e.id==0) continue;
            ans[e.id]=INF-e.cap;
        }
    }
    printf("%lld\n",c+f);
    for(ll i=1;i<=m;i++) printf("%lld\n",ans[i]);
    return 0;
}
