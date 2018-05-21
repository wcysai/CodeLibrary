#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int dp[MAXN][MAXN];
int main()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=100;i++)
		dp[0][i]=1;
	for(int i=1;i<=100;i++)
	{
		dp[i][1]=1;
		for(int j=2;j<=100;j++)
			if(i>=j) dp[i][j]=dp[i][j-1]+dp[i-j][j]; else dp[i][j]=dp[i][j-1];
		printf("%d %d\n",i,dp[i][i]);
	}
	printf("%d\n",dp[100][100]-1);
	return 0;
}