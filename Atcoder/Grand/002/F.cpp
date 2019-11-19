#include<bits/stdc++.h>
#define MAXN 2005
#define MAXM 4000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,K,fact[MAXM],invf[MAXM];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
int dp[MAXN][MAXN];
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=4000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[4000000]=pow_mod(fact[4000000],MOD-2);
    for(int i=3999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&N,&K);
    if(K==1) {puts("1"); return 0;}
    dp[0][0]=1;
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
        {
            if(i<N) add(dp[i+1][j],dp[i][j]);
            if(j<i) add(dp[i][j+1],1LL*dp[i][j]*comb(N-i+(N-j-1)*(K-1)+K-2,K-2)%MOD);
        }
    printf("%d\n",1LL*dp[N][N]*fact[N]%MOD);
    return 0;
}
