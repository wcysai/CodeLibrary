#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll dp[22][10002];
ll last[22][10002];
ll maxi=0;
ll solve(ll p)
{
	memset(dp,-1,sizeof(dp));
	memset(last,-1,sizeof(last));
	dp[0][0]=0;
	ll t=1,save=0;
	for(ll i=1;i<22;i++)
	{
		for(ll j=0;j<p;j++)
			if(dp[i-1][j]!=-1) 
			{
				dp[i][j]=dp[i-1][j];
				last[i][j]=0;
			}
		for(ll j=0;j<p;j++)
		{
			ll from=(j-t+p)%p;
			if(dp[i][j]!=1&&dp[i-1][from]!=-1)
			{
				dp[i][j]=1;
				last[i][j]=1;
			}
		}
		for(ll j=0;j<p;j++)
		{
			ll from=((j-2*t)%p+p)%p;
			if(dp[i][j]!=1&&dp[i-1][from]!=-1)
			{
				dp[i][j]=1;
				last[i][j]=2;
			}
		}
		if(dp[i][0]==1)
		{
			save=i;
			break;
		}
		t=t*10%p;
	}
	ll res=0,s=1;
	for(ll i=1;i<save;i++)
		s=s*10;
	ll now=0;
	for(ll i=save;i>=1;i--)
	{
		res+=last[i][now]*s;
		now=((now-(last[i][now]*s)%p)+p)%p;
		s=s/10;
	}
	printf("%lld %lld\n",p,res);
	//printf("%lld\n",res);
	assert(res%p==0);
	return res/p;
}
int main()
{
	ll ans=0;
	for(ll i=1;i<=9998;i++)
		ans+=solve(i);
	ans+=1111333355557778LL;
	ans+=solve(10000);
	printf("%lld\n",ans);
	return 0;
}