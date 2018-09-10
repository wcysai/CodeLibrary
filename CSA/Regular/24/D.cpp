/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-10 10:55:03
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define MAXH 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,n;
int dp[MAXN][MAXH],sum[MAXN][MAXH];
int main()
{
    scanf("%d%d",&n,&h);
    memset(dp,0,sizeof(dp));memset(sum,0,sizeof(sum));
    dp[0][0]=1;sum[0][0]=1;
    for(int i=1;i<=h;i++) sum[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=h;j++)
        {
            if(j>i) continue;
            for(int k=0;k<=i-1;k++)
            {
                dp[i][j]+=1LL*dp[k][j-1]*sum[i-1-k][j-2]%MOD;
                if(dp[i][j]>=MOD) dp[i][j]-=MOD;
                dp[i][j]+=1LL*sum[k][j-1]*dp[i-1-k][j-1]%MOD;
                if(dp[i][j]>=MOD) dp[i][j]-=MOD;
            }
        }
        sum[i][0]=dp[i][0];
        for(int j=1;j<=h;j++) 
        {
            sum[i][j]=dp[i][j]+sum[i][j-1];
            if(sum[i][j]>=MOD) sum[i][j]-=MOD;
        }
    }
    printf("%d\n",dp[n][h]);
    return 0;
}

