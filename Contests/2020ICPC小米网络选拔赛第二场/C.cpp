#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll a[MAXN],b[MAXN],sum[MAXN];
ll bit[MAXN+1];
int n,m;
ll get_sum(int i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
//max (a[i]+sum[n]-sum[i-1])
struct segtree//a[i]-sum[i]
{
    ll val[4*MAXN];
    ll lazy[4*MAXN];
    void pushup(int k)
    {
        val[k]=max(val[k*2],val[k*2+1]);
    }
    void add(int k,ll v)
    {
        val[k]+=v;
        lazy[k]+=v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            val[k]=a[l]-sum[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,ll v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return val[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) bit[i]=0;
        for(int i=1;i<=n;i++) {scanf("%lld",&b[i]); add(i,b[i]);}
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
        seg.build(1,1,n);
        for(int i=0;i<m;i++)
        {
            int type,x;
            ll y;
            scanf("%d%d",&type,&x);
            if(type==1)
            {
                scanf("%lld",&y);
                ll delta=y-a[x];
                a[x]=y;
                seg.update(1,1,n,x,x,delta);
            }
            else if(type==2)
            {
                scanf("%lld",&y);
                ll delta=y-b[x];
                add(x,delta);
                b[x]=y;
                seg.update(1,1,n,x,n,-delta);
            }
            else
            {
                printf("%lld\n",get_sum(x)+max(0LL,seg.query(1,1,n,1,x)));
            }
        }
    }
    return 0;
}