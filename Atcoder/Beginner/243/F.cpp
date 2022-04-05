#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,w[MAXN];
int p[MAXN][MAXN],fact[MAXN],invf[MAXN];
int dp[MAXN][MAXN],ndp[MAXN][MAXN];
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
int main()
{
	fact[0]=invf[0]=1;
	for(int i=1;i<=50;i++) fact[i]=1LL*fact[i-1]*i%MOD;
	invf[50]=pow_mod(fact[50],MOD-2);
	for(int i=49;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
	scanf("%d%d%d",&n,&m,&k);
	int s=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&w[i]);
		s+=w[i];
	}
	s=pow_mod(s,MOD-2);
	for(int i=1;i<=n;i++) w[i]=1LL*w[i]*s%MOD;
	for(int i=1;i<=n;i++)
	{
		p[i][0]=1;
		for(int j=1;j<=50;j++) p[i][j]=1LL*p[i][j-1]*w[i]%MOD;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j=0;j<=i;j++)
			for(int num=0;num<=k;num++)
			{
				if(!dp[j][num]) continue;
				add(ndp[j][num],dp[j][num]);
				for(int nxt=1;num+nxt<=k;nxt++) 
					add(ndp[j+1][num+nxt],1LL*dp[j][num]*p[i][nxt]%MOD*invf[nxt]%MOD);
			}
		swap(dp,ndp);
	}
	int ans=1LL*fact[k]*dp[m][k]%MOD;
	printf("%d\n",ans);
	return 0;
}