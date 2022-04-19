#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int dp[MAXN][MAXN*MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
			for(int x=1;x<=m;x++)
				if(j+x<=k) add(dp[i+1][j+x],dp[i][j]);
	int ans=0;
	for(int i=0;i<=k;i++) add(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}