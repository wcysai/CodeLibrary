#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],dep,now;
bool f;
bool dfs(int cnt)
{
	if(a[cnt]<<(dep-cnt)<now) return false;
	if(f) return true;
	if(a[cnt]==now) return true;
	for(int i=0;i<=cnt;i++)
	{
		a[cnt+1]=a[cnt]+a[i];
		if(dfs(cnt+1)) return true;
	}
	return false;
}
int main()
{
	int ans=0;
	for(now=1;now<=200;now++)
	{
		a[0]=1;dep=0;
		while(!dfs(0)) dep++;
		printf("%d %d\n",now,dep);
		ans+=dep;
	}
	printf("%d\n",ans);
	return 0;
}