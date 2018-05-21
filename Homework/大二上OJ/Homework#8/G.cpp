#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll n;
ll s;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll power(ll x,ll i)
{
    ll p=1;
    for(ll j=0;j<i;j++)
        p=p*x;
    return p;
}
int main()
{
    while(scanf("%lld",&n)==1)
    {
        s=0;
        if(n==0) {puts("0"); continue;}
        if(n<0) break;
        for(ll i=0;i<=n-1;i++)
            s+=power(3,gcd(i,n));
        if(n&1)
        {
            for(ll i=0;i<n;i++)
                s+=power(3,(n+1)/2);
            s=s/(2*n);
        }
        else
        {
            for(ll i=0;i<n/2;i++)
                s+=power(3,n/2+1);
            for(ll i=0;i<n/2;i++)
                s+=power(3,n/2);
            s=s/(2*n);
        }
        printf("%lld\n",s);
    }
    return 0;
}
