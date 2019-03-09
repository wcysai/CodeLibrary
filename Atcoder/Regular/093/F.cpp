#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 17
#define MAXM (1<<17)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
int dp[MAXN][MAXM];
int fact[MAXM],invf[MAXM];
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
    for(int i=1;i<MAXM;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[MAXM-1]=pow_mod(fact[MAXM-1],MOD-2);
    for(int i=MAXM-2;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    dp[m][0]=1;
    for(int i=m;i>0;i--)
    {
        for(int mask=0;mask<(1<<n);mask++)
        {
            if(!dp[i][mask]) continue;
            add(dp[i-1][mask],dp[i][mask]);
            int cnt=0;
            for(int j=0;j<n;j++) if(mask&(1<<j)) cnt+=(1<<j);
            for(int j=0;j<n;j++)
            {
                if(mask&(1<<j)) continue;
                int newmask=mask|(1<<j);
                add(dp[i-1][newmask],1LL*dp[i][mask]*comb((1<<n)-a[i-1]-cnt,(1<<j)-1)%MOD*fact[(1<<j)]%MOD);
            }
        }
    }
    for(int mask=0;mask<(1<<n);mask++)
    {
        int cnt=0;
        for(int j=0;j<n;j++) if(mask&(1<<j)) cnt+=(1<<j);
        dp[0][mask]=1LL*dp[0][mask]*fact[(1<<n)-1-cnt]%MOD;
    }
    int ans=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        if(__builtin_popcount(mask)&1) dec(ans,dp[0][mask]); else add(ans,dp[0][mask]);
    }
    ans=1LL*ans*pow_mod(2,n)%MOD;
    printf("%d\n",ans);
    return 0;
}

