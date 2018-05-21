#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
typedef long long ll;
ll dp[MAXN];
bool check(ll x)
{
	memset(dp,0,sizeof(dp));
	for(ll i=0;i<50;i++)
		dp[i]=1;
	ll sum=0;
	for(ll i=50;i<=x;i++)
	{
		dp[i]=1+dp[i-1]+sum;
		sum+=dp[i-50];
		if(dp[i]>1000000) return true;
	}
	return false;
}
int main()
{
	for(ll i=50;;i++)
		if(check(i))
		{
			printf("%I64d\n",i);
			return 0;
		}
	return 0;
}