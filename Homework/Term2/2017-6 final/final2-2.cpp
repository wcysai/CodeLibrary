#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAXN 205
#define INF 1000000000
using namespace std;
int a[MAXN],n;
long long dp[MAXN][MAXN],sum[MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sum[0]=0;
    sum[1]=a[0];
    for(int i=2;i<n+1;i++)
        sum[i]=sum[i-1]+a[i-1];
        int s=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=INF;
    }
    for(int i=0;i<n;i++)
        dp[i][i]=0;
    for(int l=1;l<n;l++)
    {
        for(int i=0;i<n-l;i++)
        {
            for(int j=i;j<i+l;j++)
              dp[i][i+l]=min(dp[i][i+l],dp[i][j]+dp[j+1][i+l]+sum[i+l+1]-sum[i]);
        }
    }
    printf("%lld\n",dp[0][n-1]);
    }
    return 0;
}
