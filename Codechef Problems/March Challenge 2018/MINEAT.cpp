#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,h,a[MAXN];
bool C(ll x)
{
	ll ans=0;
	for(ll i=0;i<n;i++)
		ans+=(a[i]-1)/x+1;
	return ans<=h;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&h);
		ll res=0;
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			res=max(res,a[i]);
		}
		ll l=0,r=res+1;
		while(r-l>1)
		{
			ll mid=(l+r)/2;
			if(C(mid)) r=mid; else l=mid;
		}
		printf("%lld\n",r);
	}
	return 0;
}