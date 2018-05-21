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
#define MAXL 1000005
#define MAXSQRTB 47000
#define INF 1000000000
using namespace std;
typedef long long ll;
bool is_prime_small[MAXSQRTB];
bool is_prime[MAXL];
vector<ll> prime;
void segment_sieve(ll a,ll b)
{
    for(ll i=0;(ll)i*i<=b;i++) is_prime_small[i]=true;
    for(ll i=0;i<b-a;i++) is_prime[i]=true;
    for(ll i=2;(ll)i*i<=b;i++)
    {
        if(is_prime_small[i])
        {
            for(ll j=2*i;(ll)j*j<=b;j+=i) is_prime_small[j]=false;
            for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=false;
        }
    }
    for(ll i=0;i<b-a;i++)
        if(is_prime[i]&&a+i!=1) prime.push_back(a+i);
}
int main()
{
    ll x,y;
    while(scanf("%lld%lld",&x,&y)==2)
    {
        prime.clear();
        segment_sieve(x,y+1);
        if(prime.size()<2)
        {
            printf("There are no adjacent primes.\n");
            continue;
        }
        ll res1=0,res2=INF,t1=0,t2=0;
        for(ll i=1;i<prime.size();i++)
        {
            if(prime[i]-prime[i-1]<res2)
            {
                res2=prime[i]-prime[i-1];
                t2=prime[i-1];
            }
            if(prime[i]-prime[i-1]>res1)
            {
                res1=prime[i]-prime[i-1];
                t1=prime[i-1];
            }
        }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",t2,t2+res2,t1,t1+res1);
    }
    return 0;
}

