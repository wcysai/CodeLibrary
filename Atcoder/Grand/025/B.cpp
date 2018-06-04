/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-03 20:07:31
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 350005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a,b;
ll k;
ll fact[MAXN],invf[MAXN];
ll pow_mod(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
ll comb(ll n,ll k)
{
    return (1LL*fact[n]*invf[k]%MOD)*invf[n-k]%MOD;
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
    fact[0]=invf[0]=1;
    for(ll i=1;i<=n;i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    invf[n]=pow_mod(fact[n],MOD-2);
    for(ll i=n-1;i>=1;i--)
        invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    ll ans=0;
    for(ll i=0;i<=n;i++)
    {
        if(i*a>k) continue;
        if((k-1LL*i*a)%b!=0) continue;
        ll numa=i,numb=(k-1LL*i*a)/b;
        if(max(numa,numb)>n) continue;
        ans=(ans+1LL*comb(n,numa)*comb(n,numb))%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}

