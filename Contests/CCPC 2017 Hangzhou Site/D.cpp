#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
ll C;
ll n,x[MAXN],v[MAXN];
ll a[MAXN];
ll save1[MAXN],save2[MAXN];
int main()
{
	scanf("%lld",&n);
	scanf("%lld",&C);
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&v[i]);
	x[n+1]=C;
	for(ll i=1;i<=n;i++)
		a[i]=v[i]-(x[i]-x[i-1]);
	ll now=0;
	for(ll i=1;i<=n;i++)
	{
		now+=a[i];
		save1[i]=max(save1[i-1],now);
	}
	for(ll i=n;i>=1;i--)
		a[i]=v[i]-(x[i+1]-x[i]);
	now=0;
	for(ll i=n;i>=1;i--)
	{
		now+=a[i];
		save2[i]=max(save2[i+1],now);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
		a[i]=v[i]-2*(x[i]-x[i-1]);
	now=0;
	for(ll i=0;i<=n;i++)
	{
		now+=a[i];
		ans=max(ans,now+save2[i+1]);
	}
	for(ll i=1;i<=n;i++)
		a[i]=v[i]-2*(x[i+1]-x[i]);
	now=0;
	//printf("%lld\n",save1[3]);
	for(ll i=n+1;i>=1;i--)
	{
		now+=a[i];
		ans=max(ans,now+save1[i-1]);
	}
	printf("%lld\n",ans);
	return 0;
}