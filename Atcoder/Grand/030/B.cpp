#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll L,n,a[MAXN];
ll dis(ll x,ll y,bool dir)
{
    ll ans=0;
    if(dir) ans=y-x; else ans=x-y;
    if(ans<0) ans+=L;
    return ans;
}
ll dp[MAXN][MAXN][2];
ll solve(ll l,ll r,ll pos)
{
    if(l>=r) return 0;
    if(dp[l][r][pos]!=-1) return dp[l][r][pos];
    ll ans=0;
    if(pos==1) ans=max(solve(l,r-1,0)+dis(a[r],a[l],true),solve(l,r-1,1)+dis(a[r],a[r-1],false));
    else ans=max(solve(l+1,r,0)+dis(a[l],a[l+1],true),solve(l+1,r,1)+dis(a[l],a[r],false));
    return dp[l][r][pos]=ans;
}
int main()
{
    scanf("%lld%lld",&L,&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]); 
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",max(solve(1,n,0)+dis(0,a[1],true),solve(1,n,1)+dis(0,a[n],false)));
    return 0;
}

