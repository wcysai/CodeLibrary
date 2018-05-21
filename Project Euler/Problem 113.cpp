#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll dp[105][10];
int main()
{
	memset(dp,0,sizeof(dp));
	for(ll i=0;i<10;i++)
		dp[1][i]=1;
	for(ll i=2;i<=100;i++)
		for(ll j=0;j<10;j++)
			for(ll k=0;k<=j;k++)
				dp[i][j]+=dp[i-1][k];
	ll res=0;
	for(ll i=1;i<10;i++)
		res+=dp[100][i];
	for(ll i=1;i<=100;i++)
	{
		for(ll j=1;j<10;j++)
			res+=dp[i][j];
		res-=9;
	}
	printf("%I64d\n",res);
	return 0;
}