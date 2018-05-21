#include<bits/stdc++.h>
#define MAXN 100000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
ll prime[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
bool check(ll x)
{
    for(ll i=1;i*i<=x;i++)
    {
        if(x%i!=0) continue;
        if(!is_prime[i+x/i]) return false;
    }
    return true;
}
int main()
{
    ll p=sieve(100000000);
    ll ans=0;
    for(ll i=0;i<p;i++)
        if(check(prime[i]-1))
        {
            printf("%lld\n",prime[i]-1);
            ans+=prime[i]-1;
        }
    printf("%lld\n",ans);
    return 0;
}