#include<bits/stdc++.h>
#define MAXN 17
#define MAXM 105
#define MAXV 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll to,cap,cost,rev;};
ll dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
ll V;
vector<edge> G[MAXV];
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
ll n,m,k;
ll a[MAXN][MAXM];
ll offset=1000000;
ll dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main()
{
    freopen("domino.in","r",stdin);
    freopen("domino.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            scanf("%lld",&a[i][j]);
    V=n*m+2;
    ll t=V,s=t-1;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
        {
            if((i+j)&1) add_edge(s,(i-1)*m+j,1,0);
            else add_edge((i-1)*m+j,t,1,0);
        }
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
        {
            if((i+j)&1)
            {
                for(ll k=0;k<4;k++)
                {
                    ll nx=i+dx[k],ny=j+dy[k];
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=m) add_edge((i-1)*m+j,(nx-1)*m+ny,1,offset-a[i][j]*a[nx][ny]);   
                }
            }
        }
    printf("%lld\n",offset*k-min_cost_flow(s,t,k));
    return 0;
}
