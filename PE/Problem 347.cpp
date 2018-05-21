#include<bits/stdc++.h>
#define MAXN 10000005
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
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll find_ans(ll p,ll q)
{
	ll ans=0;
	ll res=p;
	while(res*q<=10000000)
	{
		ll now=res*q;
		while(now*q<=10000000) now=now*q;
		ans=max(ans,now);
		res=res*p;
	}
	return ans;
}
int main()
{
	ll p=sieve(10000000);
	ll ans=0;
	for(ll i=0;i<p;i++)
		for(ll j=i+1;j<p;j++)
		{
			if(prime[i]*prime[j]>10000000) break;
			ans+=find_ans(prime[i],prime[j]);
		}
	printf("%I64d\n",ans);
	return 0;
}