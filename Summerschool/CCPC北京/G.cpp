#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll n,m;
int main()
{
    while(scanf("%lld %lld",&n,&m)==2)
    {
        ll x=gcd(--n,--m);
        n/=x;
        m/=x;
        printf("%lld\n",n*m*x+1-(n-1)*(m-1));
    }
    return 0;
}
