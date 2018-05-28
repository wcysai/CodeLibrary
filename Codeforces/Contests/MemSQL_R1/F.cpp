#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN],num[MAXN],res[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(ll i=0;i<2*n-1;i++)
	{
		scanf("%I64d",&a[i]);
		if(a[i]>=m) a[i]=m;
	}
	for(ll i=0;i+2<2*n-1;i+=2)
		num[i]=min(m,a[i]+a[i+1]+a[i+2]);
	ll ans=0;
	for(ll i=0;i<2*n-1;i+=2)
	{
		if(i==0) 
		{
			res[i]=max(0LL,a[i]); 
		}
		else 
		{
			res[i]=max(num[i-2]-res[i-2],max(0LL,max(a[i],a[i-1]-res[i-2])));
		}
		printf("%I64d\n",res[i]);
		ans+=res[i];
	}
	printf("%I64d\n",ans);
	return 0;
}