#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int main()
{
	scanf("%d",&n);
	int maxi=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		maxi=max(maxi,a[i]);
	}
	ll ans=0;
	for(int i=2;i<=n;i++) if(a[i]>=a[i-1]) ans+=(a[i]-a[i-1]);
	if(a[1]>=a[n]) ans+=(a[1]-a[n]);
	ans=max(ans,1LL*maxi);
	printf("%lld\n",ans);
	return 0;
}