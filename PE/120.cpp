#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int main()
{
	ll ans=0;
	for(ll i=3;i<=1000;i++)
	{
		ll res=0;
		for(ll k=0;k<=10000;k++)
			res=max(res,(4*k+2)*i%(i*i));
		printf("%I64d %I64d\n",i,res);
		ans+=res;
	}
	printf("%I64d\n",ans);
	return 0;
}