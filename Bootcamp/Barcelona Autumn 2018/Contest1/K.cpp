/*************************************************************************
    > File Name: K.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 23:39:32
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
ll bit[MAXN+1],a[MAXN],pos[MAXN],n,k;
vector<ll> ans;
ll sum(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
struct segtree
{
    ll val[4*MAXN],left[4*MAXN];
    void pushup(ll k)
    {
        val[k]=min(val[k*2],val[k*2+1]);
        left[k]=left[k*2]+left[k*2+1];
    }
    void build(ll k,ll l,ll r)
    {
        if(l==r) {left[k]=1; val[k]=a[l]; return;}
        ll mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(ll k,ll l,ll r,ll p)
    {
        if(l==r) {left[k]=0; val[k]=INF; return;}
        ll mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p); else update(k*2+1,mid+1,r,p);
        pushup(k);
    }
    ll find(ll k,ll l,ll r,ll s)
    {
        if(l==r) return l;
        ll mid=(l+r)/2;
        if(left[k*2]>=s) return find(k*2,l,mid,s); else return find(k*2+1,mid+1,r,s-left[k*2]);
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return val[k];
        ll mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
    ll query2(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return left[k];
        ll mid=(l+r)/2;
        return query2(k*2,l,mid,x,y)+query2(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++) {scanf("%lld",&a[i]); pos[a[i]]=i;}
    ll inv=0;
    for(ll i=1;i<=n;i++) 
    {
        inv+=(i-1)-sum(a[i]);
        add(a[i],1);
    }
    if(inv<=k)
    {
        for(ll i=1;i<=n;i++) printf("%lld\n",a[i]);
        return 0;
    }
    ll need=inv-k;
    seg.build(1,1,n);
    for(ll i=1;i<=n;i++)
    {
        if(need<=0) break;
        ll p=seg.find(1,1,n,need+1);
        ll q=seg.query(1,1,n,1,p);
        ans.push_back(q);need-=seg.query2(1,1,n,1,pos[q])-1;seg.update(1,1,n,pos[q]);a[pos[q]]=INF;
    }
    for(ll i=0;i<(int)ans.size();i++) printf("%lld\n",ans[i]);
    for(ll i=1;i<=n;i++) if(a[i]!=INF) printf("%lld\n",a[i]);
    return 0;
}

