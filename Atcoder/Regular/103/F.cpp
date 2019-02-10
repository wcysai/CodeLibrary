#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,d[MAXN],p[MAXN],sz[MAXN];
ll f[MAXN],g[MAXN];
vector<P> v;
vector<ll> G[MAXN];
vector<P> E;
void add_edge(ll u,ll v)
{
    G[u].push_back(v);G[v].push_back(u);
    E.push_back(P(u,v));
}
void dfs1(ll v,ll p)
{
    sz[v]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs1(to,v);
        sz[v]+=sz[to];
        f[v]+=sz[to]+f[to];
    }
}
void dfs2(ll v,ll p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        g[to]=g[v]+n-2*sz[to];
        dfs2(to,v);
    }
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&d[i]);
    for(ll i=1;i<=n;i++) v.push_back(P(d[i],i));
    sort(v.begin(),v.end());
    bool fl=true;
    for(ll i=n-1;i>0;i--)
    {
        sz[v[i].S]++;
        ll to=d[v[i].S]+2*sz[v[i].S]-n;
        auto it=lower_bound(v.begin(),v.end(),P(to,0));
        if(it==v.end()||it->F!=to) 
        {
            fl=false;
            break;
        }
        add_edge(v[i].S,it->S);
        p[v[i].S]=it->S;
        sz[it->S]+=sz[v[i].S];
    }
    if(!fl)
    {
        puts("-1");
        return 0;
    }
    dfs1(v[0].S,0);g[v[0].S]=f[v[0].S];dfs2(v[0].S,0);
    for(ll i=1;i<=n;i++) if(g[i]!=d[i]) {puts("-1"); return 0;}
    for(auto p:E) printf("%lld %lld\n",p.F,p.S);
    return 0;
}

