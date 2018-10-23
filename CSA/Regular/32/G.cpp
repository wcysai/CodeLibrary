/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-23 13:46:07
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4100
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,m,dp[MAXN][MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int solve(int n,int k,int x)
{
    if(n<x||k==0) return 0;
    return (dp[n-x][k-1]+solve(n-x,k-1,x))%MOD;
}
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=min(i,k);j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
            if(dp[i][j]>=MOD) dp[i][j]-=MOD;
        }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=1LL*solve(n,k,i)*pow_mod(i,m)%MOD;
        if(ans>=MOD) ans-=MOD;
    }
    printf("%d\n",ans);
    return 0;
}

