#include<bits/stdc++.h>
#define MAXN 200005
#define INF 4000000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k;
P a[MAXN];
ll abx(ll x){return max(-x,x);}
ll area(P x,P y,P z)
{
	ll x1=x.F-y.F,y1=x.S-y.S,x2=x.F-z.F,y2=x.S-z.S;
	return abx(x1*y2-y1*x2);
}
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
		scanf("%I64d%I64d",&a[i].F,&a[i].S);
	a[n].F=a[0].F;
	a[n].S=a[0].S;
	a[n+1].F=a[1].F;
	a[n+1].S=a[1].S;
	ll ans=INF;
	for(ll i=0;i<n;i++)
		ans=min(ans,area(a[i],a[i+1],a[i+2]));
	printf("%I64d\n",ans);
	return 0;
}
