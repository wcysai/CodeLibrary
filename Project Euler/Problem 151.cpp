#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
double dp[17][2][4][8][16];
int main()
{
	memset(dp,0,sizeof(dp));
	dp[1][1][1][1][1]=1.0;
	for(int i=1;i<=15;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<4;k++)
			{
				for(int l=0;l<8;l++)
				{
					for(int m=0;m<16;m++)
					{
						if(dp[i][j][k][l][m]==0) continue;
						int num=j+k+l+m;
						if(j>0) dp[i+1][j-1][k+1][l+1][m+1]+=dp[i][j][k][l][m]*(double)j/num;
						if(k>0) dp[i+1][j][k-1][l+1][m+1]+=dp[i][j][k][l][m]*(double)k/num;
						if(l>0) dp[i+1][j][k][l-1][m+1]+=dp[i][j][k][l][m]*(double)l/num;
						if(m>0) dp[i+1][j][k][l][m-1]+=dp[i][j][k][l][m]*(double)m/num;
					}
				}
			}
		}
	}
	double ans=0;
	for(int i=1;i<=14;i++)
		ans+=dp[i][1][0][0][0]+dp[i][0][1][0][0]+dp[i][0][0][1][0]+dp[i][0][0][0][1];
	printf("%.7f\n",ans);
	return 0;
}