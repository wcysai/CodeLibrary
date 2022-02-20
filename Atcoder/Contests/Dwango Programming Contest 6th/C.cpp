#include<bits/stdc++.h>
#define MAXK 25
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,k,a[MAXK],dp[MAXK][MAXN];
int fact[MAXN],invf[MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000]=pow_mod(fact[1000],MOD-2);
    for(int i=999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    dp[0][0]=1;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(!dp[i][j]) continue;
            for(int choose=0;choose<=min(a[i+1],n-j);choose++)
                add(dp[i+1][j+choose],1LL*dp[i][j]*comb(n-j,choose)%MOD*comb(n-choose,a[i+1]-choose)%MOD);
        }
    }
    printf("%d\n",dp[k][n]);
    return 0;
}