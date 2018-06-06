/*************************************************************************
    > File Name: 475.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-06 18:35:27
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll dp[MAXN][MAXN][MAXN];
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
    fact[0]=invf[0]=1;
    for(ll i=1;i<=200;i++)
    {
        fact[i]=1LL*fact[i-1]*i%MOD;
        invf[i]=pow_mod(fact[i],MOD-2);
    }
    memset(dp,0,sizeof(dp));
    dp[200][0][0]=1;
    for(ll i=200;i>=0;i--)
        for(ll j=200;j>=0;j--)
            for(ll k=200;k>=0;k--)
            {
                if(!dp[i][j][k]) continue;
                for(ll x=0;x<=4&&x<=i;x++)
                {
                    for(ll y=0;x+y<=4&&y<=j;y++)
                    {
                        ll z=4-x-y;
                        if(z>k) continue;
                        ll res=((((comb(j,y)*comb(k,z)%MOD)*fact[y]%MOD)*fact[z]%MOD)*comb(4,x)%MOD)*comb(4-x,y)%MOD;
                        (dp[i-x][j-y+x][k-z+y]+=dp[i][j][k]*res%MOD)%=MOD;
                    }
                }
            }
    printf("%lld\n",dp[0][0][0]);
    return 0;
}

