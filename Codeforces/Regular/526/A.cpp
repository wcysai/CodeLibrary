/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-11 00:33:45
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],w[MAXN],f[MAXN],ans;
struct edge
{
    ll to,cost;
};
vector<edge> G[MAXN];
void add_edge(ll u,ll v,ll c)
{
    G[u].push_back((edge){v,c});
    G[v].push_back((edge){u,c});
}
void dfs(ll v,ll p)
{
    f[v]=w[v];
    for(auto e:G[v])
    {
        ll to=e.to,cost=e.cost;
        if(to==p) continue;
        dfs(to,v);
        ans=max(ans,f[v]+f[to]-cost);
        f[v]=max(f[v],f[to]-cost+w[v]);
    }
}
int main()
{
    scanf("%lld",&n);ans=0;
    memset(f,0,sizeof(f));
    for(ll i=1;i<=n;i++) {scanf("%lld",&w[i]); ans=max(ans,w[i]);}
    for(ll i=0;i<n-1;i++)
    {
        ll u,v,c;
        scanf("%lld%lld%lld",&u,&v,&c);
        add_edge(u,v,c);
    }
    dfs(1,0);printf("%lld\n",ans);
    return 0;
}

