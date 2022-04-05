#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],cnt[MAXN];
int p10[10];
int main()
{
	p10[0]=1;
	for(int i=1;i<=5;i++) p10[i]=10*p10[i-1];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=0;i<=5;i++)
		for(int j=0;j<1000000;j++)
			if((j/p10[i])%10) cnt[j]+=cnt[j-p10[i]];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=cnt[999999-a[i]];
		bool f=true;
		for(int j=0;j<=5;j++) if(((a[i]/p10[j])%10)>=5) f=false;
		if(f) ans--;
	}
	printf("%lld\n",ans/2);
	return 0;
}