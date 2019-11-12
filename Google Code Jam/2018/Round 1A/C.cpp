#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define eps 1e-8
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p,w[MAXN],h[MAXN];
double dp[MAXN][500*MAXN];
int main()
{
	scanf("%d",&t);
	int kase=0;
	while(t--)
	{
		kase++;
		scanf("%d%d",&n,&p);
		int s=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&w[i],&h[i]);
			s+=2*(w[i]+h[i]);
		}
		p-=s;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=50000;j++)
				dp[i][j]=-1;
		dp[0][0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=50000;j++)
			{
				if(dp[i][j]==-1) continue;
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				dp[i+1][j+2*min(w[i+1],h[i+1])]=max(dp[i+1][j+2*min(w[i+1],h[i+1])],dp[i][j]+2*sqrt(w[i+1]*w[i+1]+h[i+1]*h[i+1]));
			}
		}
		double ans=0;
		for(int j=0;j<=50000;j++)
		{
			if(j-p>eps) break;
			if(dp[n][j]-p>eps) {ans=p; break;}
			ans=max(ans,dp[n][j]);
		}
		printf("Case #%d: %.10lf\n",kase,ans+s);
		
	}
	return 0;
}