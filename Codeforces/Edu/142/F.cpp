#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,dp[MAXN];
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    dp[1]=1; dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=0;
        for(int t=1;t<=i-1;t++){
            if(t==i-1) add(dp[i],1LL*dp[t]*comb(i-1,t-1)%MOD*dp[i-t]%MOD);
            else add(dp[i],2LL*dp[t]*comb(i-1,t-1)%MOD*dp[i-t]%MOD);
        }
    }
    int ans=2LL*dp[n]%MOD;
    dec(ans,2);
    printf("%d\n",ans);
    return 0;
}

