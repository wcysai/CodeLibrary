/*************************************************************************
    > File Name: 421.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-14 15:45:37
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100000005
#define INF 100000000
#define INF2 100000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll factor[MAXN],prime[MAXN],ans;
vector<ll> a;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll pow_mod(ll a,ll i,ll mod)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%mod;
         a=(a*a)%mod;
         i>>=1;
     }
     return s;
}
bool g_test(ll g,ll p)
{
    for(ll i=0;i<(int)a.size();i++)
        if(pow_mod(g,(p-1)/a[i],p)==1)
            return 0;
    return 1;
}
ll primitive_root(ll p)
{
    a.clear();
    for(ll tmp=p-1;tmp>1;)
    {
        ll t=factor[tmp];
        while(tmp%t==0) tmp/=t;
        a.push_back(t);
    }
    ll g=2;
    while(true)
    {
        if(g_test(g,p))
            return g;
        ++g;
    }
}
ll find_ans(ll p)
{
    ll x=gcd(p-1,15),g=primitive_root(p);
    ll res=0;
    for(ll i=0;i<x;i++)
        res+=(INF2-pow_mod(g,((p-1)/2+(p-1)/x*i)%(p-1),p))/p+1;
    return res;
}
void solve(ll n)
{
    ll p=0;
    for(ll i=2;i<=n;i++)
    {
        if(!factor[i])
        {
            factor[i]=i;
            prime[p++]=i;
            if(i==2) ans+=INF2; else ans+=find_ans(i)*i;
        }
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            factor[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
        if(i%10000==0) printf("%lld %lld\n",i,ans);    
    }
}


int main()
{
    solve(100000000);
    printf("%lld\n",ans);
    return 0;
}

