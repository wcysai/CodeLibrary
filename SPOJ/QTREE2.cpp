/*************************************************************************
    > File Name: QTREE2.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 01:14:55
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define MAXV 100005
#define MAXLOGV 20
using namespace std;
typedef long long ll;
struct edge
{
    ll to,cost;
};
vector<edge> G[MAXV];
ll parent[MAXLOGV][MAXV];
ll depth[MAXV],dep[MAXV];
ll t,V,q;
void dfs(ll v,ll p,ll d,ll d2)
{
    parent[0][v]=p;
    depth[v]=d;
    dep[v]=d2;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i].to,cost=G[v][i].cost;
        if(to==p) continue; 
        dfs(to,v,d+1,d2+cost);
    }
}
void init(ll V)
{
    dfs(1,-1,0,0);
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
ll dis(ll u,ll v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
ll findnode(ll u,ll v,ll k)
{
    ll x=lca(u,v);
    if(depth[u]-depth[x]+1>=k)
    {
        ll len=k-1,node=u;
        for(ll i=0;i<MAXLOGV;i++)
            if((len>>i)&1) node=parent[i][node];
        return node;
    }
    else
    {
        ll len=depth[u]+depth[v]-2*depth[x]-k+1,node=v;
        //printf("%lld %lld\n",len,node);
        for(ll i=0;i<MAXLOGV;i++)
            if((len>>i)&1) node=parent[i][node];
        return node;
    }
}
char str[10];
ll x,y;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&V);
        for(ll i=1;i<=V;i++) G[i].clear();
        for(ll i=0;i<V-1;i++)
        {
            ll u,v,cost;
            scanf("%lld%lld%lld",&u,&v,&cost);
            G[u].push_back((edge){v,cost});G[v].push_back((edge){u,cost});
        }
        init(V);
        while(true)
        {
            scanf("%s",str);
            if(str[1]=='O') break;
            if(str[0]=='D')
            {
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",dis(x,y));
            }
            else 
            {
                ll k;
                scanf("%lld%lld%lld",&x,&y,&k);
                printf("%lld\n",findnode(x,y,k));
            }
        }
        if(t) puts("");
    }
    return 0;
}

