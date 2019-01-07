#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],dp[MAXN][MAXN],sum[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(ll l=2;l<=n;l++)
    {
        for(ll i=1;i+l-1<=n;i++)
        {
            ll j=i+l-1;
            dp[i][j]=INF;
            for(ll k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}

