#include<bits/stdc++.h>
#define MAXN 30005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN];
ll s;
struct segtree
{
    ll sum[4*MAXN];
    ll lazy[4*MAXN];
    void pushup(ll k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushdown(ll k,ll l,ll r)
    {
        if(lazy[k]==INF) return;
        ll mid=(l+r)/2;
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        sum[k*2]=1LL*(mid-l+1)*lazy[k];
        sum[k*2+1]=1LL*(r-mid)*lazy[k];
        lazy[k]=INF;
    }
    void build(ll k,ll l,ll r)
    {
        lazy[k]=INF;
        if(l==r)
        {
            sum[k]=a[l];
            return;
        }
        ll mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(ll k,ll l,ll r,ll x,ll y,ll v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            sum[k]=1LL*(r-l+1)*v;
            lazy[k]=v;
            return;
        }
        pushdown(k,l,r);
        ll mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k,l,r);
        ll mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    freopen("death.in","r",stdin);
    freopen("death.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    seg.build(1,1,n);
    s=seg.query(1,1,n,1,n);
    for(ll i=0;i<m;i++)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        ll sum=seg.query(1,1,n,l,r);
        ll ss=seg.query(1,1,n,1,n);
        ll len=r-l+1,v;
        if(sum<0) v=(ss<=s?(sum/len):(sum-len+1)/len);
        else v=(ss<=s?(sum+len-1)/len:sum/len);
        seg.update(1,1,n,l,r,v);
    }
    for(ll i=1;i<=n;i++) printf("%lld ",seg.query(1,1,n,i,i));
    return 0;
}
