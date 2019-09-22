#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
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
int fact[MAXN],invf[MAXN];
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=400;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[400]=pow_mod(fact[400],MOD-2);
    for(int i=399;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    int asum=0,bsum=0;
    for(int i=0;i<n;i++)
    {
        asum+=a[i]; bsum+=b[i];
        for(int j=asum;j>=a[i];j--)
            for(int k=0;k<=bsum;k++)
            {
                int coef=1;
                for(int l=0;l<=min(k,b[i]-1);l++)
                {
                    dec(dp[j][k],1LL*coef*dp[j-a[i]][k-l]%MOD*invf[l]%MOD);
                    coef=1LL*coef*a[i]%MOD;
                }
            }
    }
    int ans=0;
    for(int i=1;i<=asum;i++)
    {
        int coef=1;
        for(int j=0;j<bsum;j++)
        {
            coef=1LL*coef*i%MOD;
            add(ans,1LL*dp[i][j]*fact[j]%MOD*pow_mod(coef,MOD-2)%MOD);
        }
    }
    ans=(MOD-1LL*ans*asum%MOD)%MOD;
    printf("%d\n",ans);
    return 0;
}
