#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN],b[MAXN];
int main()
{
	scanf("%lld%lld",&n,&m);
	ll s1=0,s2=0;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s1+=a[i];
	}
	ll maxx=-1;
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
		maxx=max(b[i],maxx);
		s2+=b[i];
	}
	ll maxi=-1,l=-1,r=-1;
	ll ans=s1*INF;
	for(ll i=1;i<=n;i++)
	{
		if(a[i]>maxi)
		{
			maxi=a[i];
			l=r=i;
		}
		else if(a[i]==maxi)
		{
			r=i;
		}
	}
	ans+=(m-1)*maxi*INF;
	ans+=s2;
	ans+=(l-1)*b[1]+(n-r)*b[m];
	ans+=(r-l)*maxx;
	printf("%lld\n",ans);
	return 0;
}