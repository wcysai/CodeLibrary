/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-05 14:27:53
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dp[MAXN][2][2];
char str[MAXN];
int check(int x)
{
    int l=min(dp[x][0][0],dp[x][1][1]);
    int r=min(dp[x][0][1],dp[x][1][0]);
    return min(l,r);
}
int main()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    for(int i=1;i<=n;i++) dp[i][0][0]=dp[i][1][0]=dp[i][0][1]=dp[i][1][1]=INF;
    if(str[1]==str[2]) dp[2][0][0]=INF; else dp[2][0][0]=0;
    dp[2][1][0]=dp[2][0][1]=1; dp[2][1][1]=2;
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<=1;j++)
        {
            for(int k=0;k<=1;k++)
            {
                if(dp[i][j][k]==INF) continue;
                if(str[i+1]==str[i-1]&&j==0) dp[i+1][k][1]=min(dp[i+1][k][1],dp[i][j][k]+1);
                else if(str[i+1]==str[i]&&k==0) dp[i+1][k][1]=min(dp[i+1][k][1],dp[i][j][k]+1);
                else
                {
                    dp[i+1][k][0]=min(dp[i+1][k][0],dp[i][j][k]);
                    dp[i+1][k][1]=min(dp[i+1][k][1],dp[i][j][k]+1);
                }
            }
        }
    }
    printf("%d\n",check(n));
    return 0;
}

