#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
vector<edge> G[MAXN];
vector<int> rG[MAXN],dt[MAXN],bucket[MAXN],dp[MAXN];
int sdom[MAXN],idom[MAXN],arr[MAXN],rev[MAXN],par[MAXN],dsu[MAXN],label[MAXN];
int n,m,t,ans=0;
int find(int u,int x=0)
{
	if(u==dsu[u]) return x?-1:u;
	int v=find(dsu[u],x+1);
	if(v<0) return u;
	if(sdom[label[dsu[u]]]<sdom[label[u]])
		label[u]=label[dsu[u]];
	dsu[u]=v;
	return x?v:label[u];
}
void unite(int u,int v)
{
	dsu[v]=u;
}
void dfs(int v)
{
	t++;arr[v]=t;rev[t]=v;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i].to;
		if(!arr[to]) dfs(to),par[arr[to]]=arr[to];
		rG[arr[to]].push_back(arr[v]);
	}
}
int dfs2(int v)
{
	for(int i=0;i<dt[v].size();i++)
		dfs
}
int main()
{
	scanf("%d%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back((edge){v,w});
	}
	for(int i=1;i<=n;i++)
		sdom[i]=i,idom[i]=i,label[i]=i,dsu[i]=i; 
	dfs(1);
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<rG[i].size();j++)
			sdom[i]=min(sdom[i],sdom[find(rG[i][j])]);
		if(i>1) bucket[sdom[i]].push_back(i);
		for(int j=0;j<bucket[i].size();j++)
		{
			int w=bucket[i][j],v=find(w);
			if(sdom[v]==sdom[w]) idom[w]=sdom[w];
			else idom[w]=v;
		}
		if(i>1) unite(par[i],i);
	}
	for(int i=2;i<=n;i++)
	{
		if(idom[i]!=sdom[i]) idom[i]=idom[idom[i]];
		dt[rev[idom[i]]].push_back(rev[i]);
		printf("%d %d\n",rev[i],rev[idom[i]]);
	}
	return 0;
}