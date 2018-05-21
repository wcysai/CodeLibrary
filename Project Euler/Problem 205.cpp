#include<bits/stdc++.h>
#define MAXN 40
using namespace std;
typedef long long ll;
struct polynomial
{
	ll coefficient[37];
	void init()
	{
		for(ll i=0;i<=36;i++)
			coefficient[i]=0;
	}
}Peter,Colin;
polynomial mult(polynomial x,polynomial y)
{
	polynomial res;
	for(ll i=0;i<=36;i++)
		res.coefficient[i]=0;
	for(ll i=0;i<=36;i++)
		for(ll j=0;j<=i;j++)
			res.coefficient[i]+=x.coefficient[j]*y.coefficient[i-j];
	return res;
}
int main()
{
	Peter.init();
	Peter.coefficient[0]=1;
	polynomial id;
	id.init();
	for(ll i=1;i<=4;i++)
		id.coefficient[i]=1;
	for(ll i=1;i<=9;i++)
		Peter=mult(Peter,id);
	double sum1=0;
	for(ll i=1;i<=36;i++)
		sum1+=Peter.coefficient[i];
	Colin.init();
	Colin.coefficient[0]=1;
	id.init();
	for(ll i=1;i<=6;i++)
		id.coefficient[i]=1;
	for(ll i=1;i<=6;i++)
		Colin=mult(Colin,id);
	double sum2=0;
	for(ll i=1;i<=36;i++)
		sum2+=Colin.coefficient[i];
	printf("%lld\n",sum2);
	ll ans=0;
	for(ll i=1;i<=36;i++)
		for(ll j=1;j<i;j++)
			ans+=Peter.coefficient[i]*Colin.coefficient[j];
	printf("%.10f\n",(double)ans/(sum1*sum2));
	return 0;
}