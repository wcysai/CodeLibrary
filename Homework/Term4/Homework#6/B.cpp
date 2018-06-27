#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<assert.h>
#include<vector>
#include<map>
#include<queue>
#define MAXN 520
#define MAXV 5020
#define INF 1000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,B,dp[MAXN][MAXV],w[MAXN],v[MAXN];
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&B);
		ll s=0;
		for(ll i=1;i<=n;i++)
			scanf("%lld%lld",&w[i],&v[i]);
		for(ll i=0;i<=n;i++)
			for(ll j=0;j<=5000;j++)
				dp[i][j]=j==0?0:INF;
		for(ll i=1;i<=n;i++)
		{
			s+=v[i];
			for(ll j=0;j<=s;j++)
			{
				if(j<v[i]) dp[i][j]=dp[i-1][j];
				else dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
			}
		}
		for(ll i=s;i>=0;i--)
			if(dp[n][i]<=B)
			{
				printf("%lld\n",i);
				break;
			}
	}
	return 0;
}