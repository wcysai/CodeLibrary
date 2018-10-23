/*************************************************************************
    > File Name: Telegraph.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-20 10:07:09
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 800
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
#define next daijosakd
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN],sum[MAXN];
ll dp[2][MAXN][MAXN];// dp[i][j][k]: i leaf nodes, j last,k penultimate
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n==1) {printf("%lld\n",a[1]); return 0;}
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) a[i]+=a[i-1];
    for(ll i=0;i<=n;i++) for(ll j=0;j<=n;j++) dp[0][i][j]=INF;
    dp[0][1][0]=0;
    for(ll i=0;i<=n-1;i++)
    {
        ll now=i&1,next=now^1;
        for(ll j=0;j<=n-i-1;j++)
            for(ll k=0;k<=n-i-j-1;k++)
                dp[next][j][k]=INF;
        for(ll j=0;j<=n-i;j++)
            for(ll k=0;k<=n-i-j;k++)
                if(dp[now][j][k]!=INF)
                {
                    if(j) dp[next][j-1][k]=min(dp[next][j-1][k],dp[now][j][k]);
                    if(j+k) dp[now][j+k][j]=min(dp[now][j+k][j],dp[now][j][k]+a[n-i]);
                }
    }
    printf("%lld\n",dp[n&1][0][0]);
    return 0;
}

