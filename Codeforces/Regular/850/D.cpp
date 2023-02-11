#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int fact[MAXN],invf[MAXN];
int dp[MAXN][22];
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
    if((n<0)||(n<k)) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=(1<<20);i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[(1<<20)]=pow_mod(fact[(1<<20)],MOD-2);
    for(int i=(1<<20)-1;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    dp[0][0]=1;
    int res=(1<<n);
    for(int i=1;i<=n-1;i++) res=1LL*res*fact[(1<<i)]%MOD;
    for(int i=1;i<=(1<<n);i++){
        for(int j=0;j<=n+1;j++){
            if(j<=n) dp[i][j]=dp[i-1][j];
            if(j) add(dp[i][j],1LL*dp[i-1][j-1]*(j>=n+1?1:comb((1<<n)-(1<<(n-j))-i,(1<<(n-j))-1))%MOD);
        }
        printf("%lld\n",1LL*res*dp[i][n+1]%MOD);
    }
    return 0;
}

