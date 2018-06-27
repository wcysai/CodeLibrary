#include<bits/stdc++.h>
#define MAXN 100005
#define MAXP 1005
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll t,n,p;
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
ll mod_inverse(ll a)
{
    ll x,y;
    extgcd(a,MOD,x,y);
    return (MOD+x%MOD)%MOD;
}
ll fact[MAXP];
ll pow_mod(ll a,ll i,ll m)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%m;
         a=(a*a)%m;
         i>>=1;
     }
     return s;
}
int main()
{
    scanf("%lld",&t);
    p=sieve(40000);
    while(t--)
    {
    	scanf("%lld",&n);
        if(n==1)
        {
            printf("9\n");
            continue;
        }
    	ll res=pow_mod(10,n,MOD);
        static vector<ll> prime_factor;
        prime_factor.clear();
        ll dummy=n;
    	for(ll i=0;i<p;i++)
        {
            if(dummy%prime[i]==0)
            {
                prime_factor.push_back(prime[i]);
                while(dummy%prime[i]==0) dummy=dummy/prime[i];
            }
            if(dummy==1) break;
        }
        if(dummy!=1) prime_factor.push_back(dummy);
        ll sz=prime_factor.size();
        for(ll i=1;i<(1<<sz);i++)
        {
            int num=0;
            for(ll j=i;j!=0;j>>=1) num+=j&1;
            ll ans=1;
            for(ll j=0;j<sz;j++)
                if((i>>j)&1) ans=ans*prime_factor[j];
            if(num&1) res=(res-pow_mod(10,n/ans,MOD)+MOD)%MOD; else res=(res+pow_mod(10,n/ans,MOD))%MOD;
        }
    	printf("%lld\n",(res*mod_inverse(n))%MOD);
    }
    return 0;
}

