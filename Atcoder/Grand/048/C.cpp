#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l,a[MAXN],b[MAXN];
int type[MAXN];
ll ans;
void solve(int l,int r)
{
	if(type[l]==1)
	{
		int now=l;
		for(int i=l;i<=r;i++)
		{
			int last=now;
			while(now<=r+1&&b[i]!=a[now]-(now-i)) now++;
			if(now>r+1) {puts("-1"); exit(0);}
			if(now!=last) ans+=now-i;
 		}
	}
	else
	{
		int now=r;
		for(int i=r;i>=l;i--)
		{
			int last=now;
			while(now>=l-1&&b[i]!=a[now]+(i-now)) now--;
			if(now<l-1) {puts("-1"); exit(0);}
			if(now!=last) ans+=i-now;
 		}
	}
}
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=2;i<=n+1;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n+1;i++) scanf("%d",&b[i]);
	a[1]=b[1]=0; a[n+2]=b[n+2]=l+1;
	n+=2;
	for(int i=1;i<=n;i++) if(a[i]==b[i]) type[i]=0; else if(a[i]<b[i]) type[i]=1; else type[i]=-1;
	for(int i=1;i<=n-1;i++)
	{
		if(type[i]==1&&type[i+1]==-1)
		{
			puts("-1");
			return 0;
		}
	}
	int t=0,last=2;
	ans=0;
	for(int i=2;i<=n;i++)
	{
		if(type[i]==0)
		{
			if(last<i)
			{
				solve(last,i-1);
			}
			last=i+1;
		}
		else if(type[i]==1&&type[i-1]==-1)
		{
			solve(last,i-1);
			last=i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}