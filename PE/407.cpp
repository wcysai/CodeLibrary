/*************************************************************************
    > File Name: 407.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-14 23:57:39
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,factor[MAXN],prime[MAXN],a[MAXN];
void sieve(ll n)
{
    ll p=0;
    factor[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(!factor[i])
        {
            factor[i]=i;
            prime[p++]=i;
        }
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            factor[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}
ll pow_mod(ll a,ll i,ll m)
{
    if(i==0) return 1;
    ll s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
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
    sieve(10000000);
    vector<int> v;
    for(ll i=2;i<=10000000;i++) a[i]=1;
    for(ll i=1;i<=10000000;i++)
    {
        ll t=i;v.clear();
        while(t>1)
        {
            ll u=factor[t],tt=t;
            while(t%u==0) t=t/u;
            v.push_back(tt/t);
        }
        ll sz=v.size();
        for(ll j=0;j<(1<<sz);j++)
        {
            ll s=1;
            for(ll k=0;k<sz;k++)
                if((j>>(sz-1-k))&1) s*=v[k];
            ll w=mod_inverse(s,i/s);
            if(s*w<i) a[i]=max(s*w,a[i]);
        }
        if(i%10000==0) printf("%lld\n",i);
    }
    ll ans=0;
    for(ll i=1;i<=10000000;i++) ans+=a[i]; 
    printf("%lld\n",ans);
    return 0;
}

