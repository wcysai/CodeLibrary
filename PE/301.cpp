#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll cnt=0;
	ll res=1;
	for(int i=0;i<30;i++)
		res*=2;
	for(ll i=1;i<=res;i++)
		if((i^(2*i)^(3*i))==0) cnt++;
	printf("%lld\n",cnt);
}