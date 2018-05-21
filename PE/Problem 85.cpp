#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
int main()
{
	ll ti=0,tj=0,res=INF;
	for(ll i=1;i<=300;i++)
		for(ll j=1;j<=i;j++)
		{
			ll num=i*(i+1)*j*(j+1)/4;
			if(max(num-2000000,2000000-num)<res)
			{
				res=max(num-2000000,2000000-num);
				ti=i;
				tj=j;
			}
		}
	printf("%lld %lld %lld\n",ti,tj,ti*tj);
	return 0;
}