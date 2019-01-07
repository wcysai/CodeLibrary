#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,h[MAXN],a[MAXN];
struct SegTree
{
    ll ans[4*MAXN];
    void pushup(ll k)
    {
        ans[k]=max(ans[k*2],ans[k*2+1]);
    }
    void update(ll k,ll l,ll r,ll p,ll v)
    {
        if(l==r) {ans[k]=v; return;}
        ll mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v); else update(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return ans[k];
        ll mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
vector<int> v;
ll dp[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&h[i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) v.push_back(h[i]);
    sort(v.begin(),v.end());
    for(ll i=1;i<=n;i++) h[i]=lower_bound(v.begin(),v.end(),h[i])-v.begin()+1;
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        dp[i]=seg.query(1,1,n,1,h[i])+a[i];
        ans=max(ans,dp[i]);
        seg.update(1,1,n,h[i],dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}

