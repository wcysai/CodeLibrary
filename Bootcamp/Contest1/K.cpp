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
ll bit[MAXN+1],a[MAXN],pos[MAXN],b[MAXN],n,k;
vector<ll> v,ans;
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
    int val[4*MAXN],left[4*MAXN];
    void pushup(int k)
    {
        val[k]=min(val[k*2],val[k*2+1]);
        left[k]=left[k*2]+left[k*2+1];
    }
    void build(int k,int l,int r)
    {
        if(l==r) {left[k]=1; val[k]=v[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int p)
    {
        if(l==r) {left[k]=0; val[k]=INF; return;}
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p); else update(k*2+1,mid+1,r,p);
        pushup(k);
    }
    int find(int k,int l,int r,int s)
    {
        if(l==r) return l;
        int mid=(l+r)/2;
        if(left[k*2]>=s) return find(k*2,l,mid,s); else return find(k*2+1,mid+1,r,s-left[k*2]);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return val[k];
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
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
    ll need=inv-k,cnt=0;
    for(ll i=1;i<=n;i++)
    {
        ll use=sum(pos[i]-1);
        if(use>need) break; 
        else
        {
            need-=use;
            cnt++;
            add(pos[i],-1);
        }
    }
    assert(need<=n);
    v.push_back(0);
    for(ll i=1;i<=n;i++) if(a[i]>cnt) v.push_back(a[i]);
    for(ll i=1;i<=n;i++) pos[a[i]]=i;
    n=n-cnt;
    seg.build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        if(need<=0) break;
        int p=seg.find(1,1,n,need+1);
        int q=seg.query(1,1,n,1,p);
        ans.push_back(q);need-=pos[q]-i;seg.update(1,1,n,pos[q]);v[pos[q]]=INF;
    }
    for(ll i=1;i<=cnt;i++) printf("%lld\n",i);
    for(ll i=0;i<(int)ans.size();i++) printf("%lld\n",ans[i]);
    for(ll i=1;i<=n;i++) if(v[i]!=INF) printf("%lld\n",v[i]);
    return 0;
}

