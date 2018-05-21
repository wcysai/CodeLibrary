#include<bits/stdc++.h>
#define MAXN 10005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
P Pell(ll N)
{
	ll p0=0,p1=1,q0=1,q1=0;
	ll a0=(int)sqrt(N),a1=a0,a2=a0;
	if(a0*a0==N) return P(-1,-1);
	ll g1=0,h1=1;
	while(true)
	{
		ll g2=-g1+a1*h1;
		ll h2=(N-g2*g2)/h1;
		a2=(g2+a0)/h2;
		ll p2=a1*p1+p0;
		ll q2=a1*q1+q0;
		if(p2*p2-N*q2*q2==1) return P(p2,q2);
		a1=a2;g1=g2;h1=h2;p0=p1;p1=p2;q0=q1;q1=q2;
	}
}
int main()
{
	ll n;
	ll ans=0,t=-1;
	for(ll i=2;i<=1000;i++)
	{
		if(Pell(i).F>=ans)
		{
			ans=Pell(i).F;
			t=i;
		}
	}
	printf("%I64d\n",t);
	return 0;
}