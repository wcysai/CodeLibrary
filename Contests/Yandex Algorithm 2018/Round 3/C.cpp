#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,h;
P a[MAXN];
vector<ll> v;
int main()
{
	scanf("%lld%lld",&n,&h);
	vector<P> odd,even;
	for(ll i=0;i<n;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		if((x+y)&1) odd.push_back(P(x-y,x-h+y+1)); else even.push_back(P(x-y,x-h+y+1));
	}
	ll ans=(ll)n*(2*h-2);
	v.clear();
	for(ll i=0;i<odd.size();i++)
	{
		v.push_back(odd[i].F);
		//printf("%lld %lld\n",odd[i].F,odd[i].S);
	}
	//puts("");
	sort(v.begin(),v.end());
	for(ll i=0;i<odd.size();i++)
		ans-=(ll)(upper_bound(v.begin(),v.end(),odd[i].S+h-1)-lower_bound(v.begin(),v.end(),odd[i].S-h+1));
	//printf("%lld\n",ans);
	v.clear();
	for(ll i=0;i<even.size();i++)
	{
		v.push_back(even[i].F);
		//printf("%lld %lld\n",even[i].F,even[i].S);
	}
	sort(v.begin(),v.end());
	for(ll i=0;i<even.size();i++)
		ans-=(ll)(upper_bound(v.begin(),v.end(),even[i].S+h-1)-lower_bound(v.begin(),v.end(),even[i].S-h+1));
	ans+=n;
	printf("%lld\n",ans);
	return 0;
}