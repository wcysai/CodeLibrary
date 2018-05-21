#include<bits/stdc++.h>
#define MAXN 100000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
bool is_prime(ll x)
{
    for(ll i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
int main()
{
    ll d=2,cnt=0;
    for(ll i=3;;i+=2)
    {
        if(is_prime(i*i)) cnt++;
        if(is_prime(i*i-d)) cnt++;
        if(is_prime(i*i-2*d)) cnt++;
        if(is_prime(i*i-3*d)) cnt++;
        if(cnt*10<i*2+1)
        {
            printf("%lld\n",i);
            return 0;
        }
        d+=2;
    }
    return 0;
}


