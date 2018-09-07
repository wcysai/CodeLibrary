/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-06 18:57:09
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k;
ll comb[MAXN][MAXN];
ll dp[MAXN][MAXN];
int main()
{
    scanf("%lld%lld",&n,&k);
    comb[0][0]=1;
    for(ll i=1;i<=2*n;i++)
    {
        comb[i][0]=1;
        for(ll j=1;j<=i;j++)
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    }
    for(ll i=2*n-2;i>=0;i--)
    {
        if(i%2==0) dp[i][0]=dp[i+1][1]+comb[2*n-i-1][(2*n-i)/2];
        for(ll j=1;j<=i;j++)
            dp[i][j]=dp[i+1][j-1]+dp[i+1][j+1];
    }
    ll extra=0,i;
    for(i=1;i<=2*n;i++)
    {
        if(dp[i][extra+1]>=k)
        {
            printf("(");
            extra++;
        }
        else
        {
            k-=dp[i][extra+1];
            printf(")");
            if(extra>0) extra--;
            else break;
        }
    }
    ll open=(2*n-i+1)/2;
    for(i+=1;i<=2*n;i++)
    {
        if(open&&comb[2*n-i][open-1]>=k)
        {
            printf("(");
            open--;
        }
        else
        {
            if(open) k-=comb[2*n-i][open-1];
            printf(")");
        }
    }
    return 0;
}

