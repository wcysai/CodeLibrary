#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 924844033
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,fact[MAXN],invf[MAXN];
int dp[MAXN],ndp[MAXN];
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
    for(int i=1;i<=2000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[2000]=pow_mod(fact[2000],MOD-2);
    for(int i=1999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int sum=0;
    for(int i=1;i<=min(n,2*k);i++)
    {
        int len=(n-i)/k+(i>=k+1);
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<=(len+1)/2;j++)
        {
            int coef=(j==0?1:comb(len-j+1,j));
            for(int k=0;k<=sum;k++)
                add(ndp[k+j],1LL*coef*dp[k]%MOD);
        }
        swap(dp,ndp);
        sum+=(len+1)/2;
    }
    int ans=0;
    for(int i=0;i<=n;i++) if(i&1) dec(ans,1LL*dp[i]*fact[n-i]%MOD); else add(ans,1LL*dp[i]*fact[n-i]%MOD);
    printf("%d\n",ans);
    return 0;
}