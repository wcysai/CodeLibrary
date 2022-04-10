#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
int cnt[MAXN][MAXN];
int dp[MAXN][MAXN];
int main()
{
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&cnt[i][j]);
		for(int len=1;len<=n;len++)
		{
			for(int l=1;l+len-1<=n;l++)
			{
				int r=l+len-1;
				int s=0;
				for(int i=1;i<=m;i++)
				{
					int all=INF;
					for(int j=l;j<=r;j++) all=min(all,cnt[j][i]);
					s+=all;
				}
				if(l==r) dp[l][r]=2*s;
				else
				{
					dp[l][r]=INF;
					for(int k=l;k<r;k++) dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]-2*s); 
				}
			}
		}
		printf("Case #%d: %d\n",t,dp[1][n]);
	}
	return 0;
}