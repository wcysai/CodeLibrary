#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000
using namespace std;
typedef long long ll;
ll t,n,a[MAXN][MAXN];
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
				scanf("%lld",&a[i][j]);
			sort(a[i],a[i]+n);
		}
		ll s=0,k=INF;
		bool f;
		for(ll i=n-1;i>=0;i--)
		{
			f=false;
			for(ll j=n-1;j>=0;j--)
			{
				if(a[i][j]<k)
				{
					s+=a[i][j];
					k=a[i][j];
					f=true;
					break;
				}
			}
			if(!f) break;
		}
		if(f) printf("%lld\n",s); else printf("-1\n");
	}
	return 0;
}