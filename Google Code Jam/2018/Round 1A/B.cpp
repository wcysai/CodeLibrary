#include<bits/stdc++.h>
#define MAXN 55005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,r,b,c;
ll m[MAXN],s[MAXN],p[MAXN],a[MAXN];
bool C(ll x)
{
	ll cnt=0;
	for(ll i=0;i<c;i++)
		if(x>p[i]) a[i]=(min(m[i],(x-p[i])/s[i])); else a[i]=0;
	sort(a,a+c);
	for(ll i=c-1;i>=c-r;i--)
		cnt+=a[i];
	return (cnt>=b);
}
int main()
{
	scanf("%lld",&t);
	ll kase=0;
	while(t--)
	{
		kase++;
		scanf("%lld%lld%lld",&r,&b,&c);
		for(ll i=0;i<c;i++)
			scanf("%lld%lld%lld",&m[i],&s[i],&p[i]);
		ll lb=0,rb=2LL*INF*INF;
		while(rb-lb>1)
		{
			ll mid=(lb+rb)/2;
			if(C(mid)) rb=mid; else lb=mid;
		}
		printf("Case #%lld: %lld\n",kase,rb);
	}
	return 0;
}