#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
ll t,n,k,a[MAXN],sum[MAXN];
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		ll maxpre=-INF,maxsuf=-INF,maxans=-INF,maxhere=-INF;
		for(ll i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sum[0]=0;
		for(ll i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+a[i];
			if(maxhere<=0) maxhere=a[i]; else maxhere+=a[i];
			maxans=max(maxans,maxhere);
			maxpre=max(maxpre,sum[i]);
		}
		if(maxans<0)
		{
			ll ans=-INF;
			for(ll i=1;i<=n;i++)
				ans=max(ans,a[i]);
			printf("%lld\n",ans);
			continue;
		}
		ll s=0;
		for(ll i=n;i>=1;i--)
		{
			s=s+a[i];
			maxsuf=max(maxsuf,s);
		}
		if(k==1) printf("%lld\n",maxans);
		else if(sum[n]>0) printf("%lld\n",max(maxans+(k-1)*sum[n],maxsuf+(k-2)*sum[n]+maxpre));
		else printf("%lld\n",max(maxans,maxsuf+maxpre));
	}
	return 0;
}