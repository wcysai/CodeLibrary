#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000LL
#define MOD 1000000007
#define ls (k*2)
#define rs (k*2+1)
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll tot,q,n,k,a[MAXN];
ll pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
struct node
{
    ll maxl,maxr,sum,maxs,lazy;
    void init(ll v)
    {
        lazy=-INF;
        maxl=maxr=sum=maxs=v;
    }
    void merge(node a,node b)
    {
        sum=a.sum+b.sum;
        maxl=max(a.maxl,a.sum+b.maxl);
        maxr=max(b.maxr,b.sum+a.maxr);
        maxs=max(max(a.maxs,b.maxs),a.maxr+b.maxl);
    }
    void change(ll l,ll r,ll v)
    {
        lazy=v;sum=(r-l+1)*v;
        if(v>=0)  maxl=maxr=maxs=sum;
        else maxl=maxr=maxs=v;
    }
    void rev()
    {
        swap(maxl,maxr);
    }
};
node nullnode()
{
    node ret;
    ret.lazy=-INF; ret.sum=0; ret.maxl=ret.maxr=ret.maxs=-INF;
    return ret;
}
struct segtree
{
    node seg[4*MAXN];
    void pushup(ll k)
    {
        seg[k].merge(seg[ls],seg[rs]);
    }
    void pushdown(ll k,ll l,ll r)
    {
        if(seg[k].lazy==-INF) return;
        ll v=seg[k].lazy;
        ll mid=(l+r)/2;
        seg[ls].change(l,mid,v); seg[rs].change(mid+1,r,v);
        seg[k].lazy=-INF;
    }
    void build(ll k,ll l,ll r)
    {
        seg[k].lazy=-INF;
        if(l==r)
        {
            seg[k].init(a[tpos[l]]);
            return;
        }
        ll mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }      
    void update(ll k,ll l,ll r,ll x,ll y,ll v)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y)
        {
            seg[k].change(l,r,v);
            return;
        }
        pushdown(k,l,r);
        ll mid=(l+r)/2;
        update(k*2,l,mid,x,y,v);update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    node query(ll k,ll l,ll r,ll x,ll y)
    {
        if(x>r||l>y) return nullnode();
        if(l>=x&&r<=y) return seg[k];
        pushdown(k,l,r);
        ll mid=(l+r)/2;
        node lhs=query(ls,l,mid,x,y); node rhs=query(rs,mid+1,r,x,y);
        node ret; ret.merge(lhs,rhs);
        return ret;
    }
}tree;
vector<int> G[MAXN];
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
    spos[v]=++tot;
    tpos[tot]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void init()
{
    tot=0;
    memset(wson,0,sizeof(wson));//important when multiple test cases!!!
    dfs1(1,0,0);
    dfs2(1,0,1);
    tree.build(1,1,n);
}
void modify(ll u,ll v,ll x)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        tree.update(1,1,n,spos[top[u]],spos[u],x);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    tree.update(1,1,n,spos[v],spos[u],x);
}
ll query(ll u,ll v)
{
    node ret1=nullnode(),ret2=nullnode();
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) 
        {
            swap(u,v);
            swap(ret1,ret2);
        }
        ret1.merge(tree.query(1,1,n,spos[top[u]],spos[u]),ret1);
        //printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",ret1.sum,ret1.maxl,ret1.maxr,ret1.maxs,ret2.sum,ret2.maxl,ret2.maxr,ret2.maxs);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) {swap(u,v); swap(ret1,ret2);}
    ret1.merge(tree.query(1,1,n,spos[v],spos[u]),ret1);
    //printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",ret1.sum,ret1.maxl,ret1.maxr,ret1.maxs,ret2.sum,ret2.maxl,ret2.maxr,ret2.maxs);
    swap(ret1.maxl,ret1.maxr);
    ret1.merge(ret1,ret2);
    return ret1.maxs;
}

char str[10];
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
    while(q--)
    {
        ll t,u,v,x;
        scanf("%lld%lld%lld%lld",&t,&u,&v,&x);
        if(t==1) modify(u,v,x); else printf("%lld\n",query(u,v));
    }
    return 0;
}


