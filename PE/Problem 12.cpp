#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
ll prime[MAXN];
bool is_prime[MAXN];
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
ll p;
ll find_divisor_num(ll x)
{
	ll res=1;
	for(ll i=0;i<p;i++)
	{
		ll cnt=0;
		while(x%prime[i]==0)
		{
			cnt++;
			x=x/prime[i];
		}
		if(cnt) res=res*(cnt+1);
		if(x==1) break;
	}
	return res;
}
int main()
{
	p=sieve(1000000);
	ll ans=1;
	while(true)
	{
		if(find_divisor_num(ans*(ans+1)/2)>=500)
		{
			printf("%lld\n",ans*(ans+1)/2);
			break;
		}
		ans++;
	}
	return 0;
}


