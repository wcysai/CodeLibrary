#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 21
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,a[MAXN],b[MAXN];
int cnt[MAXM][MAXM],all[MAXM],num[MAXM];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		memset(cnt,0,sizeof(cnt));
		memset(all,0,sizeof(all));
		memset(num,0,sizeof(num));
		for(int i=1;i<=N;i++) scanf("%d",&a[i]);
		for(int i=1;i<=N;i++) 
		{
			scanf("%d",&b[i]);
			for(int j=0;j<=19;j++)
				if(b[i]&(1<<j)) all[j]++;
			for(int j=19;j>=0;j--)
			{
				if(b[i]&(1<<j))
				{
					num[j]++;
					for(int k=0;k<=19;k++) 
					{
						if(b[i]&(1<<k)) cnt[j][k]++;
					}
					break;
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<=19;j++)
				if(a[i]&(1<<j)) ans+=1LL*(N-all[j])*(1<<j); else ans+=1LL*all[j]*(1<<j);
			for(int j=19;j>=0;j--)
			{
				if(a[i]&(1<<j))
				{
					for(int k=0;k<=19;k++) 
					{
						if(a[i]&(1<<k)) 
						{
							ans-=1LL*(num[j]-cnt[j][k])*(1<<k);
							ans+=1LL*cnt[j][k]*(1<<k);
						}
						else
						{
							ans-=1LL*cnt[j][k]*(1<<k);
						}
					}
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}