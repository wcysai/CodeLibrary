#include<bits/stdc++.h>
#define MAXN 200005
#define MAXQ 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
ll a[MAXN];
ll w,l;
int main()
{
	scanf("%d%lld%lld",&n,&l,&w);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	a[n+1]=l;
	ll ans=0,now=0;
	for(int i=1;i<=n+1;i++)
	{
		ans+=max(0LL,(a[i]-now+(w-1))/w);
		now=max(now,a[i]+w);
	}
	printf("%lld\n",ans);
	return 0;
}