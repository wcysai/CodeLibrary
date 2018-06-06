/*************************************************************************
    > File Name: 364.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-06 19:18:10
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll ans=0;
//l+r+2*one+3*two+1=len
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
ll fact[MAXN],invf[MAXN];
ll comb(ll n,ll k)
{
    return (1LL*fact[n]*invf[k]%MOD)*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(ll i=1;i<=1000000;i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(ll i=999999;i>=1;i--)
        invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    ll len=1000000;
    for(ll l=0;l<=1;l++)
        for(ll r=0;r<=1;r++)
        {
            for(ll two=0;l+r+3*two+1<=len;two++)
            {
                if((len-1-3*two-l-r)&1) continue;
                ll one=(len-1-l-r-3*two)/2;
                ll step1=one+two+1;
                ll step2=two+l+r;
                ll step3=len-step1-step2;
                ll x=(((1LL*comb(one+two,two)*fact[step1]%MOD)*fact[step2]%MOD)*pow_mod(2,step2-l-r)%MOD)*fact[step3]%MOD;
                //printf("l:%lld r:%lld one:%lld two:%lld step1:%lld step2:%lld step3:%lld x:%lld\n",l,r,one,two,step1,step2,step3,x);
                ans=(ans+x)%MOD;
            }
        }
    printf("%lld\n",ans);
    return 0;
}

