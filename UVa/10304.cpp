#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
using namespace std;
typedef long long ll;
ll a[MAXN],sum[MAXN];
ll n;
ll dp[MAXN][MAXN],knuth[MAXN][MAXN];
int main()
{
    while(scanf("%lld",&n)==1)
    {
        for(ll i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sum[0]=0;
        for(ll i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dp[i][j]=INF;
        for(ll i=1;i<=n;i++)
        {
            dp[i][i]=0;
            knuth[i][i]=i;
        }
        for(ll l=2;l<=n;l++)
            for(ll i=1;i<=n-l+1;i++)
            {
                ll j=i+l-1;
                for(ll k=knuth[i][j-1];k<=knuth[i+1][j];k++)
                {
                    ll lb=k-1<i?0:dp[i][k-1]+sum[k-1]-sum[i-1];
                    ll rb=k+1>j?0:dp[k+1][j]+sum[j]-sum[k];
                    if(lb+rb<dp[i][j])
                    {
                        dp[i][j]=lb+rb;
                        knuth[i][j]=k;
                    }
                }
            }
        printf("%lld\n",dp[1][n]);
    }
    return 0;
}


