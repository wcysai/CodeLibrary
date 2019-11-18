#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 4005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int offset=2000;
int n,a[MAXN],b[MAXN],fact[2*MAXM],invf[2*MAXM];
int dp[MAXM][MAXM],coef[MAXM][MAXM];
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
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=8000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[8000]=pow_mod(fact[8000],MOD-2);
    for(int i=7999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        add(dp[offset-a[i]][offset-b[i]],1);
        add(coef[offset+a[i]][offset+b[i]],1);
    }
    int ans=0;
    for(int i=0;i<=4000;i++)
        for(int j=0;j<=4000;j++)
        {
            add(ans,1LL*coef[i][j]*dp[i][j]%MOD);
            add(dp[i+1][j],dp[i][j]);
            add(dp[i][j+1],dp[i][j]);
        }
    for(int i=1;i<=n;i++) dec(ans,comb(2*a[i]+2*b[i],2*a[i]));
    ans=1LL*ans*INV%MOD;
    printf("%d\n",ans);
    return 0;
}
