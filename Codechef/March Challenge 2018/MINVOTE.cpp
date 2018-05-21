#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,a[MAXN],sum[MAXN],ans[MAXN];
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		memset(sum,0,sizeof(sum));
		for(ll i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
		memset(ans,0,sizeof(ans));
		for(ll i=2;i<=n;i++)
		{
			ll l=0,r=i-1;
			while(r-l>1)
			{
				ll mid=(l+r)/2;
				if(a[i]>=sum[i-1]-sum[mid]) r=mid; else l=mid;
			}
			ans[r]+=1;
			ans[i]-=1;
		}
		for(ll i=n-1;i>=1;i--)
		{
			ll l=i+1,r=n+1;
			while(r-l>1)
			{
				ll mid=(l+r)/2;
				if(a[i]>=sum[mid-1]-sum[i]) l=mid; else r=mid;
			}
			ans[i+1]+=1;
			ans[r]-=1;
		}
		for(ll i=1;i<=n;i++)
			ans[i]+=ans[i-1];
		for(ll i=1;i<=n;i++)
			printf("%lld ",ans[i]);
		puts("");
	}
	return 0;
}