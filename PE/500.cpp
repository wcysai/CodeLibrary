#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 500500507
#define LP 7376513
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll n,k,a[MAXN];
set<ll> ans;
ll prime[MAXN];
bool is_prime[MAXN];
bool valid[7500000];
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
	ll p=sieve(10000000);
	printf("%I64d\n",p);
	printf("%I64d\n",prime[500500]);
	memset(valid,false,sizeof(valid));
	for(ll i=0;i<500500;i++)
	{
		for(ll j=prime[i];j<LP;j=j*j)
			valid[j]=true;
	}
	ll cnt=0,ans=1;
	for(ll i=0;i<7500000;i++)
	{
		if(valid[i])
		{
			ans=ans*i%MOD;
			cnt++;
		}
		if(cnt==500500) break;
	}
	printf("%I64d\n",ans);
	return 0;
}