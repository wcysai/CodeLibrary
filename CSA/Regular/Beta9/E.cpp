/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-12 23:53:00
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
typedef pair<ll,ll> P;
ll n,k,a[MAXN];
P dp[2][MAXN];
int main()
{
    scanf("%lld%lld",&n,&k);
    dp[0][0]=P(1,0);
    for(ll i=1;i<=k;i++)
    {
        ll cur=i&1,last=1-cur;
        for(ll j=0;j<=n;j++)
        {
            if(j>=i)
            {
                dp[cur][j].F=(dp[last][j].F+dp[cur][j-i].F)%MOD;
                dp[cur][j].S=(dp[last][j].S+dp[cur][j-i].S+2LL*dp[cur][j-i].F*(j-i)+1LL*dp[cur][j-i].F*i)%MOD;
            }
            else dp[cur][j]=dp[last][j];
        }
    }
    printf("%lld\n",(dp[k&1][n].S-dp[(k-1)&1][n].S+MOD)%MOD);
    return 0;
}

