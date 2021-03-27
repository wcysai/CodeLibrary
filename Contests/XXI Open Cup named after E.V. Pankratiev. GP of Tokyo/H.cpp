#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int n,m,fact[MAXN],invf[MAXN],a[MAXN],b[MAXN];
int dp[2][MAXN],ndp[2][MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=10000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[10000]=pow_mod(fact[10000],MOD-2);
    for(int i=9999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    int ans=n+m;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        memset(ndp,0,sizeof(ndp));
        for(int k=0;k<2;k++)
            for(int j=10000;j>=0;j--)
            {
                ndp[k][j]=dp[k][j];
                if(j>=a[i]) add(ndp[k][j],dp[k^1][j-a[i]]);
            }
        swap(dp,ndp);
    }
    for(int k=1;k<=m;k++)
        for(int i=0;i<2;i++)
            for(int j=0;j<=10000;j++)
                if(dp[i][j])
                {
                    if(i&1) add(ans,1LL*dp[i][j]*b[k]%MOD*pow_mod(b[k]+j,MOD-2)%MOD);
                    else dec(ans,1LL*dp[i][j]*b[k]%MOD*pow_mod(b[k]+j,MOD-2)%MOD);
                }
    printf("%d\n",ans);
    return 0;
    
}