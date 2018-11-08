/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-09 00:28:52
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,cnt[MAXN];
int fact[MAXN],invf[MAXN];
int dp[MAXN][MAXN];
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
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000]=pow_mod(fact[1000],MOD-2);
    for(int i=999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        int x;scanf("%d",&x);cnt[x]++;
    }
    dp[0][0]=1;
    int s=0;
    for(int i=0;i<n;i++)
    {
        if(!cnt[i+1])
        {
            for(int j=0;j<=s;j++) add(dp[i+1][j],dp[i][j]);
            continue;
        }
        for(int j=0;j<=s;j++)
        {
            if(!dp[i][j]) continue;
            for(int k=1;k<=min(s+1,cnt[i+1]);k++)
                for(int l=0;l<=min(j,k);l++)
                    add(dp[i+1][j-l+cnt[i+1]-k],1LL*dp[i][j]*comb(j,l)%MOD*comb(s+1-j,k-l)%MOD*comb(cnt[i+1]-1,k-1)%MOD);
        }
        s+=cnt[i+1];
    }
    printf("%d\n",dp[n][0]);
    return 0;
}

