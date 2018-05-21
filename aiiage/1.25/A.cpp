#include<bits/stdc++.h>
#define MAXP 200020
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll query,t,x;
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
int main()
{
    scanf("%lld",&query);
    memset(fact,0,sizeof(fact));
    fact[0]=1;
    for(ll i=1;i<=200005;i++)
    	fact[i]=(fact[i-1]*i)%MOD;
    while(query--)
    {
    	scanf("%lld%lld",&t,&x);
    	x=max(x,-x);
    	if(x>t) {printf("0\n"); continue;}
    	printf("%lld\n",(((fact[2*t]*mod_inverse(fact[t+x])%MOD)*mod_inverse(fact[t-x])%MOD)*mod_inverse(pow_mod(4,t))%MOD));
    }
    return 0;
}

