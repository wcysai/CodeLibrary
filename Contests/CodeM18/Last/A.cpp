/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-07 18:59:25
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
ll n,k,a[MAXN];
double b[MAXN];
ll dp[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
        b[i]=(double)log(a[i])/i;
    dp[1]=1;
    for(ll i=2;i<=n;i++)
    {
        dp[i]=1;
        for(ll j=1;j<i;j++)
            if(b[j]<b[i]) dp[i]=(dp[i]+dp[j])%MOD;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++) ans=(ans+dp[i])%MOD;
    printf("%lld\n",ans);
    return 0;
}

