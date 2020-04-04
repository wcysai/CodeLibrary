#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,s,t;
struct edge{ll to,cap,cost,rev,id;};
ll dist[MAXN],h[MAXN],prevv[MAXN],preve[MAXN];
ll V;
vector<edge> G[MAXN];
void add_edge(ll from,ll to,ll cap,ll cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
pair<ll,ll> min_cost_flow(ll s,ll t)
{
    ll res=0,f=0;
    fill(h+1,h+V+1,0);
    while(true)
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
            return make_pair(res,f);
        }
        for(ll v=1;v<=V;v++) h[v]+=dist[v];
        ll d=INF;
        for(ll v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f+=d;
        res+=d*h[t];
        for(ll v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
}
ll cost[MAXN];
ll ans[MAXN];
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
    V=n;
    for(int i=0;i<m;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add_edge(a,b,c,d);
    }
    pair<ll,ll> p=min_cost_flow(s,t);
    printf("%lld %lld\n",p.second,p.first);
    return 0;
}
