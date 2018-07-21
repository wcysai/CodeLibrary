/*************************************************************************
    > File Name: test.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-19 16:20:29
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
int n,k,a[MAXN];
int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};
int dp[MAXN];
int main()
{
    dp[0]=dp[1]=1;
    for(int i=2;i<=6;i++)
    {
        for(int j=1;j<=i;j++)
            dp[i]+=dp[i-j]*fact[j];
        printf("%d\n",dp[i]);
    }
    return 0;
}

