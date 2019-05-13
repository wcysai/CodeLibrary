#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll to,cap,cost,rev;};
ll dist[MAXN],h[MAXN],prevv[MAXN],preve[MAXN];
ll V;
vector<edge> G[MAXN];
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
            ll v=p.S;
            if(dist[v]<p.F) continue;
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
        if(dist[t]==INF) return -1;
        for(ll v=1;v<=V;v++) h[v]+=dist[v];
        ll d=f;
        for(ll v=t;v!=s;v=prevv[v]) d=min(d,G[prevv[v]][preve[v]].cap);
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
ll n,k;
ll w[MAXN][MAXN];
int main()
{
    freopen("assignment.in","r",stdin);
    freopen("assignment.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            scanf("%lld",&w[i][j]);
    ll s=2*n+1,t=2*n+2;
    V=2*n+2;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            add_edge(i,n+j,1,w[i][j]+2000);
    for(ll i=1;i<=n;i++) add_edge(s,i,k,0);
    for(ll i=1;i<=n;i++) add_edge(i+n,t,k,0);
    printf("%lld\n",min_cost_flow(s,t,k*n)-k*n*2000);
}
