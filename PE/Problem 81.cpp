#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int mat[MAXN][MAXN],dp[MAXN][MAXN];
int main()
{
	freopen("p081_matrix.txt", "r", stdin);
	int n=80;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i==0&&j==0) dp[i][j]=mat[i][j];
			else if(i==0) dp[i][j]=mat[i][j]+dp[i][j-1];
			else if(j==0) dp[i][j]=mat[i][j]+dp[i-1][j];
			else dp[i][j]=mat[i][j]+min(dp[i-1][j],dp[i][j-1]);
		}
	printf("%d\n",dp[n-1][n-1]);
	fclose(stdin);
	return 0;
}