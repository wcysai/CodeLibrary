#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN],l[MAXN],r[MAXN],dp[MAXN];
vector<P> eve[MAXN];
struct SegTree
{
    ll lazy[4*MAXN],maxi[4*MAXN];
    void pushup(ll k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(ll k)
    { 
        if(!lazy[k]) return;
        maxi[k*2]+=lazy[k];lazy[k*2]+=lazy[k];
        maxi[k*2+1]+=lazy[k];lazy[k*2+1]+=lazy[k];
        lazy[k]=0;
    }
    void update(ll k,ll l,ll r,ll x,ll y,ll p)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y)
        {
            lazy[k]+=p;maxi[k]+=p;
            return;
        }
        ll mid=(l+r)/2;
        update(k*2,l,mid,x,y,p);update(k*2+1,mid+1,r,x,y,p);
        pushup(k);
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(x>r||l>y) return -INF;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        ll mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++) 
    {
        scanf("%lld%lld%lld",&l[i],&r[i],&a[i]);
        eve[l[i]].push_back(P(l[i]-1,a[i]));
        eve[r[i]+1].push_back(P(l[i]-1,-a[i]));
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        for(auto v:eve[i]) seg.update(1,0,n,0,v.F,v.S);
        dp[i]=seg.query(1,0,n,0,i-1);
        seg.update(1,0,n,i,i,dp[i]);
        ans=max(ans,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}

