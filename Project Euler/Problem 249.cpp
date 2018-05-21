#include <bits/stdc++.h>
#define MAXN 4000005
#define MAXL 1550000
#define MOD 10000000000000000
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll prime[MAXN];
ll sum[MAXL];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(MAXL);
    sum[0]=1;
    for(ll i=0;i<669;i++)
    {
        for(ll j=MAXL-1;j>=0;j--)
            if(j>=prime[i]) sum[j]=(sum[j]+sum[j-prime[i]])%MOD;
        //printf("%I64d\n",i);
    }
    ll ans=0;
    for(ll i=0;i<p;i++)
        ans=(ans+sum[prime[i]])%MOD;
    printf("%I64d\n",ans);
    return 0;
}

