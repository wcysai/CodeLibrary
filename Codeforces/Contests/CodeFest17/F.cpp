#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct segtree
{
    int maxi[4*MAXN],secmax[4*MAXN],lazy[4*MAXN],cnt[4*MAXN];
    ll sum[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
        if(maxi[k*2]>maxi[k*2+1])
        {
            maxi[k]=maxi[k*2];
            cnt[k]=cnt[k*2];
            secmax[k]=max(secmax[k*2],maxi[k*2+1]);
        }
        else if(maxi[k*2]<maxi[k*2+1])
        {
            maxi[k]=maxi[k*2+1];
            cnt[k]=cnt[k*2+1];
            secmax[k]=max(secmax[k*2+1],maxi[k*2]);
        }
        else
        {
            maxi[k]=maxi[k*2];
            cnt[k]=cnt[k*2]+cnt[k*2+1];
            secmax[k]=max(secmax[k*2],secmax[k*2+1]);
        }
    }
    void apply_min(int k,int x)
    {
        if(lazy[k]<=x||maxi[k]<=x) return;
        sum[k]-=1LL*cnt[k]*(maxi[k]-x); maxi[k]=x;
        lazy[k]=x;
    }
    void pushdown(int k)
    {
        if(lazy[k]==INF) return;
        apply_min(k*2,lazy[k]); apply_min(k*2+1,lazy[k]);
        lazy[k]=INF;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=INF;
        if(l==r)
        {
            maxi[k]=sum[k]=INF; secmax[k]=0; cnt[k]=1;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r||maxi[k]<=v) return;
        if(l>=x&&r<=y&&secmax[k]<v)
        {
            apply_min(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query_sum(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return (sum[k]-1LL*(maxi[k]==INF?INF:0)*cnt[k]);
        pushdown(k);
        int mid=(l+r)/2;
        return query_sum(k*2,l,mid,x,y)+query_sum(k*2+1,mid+1,r,x,y);
    }
}seg0,seg1;
int n,q;
int main()
{
    n=100000;
    scanf("%d",&q);
    seg0.build(1,1,n); seg1.build(1,1,n);
    ll ans=seg0.query_sum(1,1,n,1,10)+seg1.query_sum(1,1,n,1,10);
    printf("%lld\n",ans);
    for(int i=0;i<q;i++)
    {
        int type,l,r,k;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d%d",&l,&r,&k);
            if(k>0) seg1.update(1,1,n,l,r,k); else seg0.update(1,1,n,l,r,-k);
        }
        else
        {
            scanf("%d%d",&l,&r);
            ll ans=seg0.query_sum(1,1,n,l,r)+seg1.query_sum(1,1,n,l,r);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
