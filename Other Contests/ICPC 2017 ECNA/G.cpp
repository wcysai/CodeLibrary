#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 20005
#define INF 1000000000
using namespace std;
int n,m,a[MAXM],dp[MAXN][MAXM][3];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1)
	{
		printf("%d\n",min(a[1],m));
		return 0;
	}
	for(int i=0;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<3;k++)
				dp[i][j][k]=-INF;
	dp[1][m][0]=min(m,a[1]);
	dp[1][m][1]=0;	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<3;k++)
			{
				if(dp[i][j][k]==-INF) continue;
				if(k==0) 
				{
					dp[i+1][j*2/3][0]=max(dp[i+1][j*2/3][0],dp[i][j][k]+min(j*2/3,a[i+1]));
					dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][k]);
				}
				else if(k==1)
				{
					dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][k]+min(j,a[i+1]));
					dp[i+1][j][2]=max(dp[i+1][j][2],dp[i][j][k]);
				}
				else dp[i+1][m][0]=max(dp[i+1][m][0],dp[i][j][k]+min(m,a[i+1]));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<3;j++)
			ans=max(ans,dp[n][i][j]);
	printf("%d\n",ans);
	return 0;
}