/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 19:50:43
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll C,N,M,s[MAXN],p[MAXN];
ll dp[2][MAXN];
int main()
{
    scanf("%lld%lld%lld",&C,&N,&M);
    for(ll i=1;i<=N;i++) scanf("%lld%lld",&s[i],&p[i]);
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<N;i++)
    {
        ll cur=i&1,nxt=1-cur;
        for(ll j=0;j<=C;j++) dp[nxt][j]=0;
        for(ll j=0;j<=C;j++)
        {
            dp[nxt][j]=max(dp[nxt][j],dp[cur][j]);
            if(j+s[i+1]<=C) dp[nxt][j+s[i+1]]=max(dp[nxt][j+s[i+1]],dp[cur][j]+p[i+1]);
        }
    }
    for(ll i=1;i<=M;i++)
        printf("%lld\n",dp[N&1][C/i]*i);
    return 0;
}

