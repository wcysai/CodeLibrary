#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll x;
ll ans[MAXN],ans2[MAXN];
ll getsqrt(ll x)
{
	ll y=(ll)sqrt(x);
	y=max(0LL,y-2);
	while((y+1)*(y+1)<=x) y++;	return y;
}
int main()
{
	ans[1]=1; ans2[1]=3;
	for(int i=2;i<=100000;i++)
	{
		ll x=getsqrt(i);
		ans[i]=ans2[x-1]+(i-x*x+1)*ans[x];
		ans2[i]=ans2[i-1]+ans[i]*(2*i+1);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&x);
		ll y=getsqrt(x);
		ll z=getsqrt(y);
		printf("%lld\n",ans2[z-1]+(y-z*z+1)*ans[z]);
	}
	return 0;
}