/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-14 21:28:52
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
int n,k,dp[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    dp[1]=dp[2]=k;
    for(int i=3;i<=n;i++)
    {
        if(i&1) dp[i]=(1LL*k*dp[i-1]-dp[(i+1)/2]+MOD)%MOD;
        else dp[i]=dp[i-1];
    }
    printf("%d\n",dp[n]);
    return 0;
}

