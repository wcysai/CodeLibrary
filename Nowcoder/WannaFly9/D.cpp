#include<bits/stdc++.h>
#define MAXN 1005
int dp[MAXN][MAXN];
int bi[MAXN][MAXN];
using namespace std;
int main()
{
	dp[1][1]=bi[1][1]=1;
	for(int i=2;i<=20;i++)
	{
		dp[i][1]=i;
		bi[i][1]=1;
		for(int j=2;j<=i;j++)
		{
			bi[i][j]=bi[i-1][j]+bi[i-1][j-1];
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+1;
		}
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=i;j++)
			printf("%d ",dp[i][j]-bi[i][j]);
		printf("\n");
	}
	return 0;
}