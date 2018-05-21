#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll n,a[MAXN],b[MAXN];
int main()
{
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(ll i=0;i<n;i++)
		scanf("%lld",&b[i]);
	ll aop=0,bop=0,ans=0;
	for(ll i=0;i<n;i++)
	{
		aop+=max(0LL,(b[i]-a[i]+1)/2);
		if(b[i]>a[i]&&((b[i]-a[i])&1)) bop++;
		bop+=max(0LL,a[i]-b[i]);
		ans=ans+b[i]-a[i];
	}
	if(ans<aop||ans<bop) puts("No"); else puts("Yes");
	return 0;
}