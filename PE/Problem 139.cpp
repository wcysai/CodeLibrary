#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S seocond
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	ll ans=0;
	for(ll n=2;n<=10000;n++)
	{
		for(ll m=1;m<n;m++)
		{
			if((n&1)&&(m&1)) continue;
			if(gcd(n,m)!=1) continue;
			for(ll multiple=1;;multiple++)
			{
				ll a=multiple*(n*n-m*m);
				ll b=multiple*(2*n*m);
				ll c=multiple*(n*n+m*m);
				if(a+b+c>100000000LL) break; 
				if(c%(max(b-a,a-b))==0) ans++;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}