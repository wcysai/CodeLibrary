#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
bool is_sqr(ll x)
{
	ll s=(ll)sqrt(x);
	return s*s==x;
}
int main()
{
	ll ans=1000000000000;
	for(ll n=2;n<=10000;n++)
	{
		for(ll m=1;m<n;m++)
		{
			if((m&1)&&(n&1)) continue;
			if(gcd(m,n)!=1) continue;
			for(ll multiple=1;multiple<=1000;multiple++)
			{
				ll a=multiple*(m*m-n*n);
				ll b=2*multiple*m*n;
				ll lb=(ll)sqrt(a*a+2*b*b-1)+1;
				if((lb&1)!=(a&1)) lb++;
				for(ll c=lb;c<=100000;c+=2)
				{
					if(c==0) continue;
					if(!is_sqr(c*c-b*b)) continue;
					if(!is_sqr(c*c-b*b-a*a)) continue;
					printf("%I64d %I64d %I64d\n",(a*a+c*c)/2,(c*c-a*a)/2,(c*c-a*a)/2-b*b);
					printf("%I64d\n",c*c*3/2-a*a/2-b*b);
					ans=min(ans,c*c*3/2-a*a/2-b*b);
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}