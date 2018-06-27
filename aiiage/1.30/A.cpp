#include<bits/stdc++.h>
#define MAXN 100005
#define MAXP 100005
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll deg[MAXN],n;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll fact[MAXP];
ll mod_fact(ll n,ll p,ll &e)
{
    e=0;
    if(n==0) return 1;
    ll res=mod_fact(n/p,p,e);
    e+=n/p;
    if(n/p%2!=0) return res*(p-fact[n%p])%p;
    return res*fact[n%p]%p;
}
ll mod_comb(ll n,ll k,ll p)
{
    if(n<0||k<0||n<k) return 0;
    ll e1,e2,e3;
    ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
    if(e1>e2+e3) return 0;
    return a1*mod_inverse(a2*a3%p,p)%p;
}
int main()
{
	scanf("%lld",&n);
	memset(deg,0,sizeof(deg));
	ll ans=(n+n*(n-1)/2)%MOD;
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		deg[x]++;deg[y]++;
	}
	fact[0]=1;
	for(ll i=1;i<=100000;i++)
		fact[i]=fact[i-1]*i%MOD;
	for(ll i=1;i<=n;i++)
		if(deg[i]>=3) ans=(ans+mod_comb(deg[i],3,MOD));
	printf("%lld\n",ans);
	return 0;
}