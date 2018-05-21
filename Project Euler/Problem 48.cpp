#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 10000000000
using namespace std;
typedef long long ll;
ll pow_mod(ll a,ll i)
{
    ll s=1;
    for(ll j=1;j<=i;j++)
    	s=(s*a)%MOD;
    return s;
}
int main()
{
	ll ans=0;
	for(ll j=1;j<=1000;j++)
		ans=(ans+pow_mod(j,j))%MOD;
	printf("%I64d\n",ans);
   	return 0;
}
