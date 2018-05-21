#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll dp[41][1<<10][10];
ll find_ans(ll x)
{
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=9;i++)
		dp[1][(1<<i)][i]=1;
	for(ll i=1;i<=x-1;i++)
	{
		for(ll j=0;j<(1<<10);j++)
		{
			for(ll k=0;k<10;k++)
			{
				if(dp[i][j][k]==0) continue;
				if(k>0) dp[i+1][j|(1<<(k-1))][k-1]+=dp[i][j][k];
				if(k<9) dp[i+1][j|(1<<(k+1))][k+1]+=dp[i][j][k];
			}
		}
	}
	ll sum=0;
	for(ll i=0;i<10;i++)
		sum+=dp[x][(1<<10)-1][i];
	return sum;
}
int main()
{
	memset(dp,0,sizeof(dp));
	ll ans=0;
	for(ll i=10;i<=40;i++)
	{
		ans+=find_ans(i);
		//printf("%I64d\n",find_ans(i));
	}
	printf("%I64d\n",ans);
	return 0;
}