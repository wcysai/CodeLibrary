#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
ll power(ll a,ll x)
{
	ll s=1;
	for(ll i=0;i<x;i++)
		s=s*a;
	return s;
}
ll n,k;
int main()
{
	while(scanf("%I64d%I64d",&k,&n)==2)
	{
		if(n==0&&k==0) break;
		ll res=0;
		for(ll i=1;i<=n;i++)
			res=res+power(k,gcd(i,n));
		if(n&1)
		{
			for(ll i=1;i<=n;i++)
				res=res+power(k,(n+1)/2);
		}
		else 
		{
			for(ll i=1;i<=n/2;i++)
				res=res+power(k,n/2);
			for(ll i=1;i<=n/2;i++)
				res=res+power(k,n/2+1);
		}
		printf("%lld\n",res/(2*n));
	}
	return 0;
}
