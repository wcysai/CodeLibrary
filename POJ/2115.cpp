#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
using namespace std;
typedef __int64 ll;
ll a,b,c,k;
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
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k);
    while(a||b||c||k)
    {
        k=(1LL<<k);
        b=b-a;
        while(b<0) b+=k;
        b=b%k;
        c=c%k;
        if(c==0)
        {
            if(b==0) printf("0\n"); else printf("FOREVER\n");
        }
        else
        {
            if(gcd(c,k)!=1)
            {
                ll p=gcd(c,k);
                if(b%p!=0)
                {
                    printf("FOREVER\n");
                    scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k);
                    continue;
                }
                else
                {
                    b/=p;
                    c/=p;
                    k/=p;
                }
            }
            printf("%I64d\n",(mod_inverse(c,k)*b)%k);
        }
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k);
    }
}
