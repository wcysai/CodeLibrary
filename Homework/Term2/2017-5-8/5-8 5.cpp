#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1000
using namespace std;
int num[MAXN][MAXN],dp[MAXN],n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
          scanf("%d",&num[i][j]);
    for(int i=0;i<n;i++)
        dp[i]=num[n-1][i];
    for(int i=n-1;i>0;i--)
        for(int j=0;j<i;j++)
            dp[j]=min(num[i-1][j]+dp[j],num[i-1][j]+dp[j+1]);
    printf("%d\n",dp[0]);
    return 0;
}
