#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
set<P> s;
int main()
{
	for(ll i=1;i<=10000000;i=i*2LL)
	{
		s.clear();
		for(ll j=0;j<i;j++)
			for(ll k=0;k<i;k++)
				s.insert(P((j*j+k*k)%i,j*k%i));
		printf("%lld %lld \n",i,(ll)s.size());
	}
	return 0;
}