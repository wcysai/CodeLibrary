#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[360][360],dp[360][360];
int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=i;j++)
        scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        dp[n][i]=a[n][i];
    }
    for(int i=n-1;i>=1;i--)
      for(int j=1;j<=i;j++)
        dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
    printf("%d",dp[1][1]);
    return 0;
}