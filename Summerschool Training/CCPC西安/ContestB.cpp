#include<bits/stdc++.h>
#define MAXK 10000007
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
ll exp_mod(ll a,ll b,ll c)
{
    a%=c;
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%c;
        b>>=1,a=a*a%c;
    }
    return ans;
}
void extgcd(ll a,ll b,ll &x,ll &y)
{
    if(b!=0)
    {
        extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
int t;
ll p,q,k;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&p,&q,&k);
        ll x=(exp_mod(p,k,MOD)+exp_mod(2*q-p,k,MOD))%MOD;
        ll y=(exp_mod(p,k,MOD)*2)%MOD;
        if(k%2==1) x=(y-x+MOD)%MOD;
        printf("%lld\n",(x*mod_inverse(y,MOD))%MOD);
    }
    return 0;
}
