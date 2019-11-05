#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 755
#define MAXK 105
#define MAXM 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],cnt[MAXN],fact[MAXM],invf[MAXM];
//dp[i][j][0/1/2]:
//i: current number
//j: number of parts
//the third states represents:
//0: not glued
//1: glued but not final
//2: glued, final decision
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
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        if(!cnt[i+1])
        {
            for(int j=0;j<=n;j++) dp[i+1][j]=dp[i][j];
            continue;
        }
        for(int j=0;j<=n;j++)
        {
            if(!dp[i][j]) continue;
            for(int parts=1;parts<=cnt[i+1];parts++)
            {
                int ways=comb(cnt[i+1]-1,parts-1);
                if((cnt[i+1]-parts)&1) dec(dp[i+1][j+parts],1LL*ways*dp[i][j]%MOD*comb(j+parts,parts)%MOD);
                else add(dp[i+1][j+parts],1LL*ways*dp[i][j]%MOD*comb(j+parts,parts)%MOD);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++) add(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}
