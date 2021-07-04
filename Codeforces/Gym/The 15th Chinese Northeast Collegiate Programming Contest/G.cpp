#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k;
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
int f[MAXN][MAXN],g[MAXN][MAXN];
//f[i][j]: number of sequences with length i and sum j
//g[i][j]: number of sequences with length i and sum i+j, with maximum prefix sum j
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
    f[0][0]=1;
    for(int i=0;i<=500;i++)
        for(int j=0;j<=i;j++)
        {
            if(!f[i][j]) continue;
            for(int l=0;j+l<=i+1;l++) add(f[i+1][j+l],1LL*f[i][j]*invf[l]%MOD); 
        }
    for(int i=0;i<=500;i++)
        for(int j=0;j<=i;j++)
            f[i][j]=1LL*f[i][j]*fact[j]%MOD;
	g[0][0]=1;
	for(int i=1;i<=500;i++)
		for(int j=0;j<=500;j++) 
        {
			if(j) g[i][j]=1LL*g[i][j-1]*i%MOD;
			for(int k=1;k<=i;k++) 
			    add(g[i][j],1LL*g[k-1][j]*g[i-k][0]%MOD*comb(i+j-1,k+j-1)%MOD*(i-k+1)%MOD);
		}
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(k==0) {printf("%d\n",f[n][m]); continue;}
        else if(n+k==m) {printf("%d\n",g[n][k]); continue;}
        int ans=0;
        for(int i=1;i<=n-1;i++)//[1,i] with maximum sum i+k, [i+1,n] with no additional prefix
            add(ans,1LL*g[i][k]*f[n-i-1][m-(i+k)]%MOD*comb(m,i+k)%MOD);
        printf("%d\n",ans);
    }
    return 0;
}