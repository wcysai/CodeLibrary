#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,m;
ll fact(int x)
{
    ll s=1;
    for(int i=2;i<=x;i++)
        s=(s*i)%MOD;
    return s;
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
ll fact2(int x,int y)
{
    if(x>y) return mod_inverse(fact2(y,x),MOD);
    ll s=1;
    for(int i=x+2;i<=y;i+=2)
        s=(s*i)%MOD;
    return s;
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n%2!=m%2) printf("0\n");
        else
        {
            ll res=fact2(n-m,n+m-2);
            res=(((res*mod_inverse(fact(m),MOD))%MOD)*n)%MOD;
            if(((n-m)/2)%2==0) printf("%lld\n",res); else printf("%lld\n",(MOD-res)%MOD);
        }
    }
    return 0;
}
