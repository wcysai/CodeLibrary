/*************************************************************************
    > File Name: 3683.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-14 11:18:12
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
ll tot,q,n,k,a[MAXN];
ll pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN],qaq[MAXN],st[MAXN],ed[MAXN],b[MAXN];
vector<ll> G[MAXN];
typedef long double db;
struct segtree
{
    ll sum[4*MAXN],lazy[4*MAXN];
    void Lazy(ll k,ll l,ll r)
    {
        lazy[k*2]+=lazy[k];lazy[k*2+1]+=lazy[k];
        ll mid=(l+r)/2;
        sum[k*2]+=lazy[k]*(mid-l+1);sum[k*2+1]+=lazy[k]*(r-mid);
        lazy[k]=0;
    }
    void update(ll k,ll l,ll r,ll x,ll y,ll v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            sum[k]+=(r-l+1)*v;
            lazy[k]+=v;
            return;
        }
        Lazy(k,l,r);
        ll mid=(l+r)/2;
        update(k*2,l,mid,x,y,v);update(k*2+1,mid+1,r,x,y,v);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        Lazy(k,l,r);
        ll mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}tree1,tree2;
void dfs1(ll v,ll p,ll d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;st[v]=++tot;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        dfs1(to,v,d+1);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        qaq[v]+=sz[v]*sz[to];
        sz[v]+=sz[to];
    }
    ed[v]=tot;
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
void update1(ll v,ll x,bool f)
{
    //printf("%lld %lld\n",v,sz[v]);
    if(f) b[v]+=x*(sz[v]-1);
    while(v!=1)
    {
        while(v!=1&&(top[v]==v))
        {
            b[pa[v]]+=x*(sz[pa[v]]-sz[v]);
            v=pa[v];
        }
        v=pa[v];
        tree1.update(1,1,n,spos[top[v]],spos[v],x);
        v=top[v];
    }
}
void update2(ll v,ll x)
{
    tree2.update(1,1,n,st[v],ed[v],2*x);
    update1(v,sz[v]*x,false);
}
db query(ll v)
{
    db ss=tree1.query(1,1,n,spos[v],spos[v])*(sz[v]-sz[wson[v]])+b[v];
    ss=ss/qaq[v];
    return ss+tree2.query(1,1,n,st[v],st[v]);
}
void init()
{
    tot=0;dfs1(1,1,1);
    tot=0;dfs2(1,0,1);
}
char ch[3];
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=2;i<=n;i++)
    {
        ll x;scanf("%lld",&x);
        G[x].push_back(i);G[i].push_back(x);
    }
    init();
    //for(ll i=1;i<=n;i++) printf("%lld %lld\n",i,qaq[i]);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        update1(i,a[i],true);
    }
    ll v,x;
    for(ll i=0;i<q;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='Q')
        {
            scanf("%lld",&v);
            printf("%.10Lf\n",query(v));
        }
        else
        {
            scanf("%lld%lld",&v,&x);
            if(ch[0]=='S') update1(v,x,true); else update2(v,x);
        }
    }
    return 0;
}

