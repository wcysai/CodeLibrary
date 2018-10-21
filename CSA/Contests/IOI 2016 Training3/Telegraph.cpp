/*************************************************************************
    > File Name: Telegraph.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-20 10:07:09
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 800
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN],sum[MAXN];
ll dp[MAXN][MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n==2) {printf("%lld\n",a[1]); return 0;}
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(ll i=1;i<=n-1;i++) dp[i][i+1]=2*a[i]+a[i+1];
    for(ll d=3;d<=n;d++)
    {
        for(ll i=1;i+d-1<=n;i++)
        {
            ll j=i+d-1;
            dp[i][j]=INF;
            for(ll k=i;k<j;k++)
            {
                if(2*(sum[k]-sum[i-1])+sum[j]-sum[k]+dp[i][k]+dp[k+1][j]<dp[i][j])
                {
                    dp[i][j]=2*(sum[k]-sum[i-1])+sum[j]-sum[k]+dp[i][k]+dp[k+1][j];
                }
            }
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}

