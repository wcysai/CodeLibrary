#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 5005
#define MAXV 11005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m;
ll val[MAXN];
struct edge{ll to,cap,cost,rev;};
ll dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
ll V;
vector<edge> G[MAXV];
const ll shift=1000000;
void add_edge(ll from,ll to,ll cap,ll cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
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
ll d[MAXN][MAXN];
int main()
{
    freopen("rentacar.in","r",stdin);
    freopen("rentacar.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            d[i][j]=(i==j?0:INF);
    for(ll i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        val[i]=x-y;
    }
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }
    V=n+2;
    ll s=n+1,t=n+2;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
        { 
            if(i==j) continue;
            if(d[i][j]==INF) continue;
            add_edge(i,j,INF,d[i][j]);
        }
    ll sum=0;
    for(ll i=1;i<=n;i++) 
        if(val[i]>0) 
        {
            add_edge(s,i,val[i],0);
            sum+=val[i];
        }
        else add_edge(i,t,-val[i],0);
    ll res=min_cost_flow(s,t,sum);
    if(res==-1) puts("-1");
    else printf("%lld\n",res);
    return 0;
}
