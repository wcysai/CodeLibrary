/*************************************************************************
    > File Name: 3468-segment.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-19 17:46:30
 ************************************************************************/

#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,q,a[MAXN];
struct segtree
{
    ll sum[4*MAXN],lazy[4*MAXN];
    void Lazy(ll k,ll l,ll r)
    {
        if(!lazy[k]) return;
        ll mid=(l+r)/2,v=lazy[k];
        sum[k*2]+=(mid-l+1)*v;sum[k*2+1]+=(r-mid)*v;
        lazy[k*2]+=v;lazy[k*2+1]+=v;
        lazy[k]=0;
    }
    void build(ll k,ll l,ll r)
    {
        lazy[k]=0;
        if(l==r) {sum[k]=a[l]; return;}
        ll mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void update(ll k,ll l,ll r,ll x,ll y,ll v)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y) 
        {
            lazy[k]+=v;sum[k]+=(r-l+1)*v;
            return;
        }
        Lazy(k,l,r);
        ll mid=(l+r)/2;
        update(k*2,l,mid,x,y,v);update(k*2+1,mid+1,r,x,y,v);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(x>r||l>y) return 0;
        if(l>=x&&r<=y) return sum[k];
        Lazy(k,l,r);
        ll mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
char ch[2];
ll l,r,v;
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    seg.build(1,1,n);
    for(ll i=0;i<q;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='Q')
        {
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",seg.query(1,1,n,l,r));
        }
        else
        {
            scanf("%lld%lld%lld",&l,&r,&v);
            seg.update(1,1,n,l,r,v);
        }
    }
    return 0;
}

