#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll ans=0;
	for(ll i=1;i<=47;i++)
		for(ll j=1;j<=43;j++)
		{
			ll x=max(i,j),y=min(i,j);
			ans+=x*(x+1)*y*(y+1)/4;
			ans+=y*((2*x-y)*(4*y*y-1)-3)/6;
		}
	printf("%lld\n",ans);
	return 0;
}