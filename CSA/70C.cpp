#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,d[MAXN][MAXN];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			d[i][j]=i==j?0:INF;
	bool f=true;
	for(ll i=1;i<=m;i++)
	{
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(d[a][b]!=c&&d[a][b]!=INF) f=false;
		d[a][b]=d[b][a]=c;
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++)
				if(d[i][j]!=INF&&d[i][j]>d[i][k]+d[k][j]) f=false; 
	if(!f)
	{
		puts("-1");
		return 0;
	}
	printf("%lld\n",n*(n-1)/2);
	for(ll i=1;i<=n;i++)
		for(ll j=i+1;j<=n;j++)
			printf("%lld %lld %lld\n",i,j,d[i][j]>=10000000?10000000:d[i][j]);
	return 0;
}