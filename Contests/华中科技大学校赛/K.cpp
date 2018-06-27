#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,d[MAXN];
bool C(ll x)
{
	ll cnt=0,ans=0;
	for(ll i=1;i<=n-1;i++)
	{
		if(d[i]>x) return false;
		cnt+=d[i];
		if(cnt>x) {ans++; cnt=d[i];}
	}
	ans++;
	return ans<=k;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	if(n==1) {puts("0"); return 0;}
	for(ll i=1;i<=n-1;i++) scanf("%lld",&d[i]);
	ll l=0,r=10000000000;
	while(r-l>1)
	{
		ll mid=(l+r)/2;
		if(C(mid)) r=mid; else l=mid;
	}
	printf("%lld\n",r);
	return 0;
}