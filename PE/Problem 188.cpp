#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 100000000
#define PHI 40000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll pow_mod(ll a,ll i)
{
	ll s=1;
	while(i)
	{
		if(i&1) s=s*a%PHI;
		a=a*a%PHI;
		i>>=1;
	}
	return s;
}
ll pow_mod2(ll a,ll i)
{
	ll s=1;
	while(i)
	{
		if(i&1) s=s*a%MOD;
		a=a*a%MOD;
		i>>=1;
	}
	return s;
}
ll find_ans(ll a,ll i)
{
	if(i==1) return a;
	else return pow_mod(a,PHI)*pow_mod(a,find_ans(a,i-1))%PHI;
}
int main()
{
	printf("%I64d\n",pow_mod2(1777,find_ans(1777,1854)));
	return 0;
}