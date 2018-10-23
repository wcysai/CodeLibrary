/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-23 06:49:53
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
int n,k,f[MAXN],dp[MAXN],fact[MAXN],invf[MAXN];
int p2[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*(i+1)*invf[i+1]%MOD;
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++) p2[i]=pow_mod(2,i*(i-1)/2);
    for(int i=1;i<=n;i++)
    {
        f[i]=p2[i];
        for(int j=1;j<=i-1;j++)
        {
            f[i]-=1LL*f[j]*comb(i,j)%MOD*p2[i-j]%MOD;
            if(f[i]<0) f[i]+=MOD; 
        }
        //printf("%d %d\n",i,f[i]);
    }
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(i,k-1);j++)
        {
            dp[i]+=1LL*comb(i,j)*f[j]%MOD*dp[i-j]%MOD;
            if(dp[i]>=MOD) dp[i]-=MOD;
        }
        for(int j=k;j<=i;j++)
        {
            dp[i]+=1LL*comb(i,j)*f[j]%MOD*p2[i-j]%MOD;
            if(dp[i]>=MOD) dp[i]-=MOD;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}

