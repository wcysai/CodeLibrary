#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXV 2025
#define OFF 2000000000LL
#define INF 1000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{ll to,cap,cost,rev;};
ll dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
ll V;
vector<edge> G[MAXV];
ll offset=OFF;
ll N,st,ed;
ll RX[MAXN],RY[MAXN],BX[MAXN],BY[MAXN],RC[MAXN],BC[MAXN];
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
// 1.. N 
// N+1.. 2N
// 2N+1.. 2N+4
// S=2N+5
// T=2N+6
int main()
{
    ll s=0;
    scanf("%lld",&N);
    for(ll i=1;i<=N;i++) scanf("%lld%lld%lld",&RX[i],&RY[i],&RC[i]);
    for(ll i=1;i<=N;i++) scanf("%lld%lld%lld",&BX[i],&BY[i],&BC[i]);
    for(ll i=1;i<=N;i++) s+=RC[i];
    ll tp1=2*N+1,tp2=2*N+2,tp3=2*N+3,tp4=2*N+4,src=2*N+5,dest=2*N+6;
    V=2*N+6;
    for(ll i=1;i<=N;i++)
    {
        add_edge(i,tp1,RC[i],offset-(RX[i]+RY[i]));
        add_edge(i,tp2,RC[i],offset-(-RX[i]+RY[i]));
        add_edge(i,tp3,RC[i],offset-(RX[i]-RY[i]));
        add_edge(i,tp4,RC[i],offset-(-RX[i]-RY[i]));
    }
    for(ll i=1;i<=N;i++)
    {
        add_edge(tp1,N+i,BC[i],offset-(-BX[i]-BY[i]));
        add_edge(tp2,N+i,BC[i],offset-(BX[i]-BY[i]));
        add_edge(tp3,N+i,BC[i],offset-(-BX[i]+BY[i]));
        add_edge(tp4,N+i,BC[i],offset-(BX[i]+BY[i]));
    }
    for(ll i=1;i<=N;i++) add_edge(src,i,RC[i],0);
    for(ll i=1;i<=N;i++) add_edge(N+i,dest,BC[i],0);
    ll ans=min_cost_flow(src,dest,s);
    ans=2LL*s*offset-ans;
    printf("%lld\n",ans);
    return 0;
}

