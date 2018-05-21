#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll dp[32][3];
int main()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	dp[0][1]=dp[0][2]=0;
	for(ll i=1;i<=31;i++)
	{
		dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][1];
	}
	ll ans=dp[31][0];
	for(ll i=1;i<=30;i++)
		ans+=dp[i][0]*dp[31-i][0];
	printf("%lld\n",ans);
	return 0;
}