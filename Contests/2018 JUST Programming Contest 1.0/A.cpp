#include<bits/stdc++.h>
#define MAXN 200050
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,m,pow2[MAXN],invpow2[MAXN],fact[MAXN],invf[MAXN];
ll pow_mod(ll a,ll i)
{
	ll s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i=i>>1;
	}
	return s;
}
ll comb(ll n,ll k)
{
	return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
	pow2[0]=1;invpow2[0]=1;
	for(ll i=1;i<=200005;i++)
		invpow2[i]=500000004LL*invpow2[i-1]%MOD;
	fact[0]=1;invf[0]=1;
	for(ll i=1;i<=200005;i++)
	{
		fact[i]=1LL*fact[i-1]*i%MOD;
		invf[i]=pow_mod(fact[i],MOD-2);
	}
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&m);
		if(n<0) n=-n;
		if(((m-n)&1)||(n>m)) {puts("0"); continue;}
		printf("%I64d\n",1LL*comb(m,(n+m)/2)*invpow2[m]%MOD);
	}
	return 0;
}