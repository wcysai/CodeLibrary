/*************************************************************************
    > File Name: 618.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-21 15:56:27
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXP 5005
#define INF 1000000000
#define MOD 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll fib[30];
ll dp[MAXN],prime[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=true;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[++p]=i;
        for(ll j=1;j<=p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    fib[1]=fib[2]=1;
    for(ll i=3;i<=24;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        printf("%lld %lld\n",i,fib[i]);
    }
    ll p=sieve(fib[24]);
    printf("%lld\n",p);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(ll j=1;j<=p;j++)
    {
        for(ll i=0;i+prime[j]<=fib[24];i++)
            (dp[prime[j]+i]+=prime[j]*dp[i])%=MOD;
        printf("%lld\n",j);
    }
    ll sum=0;
    for(ll i=2;i<=24;i++)
    {
        printf("%lld %lld\n",i,dp[fib[i]]);
        sum=(sum+dp[fib[i]])%MOD;
    }
    printf("%lld\n",sum);
    return 0;
}

