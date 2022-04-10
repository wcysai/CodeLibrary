#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,f[MAXN],p[MAXN];
ll g[MAXN],h[MAXN];//g: no root use,h: root use
vector<int> G[MAXN];
void dfs(int v)
{
	g[v]=0; h[v]=0;
	ll s=0,mini=INF;
	for(auto to:G[v])
	{
		dfs(to);
		s+=g[to]; mini=min(mini,g[to]-h[to]);
	}
	if(mini==INF) {g[v]=f[v]; return;}
	g[v]=max(s,f[v]+s-mini);
	h[v]=s-mini;
}
int main()
{
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++) scanf("%d",&f[i]);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&p[i]);
			G[p[i]].push_back(i);
		}
		dfs(0);
		printf("Case #%d: %lld\n",t,g[0]);
	}
	return 0;
}