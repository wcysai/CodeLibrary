#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,MOD;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int dp[2][MAXN],ndp[2][MAXN];
int main()
{
	scanf("%d%d",&N,&MOD);
	dp[0][0]=1;
	for(int i=0;i<N-1;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<=N-1;k++)
			{
				if(!dp[j][k]) continue;
				//no delete
				add(ndp[1][k],dp[j][k]);
				//delete upper/lower
				add(ndp[0][k+1],2LL*dp[j][k]%MOD);
				//delete left
				add(ndp[j][k+1],dp[j][k]);
				//delete left and upper/lower
				if(j) add(ndp[0][k+2],2LL*dp[j][k]%MOD);
			}
		}
		swap(dp,ndp);
	}
	for(int i=1;i<=N-1;i++)
	{
		int ans=dp[0][i];
		add(ans,dp[1][i]); add(ans,dp[1][i-1]);
		printf("%d%c",ans,i==N-1?'\n':' ');
	}
	return 0;
}