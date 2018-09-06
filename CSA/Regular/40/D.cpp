/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-06 15:48:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],dp[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++) scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));dp[1][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n-i;j++) 
        {
            dp[i][j]+=dp[i][j-1];
            if(dp[i][j]>=MOD) dp[i][j]-=MOD;
        }
        for(int j=0;j<=n-i;j++)
        {
            int rest=n-i-j;
            if(a[i]==0)
            {
                if(j==0) continue;
                dp[i+1][0]+=dp[i][j];
                if(dp[i+1][0]>=MOD) dp[i+1][0]-=MOD;
                dp[i+1][j]-=dp[i][j];
                if(dp[i+1][j]<0) dp[i+1][j]+=MOD;
            }
            else
            {
                if(rest==0) continue;
                dp[i+1][j]+=dp[i][j];
                if(dp[i+1][j]>=MOD) dp[i+1][j]-=MOD;
            }
        }
    }
    printf("%d\n",dp[n][0]);
    return 0;
}

