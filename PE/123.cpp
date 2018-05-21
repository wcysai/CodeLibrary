#include<bits/stdc++.h>
#define MAXN 100000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int main()
{
	ll p=sieve(100000000);
	for(ll i=0;i<p;i+=2)
	{
		if(2*(i+1)*prime[i]%(prime[i]*prime[i])>10000000000)
		{
			printf("%lld\n",i+1);
			return 0;
		}
	}
	return 0;
}