#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int cnt[31],maxi[31];
int main()
{
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
		for(int j=0;j<30;j++) if(a[i]&(1<<j)) cnt[j]++;
	}
	for(int i=1;i<=n;i++)
	{
		ll res=0;
		for(int j=0;j<30;j++) if(a[i]&(1<<j)) res+=1LL*(1<<j)*(n-cnt[j]); else res+=1LL*(1<<j)*cnt[j];
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}