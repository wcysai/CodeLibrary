#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long ll;
ll dp[MAXN];
ll find_ans(ll x)
{
	ll next;
	if(x==1) return dp[x]=0;
	else if(x<=1000000&&dp[x]!=-1) return dp[x];
	if(x&1) next=3*x+1; else next=x/2;
	if(x<=1000000) return dp[x]=1+find_ans(next); else return 1+find_ans(next);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	ll ans=0,t=0;
	for(ll i=1;i<=1000000;i++)
	{
		dp[i]=find_ans(i);
		if(dp[i]>ans)
		{
			ans=dp[i];
			t=i;
		}
	}
	printf("%lld\n",t);
	return 0;
}