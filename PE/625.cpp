/*************************************************************************
    > File Name: 625.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-14 00:49:59
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
bool is_prime[MAXN];
ll cnt,phi[MAXN],prime[MAXN];
ll n,f[MAXN];
map<ll,ll> mp; 
ll pow_mod(ll a,ll i)
{
    a%=MOD;
	ll s=1;
	while(i)
	{
		if(i&1) s=s*a%MOD;
		a=a*a%MOD;
		i>>=1;
	}
	return s;
}
void genphi(ll n)
{
    ll p=0;
    memset(phi,0,sizeof(phi));
    phi[1]=1;
     for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1;}
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
    for(ll i=1;i<=n;i++) f[i]=(f[i-1]+phi[i])%MOD;
}
ll calc(ll x)
{
	if(x<=10000000) return f[x];
	if(mp.find(x)!=mp.end()) return mp[x];
	ll ans=((x%MOD)*((x+1)%MOD)%MOD)*pow_mod(2,MOD-2)%MOD;
	for(ll i=2,r;i<=x;i=r+1)
	{
		r=x/(x/i);
		ans=(ans-calc(x/i)*((r-i+1)%MOD)%MOD+MOD)%MOD;
	}
	return mp[x]=ans;
}
const long long num=100000000000LL;
int main()
{
	genphi(10000000);
	ll ans=0;
    for(ll i=1,j;i<=num;i=j+1)
    {
        j=num/(num/i);
        ll res=(((i+j)%MOD)*((j-i+1)%MOD)%MOD)*pow_mod(2,MOD-2)%MOD;
        ans=(ans+res*calc(num/i))%MOD;
        printf("%lld\n",i);
    }
    printf("%lld\n",ans);
	return 0;
}

