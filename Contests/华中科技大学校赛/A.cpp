#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,cnt;
vector<int> G[MAXN];
void dfs(int v,int p,int d)
{
	if(d==1) cnt++;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v,-d);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);G[v].push_back(u);
		}
		dfs(1,-1,1);
		if(n&1) printf("%lld\n",2LL*n*cnt*(n-cnt)); else printf("%lld\n",1LL*n*cnt*cnt+1LL*n*(n-cnt)*(n-cnt));
	}
	return 0;
}