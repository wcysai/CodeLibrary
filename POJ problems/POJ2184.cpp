#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 105
#define INF 200000
using namespace std;
int main()
{
    int n,d;
    int s[MAXN],f[MAXN],dp[INF+10];
    fill(dp,dp+INF+10,-INF);
    dp[100000]=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&s[i],&f[i]);
    for(int i=0;i<n;i++)
    {
        if(s[i]>=0)
            for(int j=INF;j>=s[i];j--)
              dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
        else
          for(int j=0;j<=INF+s[i];j++)
            dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
    }
    d=-INF;
    for(int i=INF/2;i<=INF;i++)
        if(dp[i]>=0)
          d=max(d,dp[i]+i-INF/2);
    printf("%d",d);
    return 0;
}