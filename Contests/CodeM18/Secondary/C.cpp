/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-09 19:34:27
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 200005
#define MAXLOGV 22
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll V,q,x,y,z,l,S,T;
struct edge
{
    ll to,cost,l;
};
vector<edge> G[MAXV];
ll parent[MAXLOGV][MAXV];
ll depth[MAXV],dep1[MAXV],dep2[MAXV];
void dfs(ll v,ll p,ll d,ll d1,ll d2)
{
    parent[0][v]=p;
    depth[v]=d;
    dep1[v]=d1;
    dep2[v]=d2;
    for(ll i=0;i<G[v].size();i++)
    {
        ll to=G[v][i].to,l=G[v][i].l,cost=G[v][i].cost;
        if(to==p) continue;
        ll oddcost=((l&1)?l*cost%MOD:(l+1)*cost%MOD);
        ll evencost=((l&1)?(l+1)*cost%MOD:l*cost%MOD);
        dfs(to,v,d+1,(d1+oddcost)%MOD,(d2+evencost)%MOD);
    }
}
void init(ll V)
{
    dfs(1,-1,0,0,0);
    for(ll k=0;k+1<MAXLOGV;k++)
    {
        for(ll v=1;v<=V;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
ll lca(ll u,ll v)
{
    if(depth[u]>depth[v]) swap(u,v);
    for(ll k=0;k<MAXLOGV;k++)
    {
        if((depth[v]-depth[u])>>k&1)
            v=parent[k][v];
    }
    if(u==v) return u;
    for(ll k=MAXLOGV-1;k>=0;k--)
    {
        if(parent[k][u]!=parent[k][v])
        {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
ll odddis(ll u,ll v)
{
    return ((dep1[u]+dep1[v]-2*dep1[lca(u,v)])%MOD+MOD)%MOD;
}
ll evendis(ll u,ll v)
{
    return ((dep2[u]+dep2[v]-2*dep2[lca(u,v)])%MOD+MOD)%MOD;
}
int main()
{
    scanf("%lld",&V);
    ll sum=0;
    for(ll i=0;i<V-1;i++)
    {
        scanf("%lld%lld%lld%lld",&x,&y,&z,&l);
        G[x].push_back((edge){y,z,l});
        G[y].push_back((edge){x,z,l});
        (sum+=((l&1)?(l+1)*z:l*z))%=MOD;
    }
    init(V);
    scanf("%lld",&q);
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld",&S,&T);
        //printf("%lld %lld\n",evendis(S,T),odddis(S,T));
        ll ans=((sum+odddis(S,T)-evendis(S,T))%MOD+MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}

