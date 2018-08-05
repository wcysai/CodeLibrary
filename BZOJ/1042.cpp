/*************************************************************************
    > File Name: 1042.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-03 18:34:46
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
ll c[5],tot,d[5],s;
ll dp[5][MAXN];
int main()
{
    scanf("%lld%lld%lld%lld%lld",&c[1],&c[2],&c[3],&c[4],&tot);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(ll i=1;i<=4;i++)
    {
        dp[i][0]=1;
        for(ll j=0;j<=100000;j++)
        {
            if(j<c[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i][j-c[i]]+dp[i-1][j];
        }
    }
    while(tot--)
    {
        scanf("%lld%lld%lld%lld%lld",&d[1],&d[2],&d[3],&d[4],&s);
        ll ans=0;
        for(ll i=0;i<16;i++)
        {
            ll t=s,cnt=0;
            for(ll j=0;j<4;j++)
            {
                if((i>>j)&1)
                {
                    t-=c[j+1]*(d[j+1]+1);
                    cnt++;
                }
            }
            if(t<0) continue; ans=ans+pow(-1,cnt)*dp[4][t];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

