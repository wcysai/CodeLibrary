#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 10000000000
using namespace std;
typedef long long ll;
int main()
{
	ll res=1;
	for(int i=1;i<=7830457;i++)
		res=res*2%MOD;
	res=(res*28433+1)%MOD;
	printf("%lld\n",res);
	return 0;
}