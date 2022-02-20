#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int pow_mod(int a,ll i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int main()
{
	scanf("%lld",&n);
	ll t=1;
	while(t*2<=n) t*=2;
	ll num=min(n-t,2*t-n);
	printf("%d\n",1LL*pow_mod(3,num)*pow_mod(2,(n-3*num)/2)%MOD);
	return 0;
}