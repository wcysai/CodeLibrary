#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],f[MAXN],cnt[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		for(int i=0;i<(1<<20);i++)
			f[i]=cnt[i];
		for(int i=0;i<20;i++) 
		{
			for(int mask=0;mask<(1<<20);mask++)
				if(mask&(1<<i))
					f[mask]+=f[mask^(1<<i)];
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{ 
			ans+=f[(1<<20)-1-a[i]];
			cnt[a[i]]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}