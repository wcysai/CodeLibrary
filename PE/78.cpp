#include<bits/stdc++.h>
#define MAXN 100000
#define MOD 1000000
using namespace std;
int dp[MAXN+1];
int num[MAXN];
int main()
{
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));
	int t=0;
	for(int k=1;;k++)
	{
		num[t++]=k*(3*k-1)/2*(k&1?1:-1);
		num[t++]=k*(3*k+1)/2*(k&1?1:-1);
		if(max(num[t-1],-num[t-1])>MAXN) break;
	}
	dp[0]=1;
	for(int i=1;;i++)
	{
		for(int j=0;;j++)
		{
			int sgn=num[j]>0?1:-1;
			int res=max(num[j],-num[j]);
			if(res>i) break;
			dp[i]=(dp[i]+sgn*dp[i-res]+MOD)%MOD;
		}
		printf("%d %d\n",i,dp[i]);
		if(dp[i]==0) return 0;
	}
	return 0;
}