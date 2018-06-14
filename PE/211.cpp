/*************************************************************************
    > File Name: 211.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-14 14:52:12
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 64000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],prime[MAXN],sigma[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=true;
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
    ll l=1,r=1000000000;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(mid*mid<=x) l=mid; else r=mid;
    }
    return l*l==x;
}
int main()
{
    n=64000000-1;
    ll p=sieve(n);
    puts("done1!");
    for(ll i=1;i<=n;i++) sigma[i]=1;
    for(ll i=0;i<p;i++)
    {
        ll s=1;
        printf("%lld\n",prime[i]);
        for(ll j=prime[i];j<=n;j*=prime[i])
        {
            s*=prime[i]*prime[i];
            sigma[j]=s+sigma[j/prime[i]];
            for(ll k=2*j;k<=n;k+=j)
            {
                if((k/j)%prime[i]==0) continue;
                sigma[k]*=sigma[j];
            }
        }
    }
    puts("done2!");
    ll ans=0;
    for(ll i=1;i<=n;i++)
        if(check(sigma[i])) ans+=i;
    printf("%lld\n",ans);
    return 0;
}

