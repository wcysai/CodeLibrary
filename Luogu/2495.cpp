/*************************************************************************
    > File Name: 2495.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-18 00:15:44
 ************************************************************************/
#include<bits/stdc++.h>
#define MAXV 300005
#define INF 100000000000000LL
#define MAXLOGV 22
using namespace std;
typedef long long ll;
struct edge
{
    ll to,cost;
};
vector<edge> G[MAXV];
vector<ll> vt[MAXV];
ll root;
ll parent[MAXLOGV][MAXV];
ll depth[MAXV],dfn[MAXV],dis[MAXV],st[MAXV];
ll n,q,tot;
void add_edge(ll from,ll to)
{
    vt[from].push_back(to);
}
bool cmp(ll x,ll y)
{
    return dfn[x]<dfn[y];
}
void dfs(ll v,ll p,ll d,ll minx)
{
    dfn[v]=++tot;
    dis[v]=minx;
    parent[0][v]=p;
    depth[v]=d;
    for(ll i=0;i<(int)G[v].size();i++)
        if(G[v][i].to!=p) dfs(G[v][i].to,v,d+1,min(minx,G[v][i].cost));
}
void init(ll V)
{
    dfs(1,-1,0,INF);
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
void build_vtree(vector<ll> &a)
{
    sort(a.begin(),a.end(),cmp);
    assert(a.size()>0);
    ll t=0;
    st[t=1]=a[0];
    for(ll i=1;i<(int)a.size();i++)
    {
        if(t==1) {st[++t]=a[i]; continue;}
        ll l=lca(a[i],st[t]);
        if(l==st[t]) continue;
        while(t>1&&dfn[st[t-1]]>=dfn[l]) add_edge(st[t-1],st[t]),t--;
        if(l!=st[t]) add_edge(l,st[t]),st[t]=l;
        st[++t]=a[i];
    }
    while(t>0) add_edge(st[t-1],st[t]),t--;
}
ll dfs2(ll v,ll p)
{
    if(vt[v].size()==0) return dis[v];
    ll sum=0;
    for(ll i=0;i<(int)vt[v].size();i++)
    {
        ll to=vt[v][i];
        if(to==p) continue;
        sum+=dfs2(to,v);
    }
    vt[v].clear();
    return min(sum,dis[v]);
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n-1;i++)
    {
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        G[x].push_back((edge){y,z});G[y].push_back((edge){x,z});
    }
    init(n);
    //for(ll i=1;i<=n;i++) printf("%lld\n",dis[i]);
    scanf("%lld",&q);
    vector<ll> a;
    for(ll i=0;i<q;i++)
    {
        ll k,x;
        scanf("%lld",&k);
        a.clear();a.push_back(1);
        for(ll j=0;j<k;j++) 
        {
            scanf("%lld",&x);
            a.push_back(x);
        }
        build_vtree(a);
        printf("%lld\n",dfs2(1,0));
    }
    return 0;
}
