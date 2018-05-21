#include<bits/stdc++.h>
#define MAXN 10000005
using namespace std;
int dp[MAXN];
int main()
{
	int cnt=0;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<10000000;i++)
	{
		if(i==1||i==89) dp[i]=i;
		int t=i;
		while(t!=1&&t!=89&&dp[t]<0)
		{
			int s=0;
			while(t>0)
			{
				s+=(t%10)*(t%10);
				t=t/10;
			}
			t=s;
		}
		if(t==1||t==89) dp[i]=t; else dp[i]=dp[t];
		if(dp[i]==89) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
