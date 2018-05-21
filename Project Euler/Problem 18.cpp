#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int tri[MAXN][MAXN],dp[MAXN][MAXN];
int main()
{
	int n=15;
	for(int i=0;i<n;i++)
		for(int j=0;j<i+1;j++)
			scanf("%d",&tri[i][j]);
	memset(dp,0,sizeof(dp));
	for(int j=0;j<n;j++)
		dp[n-1][j]=tri[n-1][j];
	for(int i=n-2;i>=0;i--)
		for(int j=0;j<i+1;j++)
			dp[i][j]=tri[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
	printf("%d\n",dp[0][0]);
	return 0;
}