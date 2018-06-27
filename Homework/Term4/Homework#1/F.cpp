#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<assert.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				if(j!=1) a[i][j]=max(a[i][j],a[i][j-1]);
			}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=0;k<=j;k++)
					dp[i][j]=max(dp[i][j],dp[i-1][j-k]+a[i][k]);
		printf("%d\n",dp[n][m]);
	}
	return 0;
}