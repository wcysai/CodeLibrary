#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
typedef long long ll;
ll dp[MAXN];
int main()
{
	dp[0]=dp[1]=dp[2]=1;
	ll sum=0;
	for(ll i=3;i<=50;i++)
	{
		dp[i]=1+dp[i-1]+sum;
		sum+=dp[i-3];
		printf("%I64d %I64d\n",i,dp[i]);
	}
	printf("%I64d\n",dp[50]);
	return 0;
}