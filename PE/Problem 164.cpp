#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll dp[21][10][10];
int main()
{
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=9;i++)
		for(ll j=0;i+j<=9;j++)
			dp[2][i][j]=1;
	for(ll i=3;i<=20;i++)
		for(ll j=0;j<=9;j++)
			for(ll k=0;j+k<=9;k++)
				for(ll l=0;j+k+l<=9;l++)
					dp[i][k][l]+=dp[i-1][j][k];
	ll ans=0;
	for(ll i=0;i<=9;i++)
		for(ll j=0;i+j<=9;j++)
			ans+=dp[20][i][j];
	printf("%lld\n",ans);
	return 0;
}