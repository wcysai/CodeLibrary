#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
ll a[MAXN][MAXN],b[MAXN][MAXN];
ll row[MAXN],col[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j&1) row[i]+=a[i][j]; else row[i]-=a[i][j];
			if(i&1) col[j]+=a[i][j]; else col[j]-=a[i][j];
		}
	for(int i=1;i<=n;i+=2)
	{
		for(int j=1;j<=m;j+=2)
		{
			if(row[i]>0&&col[j]>0)
			{
				ll mini=min(row[i],col[j]);
				row[i]-=mini; col[j]-=mini;
				b[i][j]+=mini;
			}
			else if(row[i]<0&&col[j]<0)
			{
				ll mini=min(-row[i],-col[j]);
				row[i]+=mini; col[j]+=mini;
				b[i][j]-=mini;
			}
		}
	}
	for(int i=1;i<=n;i+=2)
	{
		for(int j=2;j<=m;j+=2)
		{
			if(row[i]<0&&col[j]>0)
			{
				ll mini=min(-row[i],col[j]);
				row[i]+=mini; col[j]-=mini;
				b[i][j]+=mini;
			}
			else if(row[i]>0&&col[j]<0)
			{
				ll mini=min(row[i],-col[j]);
				row[i]-=mini; col[j]+=mini;
				b[i][j]-=mini;
			}
		}
	}
	for(int i=2;i<=n;i+=2)
	{
		for(int j=1;j<=m;j+=2)
		{
			if(row[i]>0&&col[j]<0)
			{
				ll mini=min(row[i],-col[j]);
				row[i]-=mini; col[j]+=mini;
				b[i][j]+=mini;
			}
			else if(row[i]<0&&col[j]>0)
			{
				ll mini=min(-row[i],col[j]);
				row[i]+=mini; col[j]-=mini;
				b[i][j]-=mini;
			}
		}
	}
	for(int i=2;i<=n;i+=2)
	{
		for(int j=2;j<=m;j+=2)
		{
			if(row[i]<0&&col[j]<0)
			{
				ll mini=min(-row[i],-col[j]);
				row[i]+=mini; col[j]+=mini;
				b[i][j]+=mini;
			}
			else if(row[i]>0&&col[j]>0)
			{
				ll mini=min(row[i],col[j]);
				row[i]-=mini; col[j]-=mini;
				b[i][j]-=mini;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(row[i]!=0)
		{
			b[i][1]+=row[i];
			col[1]+=(i&1?-row[i]:row[i]);
		}
	}
	for(int i=2;i<=m;i++)
	{
		if(col[i]!=0)
		{
			b[1][i]+=col[i];
			row[1]+=(i&1?-col[i]:col[i]); 
		}
	}
	assert(row[1]==col[1]);
	b[1][1]+=row[1];
	ll s=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s+=max(-b[i][j],b[i][j]);
	printf("%lld\n",s);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%lld ",b[i][j]);
		puts("");
	}
	return 0;
}