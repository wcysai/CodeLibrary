#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<assert.h>
#define MAXN 3000005
#define MOD 16290047
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
long long a,b,k;
ll prime[MAXN];
ll t[MAXN],d[MAXN];
bool is_prime[MAXN];
ll pow_mod(ll a,ll i)
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
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}

int main()
{
	scanf("%lld%lld%lld",&a,&b,&k);
	ll p=sieve((ll)sqrt(b));
	for(ll i=0;i<=b-a;i++)
	{
		d[i]=1;
		t[i]=i+a;
	}
	for(ll i=0;i<p;i++)
	{
		for(ll j=(a+prime[i]-1)/prime[i]*prime[i];j<=b;j+=prime[i]) 
		{
			//printf("%lld ",j);
			ll cnt=0;
			while((t[j-a]%prime[i])==0)
			{
				cnt++;
				t[j-a]/=prime[i];
			}
			d[j-a]=(d[j-a]*((cnt*k+1)%MOD))%MOD;
		}
		//printf("\n");
	}
	/*for(ll i=0;i<=b-a;i++)
		printf("%I64d ",d[i]);
	printf("\n");
	for(ll i=0;i<=b-a;i++)
		printf("%I64d ",t[i]);
	printf("\n");*/
	for(ll i=0;i<=b-a;i++)
		if(t[i]!=1) d[i]=(d[i]*(k+1))%MOD;
	ll ans=0;
	for(ll i=0;i<=b-a;i++)
		ans=(ans+d[i])%MOD;
	printf("%lld\n",ans);
	return 0;
}
