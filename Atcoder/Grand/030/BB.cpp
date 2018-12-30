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
ll L,n,a[MAXN],ans;
ll dp[MAXN];
ll go(ll x,ll y,bool dir)
{
    ll ret;
    if(dir) ret=y-x; else ret=x-y;
    if(ret<0) ret+=L;
    return ret;
}
ll findans(ll step)
{
    if(step==n) return go(0,a[n],true);
    else if(step==n-1) return go(0,a[n-1],true)+go(a[n-1],a[n],false);
    if(dp[step]!=-1) return dp[step];
    ll st=step,ed=(n-step)/2;
    return dp[step]=findans(step+2)+2*go(0,a[st],true)+2*go(a[n-ed+1],0,true)+((n-step)&1?1:-1)*(a[n-ed+1]-a[n-ed])-2*go(a[st+1],a[n-ed],true);
}
int main()
{
    scanf("%lld%lld",&L,&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    memset(dp,-1,sizeof(dp));
    ll ans=0;
    for(ll i=1;i<=n;i++) ans=max(ans,findans(i));
    reverse(a+1,a+n+1);
    for(ll i=1;i<=n;i++) a[i]=L-a[i];
    memset(dp,-1,sizeof(dp));
    for(ll i=1;i<=n;i++) ans=max(ans,findans(i));
    printf("%lld\n",ans);
    return 0;
}

