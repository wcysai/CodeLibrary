#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int l[MAXN],r[MAXN];
int dp[2][MAXN][MAXN];
int cnt[MAXN][MAXN];
int inv[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
	inv[1] = 1;
	for (int i = 2; i <=400; i++)
		inv[i] = 1LL* (MOD - MOD / i) * inv[ MOD % i] % MOD;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d",&l[i],&r[i]);
		cnt[l[i]][r[i]]++;
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			cnt[i][j]+=(cnt[i+1][j]+cnt[i][j-1]-cnt[i+1][j-1]);
		}
	}
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int par=0;par<2;par++)
		{
			for(int j=0;j<=m;j++)
			{
				if(!dp[par][i][j]) continue;
				for(int k=i+1;k<=n;k++) add(dp[par^1][k][j+cnt[i+1][k-1]],dp[par][i][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int par=0;par<2;par++)
		{
			for(int num=0;num<m;num++)
			{
				if(!dp[par][i][num]) continue;
				int c=num+cnt[i+1][n];
				if(par&1) add(ans,1LL*m*inv[m-c]%MOD*dp[par][i][num]%MOD);
				else dec(ans,1LL*m*inv[m-c]%MOD*dp[par][i][num]%MOD);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}