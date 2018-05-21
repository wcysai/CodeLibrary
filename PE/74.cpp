#include<bits/stdc++.h>
#define MAXN 3000000
using namespace std;
typedef long long ll;
int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};
int dp[MAXN];
int find_next(int x)
{
	int s=0;
	while(x>0)
	{
		s+=fac[x%10];
		x/=10;
	}
	return s;
}
int find_ans(int x)
{
	if(dp[x]!=-1) return dp[x];
	int cnt=1;
	int t=find_next(x);
	while(dp[t]==-1&&t!=x)
	{
		cnt++;
		t=find_next(t);
	}
	if(t==x) return dp[x]=cnt; else return dp[x]=cnt+dp[t];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	dp[145]=dp[40585]=1;
	dp[169]=dp[363601]=dp[1454]=3;
	dp[871]=dp[45361]=dp[872]=dp[45362]=2;
	int ans=0;
	for(int i=1;i<1000000;i++)
	{
		if(dp[i]==-1) find_ans(i);
		if(dp[i]==60) ans++;
		//printf("%d %d\n",i,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}