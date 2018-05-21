#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll pow_mod(ll a,ll i,ll MOD)
{
    if(i==0) return 1;
    ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%MOD;
         a=(a*a)%MOD;
         i>>=1;
     }
     return s;
}
ll a[250251],dp[250251][250];
int main()
{
	for(ll i=1;i<=250250;i++)
		a[i]=pow_mod(i,i,250);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(ll i=1;i<=250250;i++)
	{
		for(ll j=0;j<250;j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j])%10000000000000000;
			dp[i][(j+a[i])%250]=(dp[i][(j+a[i])%250]+dp[i-1][j])%10000000000000000;
		}
	}
	printf("%I64d\n",dp[250250][0]-1);
	return 0;
}