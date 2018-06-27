#include<bits/stdc++.h>
#define MAXN 35
#define MOD 998244353
using namespace std;
typedef long long ll;
double a[MAXN];
ll n;
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
ll pos(ll x)
{
	if(x==1) return (ll)(a[i]*1000000)*mod_inverse(1000000,MOD);
	
}

int main()
{
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lf",&a[i]);

}