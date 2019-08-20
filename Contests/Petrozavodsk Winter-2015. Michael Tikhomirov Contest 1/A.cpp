#include<bits/stdc++.h>
#define MAXN 100005
#define MAXV 205
#define MAXE 500005
#define INF 10000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{ll to,cap,cost,rev;};
ll dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV],a[MAXV];
ll n,m,V;
vector<edge> G[MAXV];
void add_edge(ll from,ll to,ll cap,ll cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
P min_cost_flow(ll s,ll t)
{
    assert(s==n+2&&t==n+3);
    ll res=0,f=0;
    fill(h+1,h+V+1,0);
    while(true)
    {
        priority_queue<P,vector<P>,greater<P> > que;
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
        if(dist[t]==INF) return make_pair(f,res);
        for(ll v=1;v<=V;v++) h[v]+=dist[v];
        ll d=INF;
        for(ll v=t;v!=s;v=prevv[v]) d=min(d,G[prevv[v]][preve[v]].cap);
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
char ch[5];
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%lld%lld",&n,&m);
    V=n+3;
    ll s=n+2,t=n+3;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    a[0]=-INF,a[n+1]=INF;
    ll sum=0;
    for(ll i=1;i<=n+1;i++)
    {
        if(a[i-1]>a[i])
        {
            sum+=a[i-1]-a[i];
            add_edge(s,i,a[i-1]-a[i],0);
        }
        else add_edge(i,t,a[i]-a[i-1],0);
    }
    for(ll i=0;i<m;i++)
    {
        ll l,c;
        scanf("%s%lld%lld",ch,&l,&c);
        for(ll i=1;i+l-1<=n;i++) if(ch[0]=='+') add_edge(i,i+l,INF,c); else add_edge(i+l,i,INF,c);
    }
    P p=min_cost_flow(s,t);
    if(p.F<sum) puts("-1"); else printf("%lld\n",p.S);
    return 0;
}
