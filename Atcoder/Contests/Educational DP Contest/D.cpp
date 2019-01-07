#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXW 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,W,w[MAXN],v[MAXN];
ll dp[MAXN][MAXW];
int main()
{
    scanf("%lld%lld",&n,&W);
    for(ll i=1;i<=n;i++) scanf("%lld%lld",&w[i],&v[i]);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=W;j++)
        {
            if(j<w[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    ll ans=0;
    for(ll i=0;i<=W;i++) ans=max(ans,dp[n][i]);
    printf("%lld\n",ans);
    return 0;
}

