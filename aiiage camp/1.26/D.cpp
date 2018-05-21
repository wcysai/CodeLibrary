#include<bits/stdc++.h>
#define MAXN 100000
#define MAXP 2005
using namespace std;
typedef long long ll;
ll T,x,y,M;
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
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&x,&y,&M);
        fact[0]=1;
        for(ll i=1;i<=2000;i++)
            fact[i]=(fact[i-1]*i)%M;
        ll res=0;
        for(ll k=((x+y)&1);k<=y;k+=2)
        {
            ll n=(x+y+k)/2;
            ll comb1=(fact[n]*mod_inverse(fact[k],M)%M)*mod_inverse(fact[n-k],M)%M;
            n=(x+y-k);
            ll comb2=(fact[n]*mod_inverse(fact[x],M)%M)*mod_inverse(fact[n-x],M)%M;
            res=(res+comb1*comb2)%M;
        }
        printf("%lld\n",res);
    }
    return 0;
}

