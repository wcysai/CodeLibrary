#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int dp[10],ndp[10];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=9;i++) dp[i]=1;
	for(int i=2;i<=n;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j=1;j<=9;j++)
		{
			for(int k=j-1;k<=j+1;k++)
			{
				if(k>=1&&k<=9) add(ndp[k],dp[j]);
			}
		}
		swap(dp,ndp);
	}
	int ans=0;
	for(int i=1;i<=9;i++) add(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}