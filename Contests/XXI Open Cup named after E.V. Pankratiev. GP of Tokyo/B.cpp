#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int dp[MAXN],fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int main()
{
    dp[0]=1;
    for(int i=1;i<=1000000;i++) dp[i]=1LL*(2*i-1)*dp[i-1]%MOD;
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]==1)
            add(ans,1LL*dp[i-1]*dp[n-i]%MOD*comb(n-1,i-1)%MOD);
    printf("%d\n",ans);
    return 0;
}