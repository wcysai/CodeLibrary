#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int p[MAXN];
bool vis[MAXN];
set<int> sa,sb;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sa.insert(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		sb.insert(b[i]);
	}
	if(sa!=sb) {puts("No"); return 0;}
	if(sa.size()<n) {puts("Yes"); return 0;}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(b[j]==a[i]) p[i]=j;
	memset(vis,false,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			int now=i;
			while(!vis[now])
			{
				vis[now]=true;
				now=p[now];
			}
		}
	}
	if((n-cnt)&1) puts("No"); else puts("Yes");
	return 0;
}