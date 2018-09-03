/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 13:17:01
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 6005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,K;
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
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
ll calc(ll v,ll n,ll k)
{
    ll ans=0;
    ll lim=max(0LL,v/2-max(0LL,v-1-k));
    for(ll i=0;i<=lim;i++)
        ans=(1LL*pow_mod(2,i)*comb(lim,i)%MOD*comb(k-lim*2+n-1,k-lim*2+i-1)+ans)%MOD;
    return ans;
}
int main()
{
    fact[0]=invf[0]=1;
    for(ll i=1;i<=6000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[6000]=pow_mod(fact[6000],MOD-2);
    for(ll i=5999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%lld%lld",&K,&N);
    for(ll i=2;i<=2*K;i++)
    {
        if(i&1) printf("%lld\n",calc(i,N,K));
        else printf("%lld\n",(calc(i-1,N,K-1)+calc(i-1,N-1,K-1))%MOD);
    }
    return 0;
}

