#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,k,a[MAXN],st[MAXN],dp[MAXN],id[MAXN];
bool cpt[MAXN],chosen[MAXN];
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		ll sum=0,tot=0;
		for(ll i=1;i<=n;i++)
		{
			if((i==1&&a[i]<a[i+1])||(i==n&&a[i]<a[i-1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
			{
				if(i==1)
				{
					tot++;
					st[tot]=a[i];
					cpt[tot]=true;
					id[i]=tot;
					sum=-a[i];
				}
				else
				{
					tot++;
					if(sum-a[i]<=0) cpt[tot]=false; else cpt[tot]=true;
					id[i]=tot;
					st[tot]=a[i];
					sum=-a[i];
				}
			}
			else {sum+=a[i]; id[i]=-1;}
		}
		dp[0]=0;
		for(ll i=1;i<=tot;i++)
			if(cpt[i]) dp[i]=dp[i-1]+st[i]; else dp[i]=max(st[i]+dp[i-2],dp[i-1]);
		ll now=tot;
		memset(chosen,false,sizeof(chosen));
		while(now>=1)
		{
			if(cpt[now]) {chosen[now]=true; now--;}
			else
			{
				if(dp[now]==st[now]+dp[now-2])
				{
					chosen[now]=true; 
					now-=2;
				}
				else 
				{
					chosen[now]=false;
					now--;
				}
			}
		}
		for(ll i=1;i<=n;i++)
			if(id[i]==-1||!chosen[id[i]]) printf("%lld ",a[i]); else printf("%lld ",-a[i]);
		puts("");
	}
	return 0;
}