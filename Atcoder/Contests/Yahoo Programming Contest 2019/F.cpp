#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],fact[2*MAXN],invf[2*MAXN];
char str[MAXN+1];
int dp[MAXN][MAXN],cnt1[MAXN],cnt2[MAXN];
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
    fact[0]=invf[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        cnt1[i]=cnt1[i-1];cnt2[i]=cnt2[i-1];
        if(str[i]=='0') cnt1[i]+=2;
        else if(str[i]=='2') cnt2[i]+=2;
        else
        {
            cnt1[i]++;cnt2[i]++;
        }   
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!dp[i][j]) continue;
            if(j<cnt1[i+1]) add(dp[i+1][j+1],dp[i][j]);
            if(i-j<cnt2[i+1]) add(dp[i+1][j],dp[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++) add(ans,1LL*dp[n][i]*comb(n,cnt1[n]-i)%MOD);
    printf("%d\n",ans);
    return 0;
}

