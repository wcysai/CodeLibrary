#include<bits/stdc++.h>
#define MAXN 1000005
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
ll is_cube(ll x)
{
	ll l=1,r=1000;
	while(r-l>1)
	{
		ll mid=(l+r)/2;
		if(mid*mid*mid<=x) l=mid; else r=mid;
	}
	if(l*l*l==x) return l; else return -1;
}
int main()
{
	int p=sieve(1000000);
	int ans=0;
	for(int k=1;3*k*k+3*k+1<1000000;k++)
		if(is_prime[3*k*k+3*k+1]) ans++;
	printf("%d\n",ans);
	return 0;
}