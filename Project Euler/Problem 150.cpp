#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll tri[MAXN][MAXN],sum[MAXN][MAXN];
int main()
{
	ll k=0,t=0;
	for(ll i=1;i<=1000;i++)
		for(ll j=1;j<=i;j++)
		{
			k++;
			t=(615949*t+797807)%1048576;
			tri[i][j]=t-524288;
		}
	memset(sum,0,sizeof(sum));
	for(ll i=1;i<=1000;i++)
		for(ll j=1;j<=i;j++)
			sum[i][j]=sum[i][j-1]+tri[i][j];
	ll ans=0;
	for(ll i=1;i<=1000;i++)
		for(ll j=1;j<=i;j++)
		{
			ll res=0;
			for(ll k=0;i+k<=1000;k++)
			{
			  	res+=sum[i+k][j+k]-sum[i+k][j-1];
			  	ans=min(ans,res);
			}
		}
	printf("%lld\n",ans);
	return 0;
}