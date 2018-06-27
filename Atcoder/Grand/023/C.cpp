#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll pow_mod(ll a,ll i)
{
	ll s=1;
	while(i)
	{
		if(i&1) s=s*a%MOD;
		a=a*a%MOD;
		i>>=1;
	}
	return s;
}
int main()
{
	scanf("%lld",&n);
	if(n==2)
	{
		puts("1");
		return 0;
	}
	ll ans=0;
	if(n&1)
	{
		ll st=3,mult=((n+1)*(n+3)/8)%MOD,addn=7,adds=n/2+2,last=0;
		ll init=2,cf=6,add=6;
		for(ll i=5;i<=n;i+=2)
		{
			init=init*cf%MOD;
			cf=(cf+add)%MOD;
			add=add+2;
		}
		//printf("%lld\n",init);
		ans+=init*((n+1)/2)%MOD;
		last=init;
		for(ll i=(n+1)/2+1;i<=n-1;i++)
		{
			init=init*mult%MOD*pow_mod(st,MOD-2)%MOD;
			//printf("%lld\n",init);
			mult=(mult+adds)%MOD;
			st=(st+addn)%MOD;
			adds++;
			addn+=4;
			ans=(ans+(init-last+MOD)*i)%MOD;
			last=init;
		}
		printf("%lld\n",ans);
	}
	else
	{
		ll st=1,mult=(n*(n+2)/8)%MOD,addn=5,adds=n/2+1,last=0;
		ll init=2,cf=6,add=6;
		for(ll i=6;i<=n;i+=2)
		{
			init=init*cf%MOD;
			cf=(cf+add)%MOD;
			add+=2;
		}
		//printf("%lld\n",init);
		ans+=init*(n/2)%MOD;
		last=init;
		for(ll i=n/2+1;i<=n-1;i++)
		{
			init=init*mult%MOD*pow_mod(st,MOD-2)%MOD;
			//printf("%lld\n",init);
			mult=(mult+adds)%MOD;
			st=(st+addn)%MOD;
			adds++;
			addn+=4;
			ans=(ans+(init-last+MOD)*i)%MOD;
			last=init;
		}
		printf("%lld\n",ans);
	}
	return 0;
}