#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
using namespace std;
int mat[MAXN][MAXN],sum[MAXN][MAXN],dp[MAXN][MAXN];
int n=80;
int main()
{
	freopen("p082_matrix.txt", "r", stdin);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mat[i][j]);
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=mat[j][i]+sum[i][j-1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[i][1]=mat[i][1];
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			dp[j][i]=INF;
			for(int k=1;k<=n;k++)
				if(k>=j) dp[j][i]=min(dp[j][i],dp[k][i-1]+sum[i][k]-sum[i][j-1]); else dp[j][i]=min(dp[j][i],dp[k][i-1]+sum[i][j]-sum[i][k-1]);
		}
	int ans=INF;
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[i][n]);
	printf("%d\n",ans);
	fclose(stdin);
	return 0;
}