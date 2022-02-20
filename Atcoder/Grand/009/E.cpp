#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int d=(n+m-1)/(k-1);
	dp[0][0]=1;
	int ans=0;
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(!dp[i][j]) continue;
			int nj=i*(k-1)-j;
			for(int x=0;x<k;x++)
			{
				if(x+j>n) continue;
				if(k-1-x+nj>m-1) continue;
				add(dp[i+1][j+x],dp[i][j]);
				if(x>0&&((n-(j+x))%(k-1)==0)&&((m-1-(k-1-x+nj))%(k-1)==0)) add(ans,dp[i][j]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}