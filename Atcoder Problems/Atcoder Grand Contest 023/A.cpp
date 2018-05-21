#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
map<ll,ll> mp;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ll ans=0,s=0;
	for(ll i=1;i<=n;i++)
	{
		s+=a[i];
		if(mp.find(s)==mp.end()) mp[s]=1;
		else {ans+=mp[s]; mp[s]++;}
		if(s==0) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}