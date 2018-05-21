#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
typedef long long ll;
ll dp[MAXN];
int main()
{
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;dp[4]=8;
	for(ll i=5;i<=50;i++)
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
	printf("%I64d\n",dp[50]);
	return 0;
}