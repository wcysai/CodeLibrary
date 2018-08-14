#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 250
#define INF 1000000000
using namespace std;
int n;
int dp[MAXN][MAXN];
int mat[MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&mat[i]);
    }
    for(int i=0;i<n;i++)
    {
        dp[i][i]=0;
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j=i+len-1;
            dp[i][j]=INF;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+mat[i]*mat[k+1]*mat[j+1]);
            }
        }
    }
    printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
