#include<bits/stdc++.h>
#define MAXN 120005
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
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
ll rad[MAXN];
int main()
{
	ll p=sieve(120000);
	for(ll i=1;i<=120000;i++)
	{
		ll res=1,t=i;
		for(ll j=0;j<p;j++)
		{
			if(is_prime[t]) {res=res*t; break;}
			if(t==1) break;
			if(t%prime[j]==0) 
			{
				res=res*prime[j];
				while(t%prime[j]==0) t=t/prime[j];
			}
		}
		rad[i]=res;
	}
	ll ans=0;
	for(ll i=1;i<=120000;i++)
	{
		if(rad[i]*3>i) continue;
		for(ll j=1;j<=i/2;j++)
		{
			if(gcd(j,i-j)!=1) continue;
			if(rad[i-j]*rad[j]*rad[i]<i)
			{
				ans+=i;
				printf("%I64d %I64d %I64d %I64d\n",j,i-j,i,rad[i]);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}