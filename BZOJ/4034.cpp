/*************************************************************************
    > File Name: 4034.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-20 01:44:45
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll tot,q,n,k,a[MAXN];
ll pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],st[MAXN],ed[MAXN],tpos[MAXN];
vector<int> G[MAXN];
struct segtree
{
    ll sum[4*MAXN],lazy[4*MAXN];
    void modify(ll k,ll l,ll r,ll v)
    {
        sum[k]+=(r-l+1)*v;lazy[k]+=v;
    }
    void Lazy(ll k,ll l,ll r)
    {
        if(!lazy[k]) return;
        ll mid=(l+r)/2;
        modify(k*2,l,mid,lazy[k]);modify(k*2+1,mid+1,r,lazy[k]);
        lazy[k]=0;
    }
    void build(ll k,ll l,ll r)
    {
        lazy[k]=0;
        if(l==r) {sum[k]=a[tpos[l]]; return;}
        ll mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void update(ll k,ll l,ll r,ll x,ll y,ll v)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y) {modify(k,l,r,v); return;}
        ll mid=(l+r)/2;
        Lazy(k,l,r);
        update(k*2,l,mid,x,y,v);update(k*2+1,mid+1,r,x,y,v);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(x>r||l>y) return 0;
        if(l>=x&&r<=y) return sum[k];
        ll mid=(l+r)/2;
        Lazy(k,l,r);
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}tree;
void dfs1(ll v,ll p,ll d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        dfs1(to,v,d+1);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
}
void dfs2(ll v,ll p,ll num)
{
    top[v]=num;
    st[v]=++tot;
    tpos[tot]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
    ed[v]=tot;
}
void init()
{
    tot=0;dfs1(1,1,1);
    dfs2(1,0,1);
    tree.build(1,1,n);
}
void update1(ll x,ll v)
{
    tree.update(1,1,n,st[x],st[x],v);
}
void update2(ll x,ll v)
{
    tree.update(1,1,n,st[x],ed[x],v);
}
ll query(ll x)
{
    ll ans=0;
    while(top[x]!=1)
    {
        ans+=tree.query(1,1,n,st[top[x]],st[x]);
        x=pa[top[x]];
    }
    ans+=tree.query(1,1,n,1,st[x]);
    return ans;
}
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    init();
    ll op,x,v;
    for(ll i=0;i<q;i++)
    {
        scanf("%lld",&op);
        if(op==1)
        {
            scanf("%lld%lld",&x,&v);
            update1(x,v);
        }
        else if(op==2)
        {
            scanf("%lld%lld",&x,&v);
            update2(x,v);
        }
        else
        {
            scanf("%lld",&x);
            printf("%lld\n",query(x));
        }
    }
    return 0;
}

