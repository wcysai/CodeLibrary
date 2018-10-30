/*************************************************************************
    > File Name: 3817.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-30 10:45:39
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,inv2,inv6,a,b,c,l,r;//need initialize
long double t;
struct E
{
    ll f,g,h;
    E(){}
    E(ll _f,ll _g,ll _h){f=_f,g=_g,h=_h;}
};
ll pow_mod(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=s*a%MOD;
        a=a*a%MOD;
        i>>=1;
    }
    return s;
}
// f:\sum_{i=0}^{n}\lfloor\frac{ai+b}{c}\rfloor
// g:\sum_{i=0}^{n}i\times\lfloor\frac{ai+b}{c}\rfloor
// g:\sum_{i=0}^{n}\lfloor\frac{ai+b}{c}\rfloor^{2}
E cal(ll a,ll b,ll c,ll n)
{
    if(!n) return E(0,0,0);
    ll g=__gcd(a,__gcd(b,c));
    a/=g;b/=g;c/=g;
    ll d=(a*t+b)/c;
    if(n==1) return E(d,0,0);
    E x,y;
    if(d>0)
    {
        x=cal(a,b-d*c,c,n);
        y.f=x.f+n*(n+1)/2*d;
        return y;
    }
    ll m=(a*n*t+b*n)/c;
    x=cal(a*c,-b*c,a*a*r-b*b,m);
    y.f=n*m-x.f;
    return y;
}
ll T;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&r);
        t=sqrt(r);
        if((ll)t*(ll)t==r)
        {
            if((ll)t%2==0) printf("%lld\n",n);
            else printf("%lld\n",n&1?-1LL:0LL);
        }
        else
        {
            printf("%lld\n",4*cal(1,0,2,n).f-2*cal(1,0,1,n).f+n);
        }
    }
    return 0;
}

