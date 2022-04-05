#include<bits/stdc++.h>
#define MAXN 51
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,b,w;
int dp[MAXN*MAXN][MAXN][MAXN];
int comb[MAXN][MAXN];
int invc[MAXN][MAXN];
int fact[MAXN*MAXN],invf[MAXN*MAXN];
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
int main()
{
	fact[0]=invf[0]=1;
	for(int i=1;i<=2500;i++) fact[i]=1LL*fact[i-1]*i%MOD;
	invf[2500]=pow_mod(fact[2500],MOD-2);
	for(int i=2499;i>=1;i--) invf[i]=1LL*(i+1)*invf[i+1]%MOD;
	scanf("%d%d%d%d",&n,&m,&b,&w);
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<n*m;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=m;k++)
			{
				if(j*k<i) continue;
				if(!dp[i][j][k]) continue;
				add(dp[i+1][j][k],1LL*(j*k-i)*dp[i][j][k]%MOD);
				add(dp[i+1][j+1][k+1],1LL*(n-j)*(m-k)*dp[i][j][k]%MOD);
				add(dp[i+1][j+1][k],1LL*k*(n-j)*dp[i][j][k]%MOD);
				add(dp[i+1][j][k+1],1LL*j*(m-k)*dp[i][j][k]%MOD);
			}
	comb[0][0]=invc[0][0]=1;
	for(int i=1;i<=50;i++)
	{
		comb[i][0]=invc[i][0]=comb[i][i]=invc[i][i]=1;
		for(int j=1;j<i;j++)
		{
			comb[i][j]=comb[i-1][j-1];
			add(comb[i][j],comb[i-1][j]);
			invc[i][j]=pow_mod(comb[i][j],MOD-2);
		}
	}
	int ans=0;
	for(int i=1;i<n;i++)
		for(int j=1;i+j<=n;j++)
			for(int k=1;k<m;k++)
				for(int l=1;k+l<=m;l++)
				{
					int tmp=1LL*dp[b][i][k]*dp[w][j][l]%MOD;
					tmp=1LL*tmp*invf[b]%MOD*invf[w]%MOD;
					add(ans,1LL*tmp*comb[n-i][j]%MOD*comb[m-k][l]%MOD*invc[n][j]%MOD*invc[m][l]%MOD);
				}
	printf("%d\n",ans);
	return 0;
}