#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN],rG[MAXN],dt[MAXN],bucket[MAXN];
int sdom[MAXN],idom[MAXN],arr[MAXN],rev[MAXN],par[MAXN],dsu[MAXN],label[MAXN],ans[MAXN];
int n,m,t;
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
	label[t]=t;sdom[t]=t;dsu[t]=t;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(!arr[to]) dfs(to),par[arr[to]]=arr[v];
		rG[arr[to]].push_back(arr[v]);
	}
}
void dfs2(int v,int p,int x)
{
	ans[v]=x+v;
	for(int i=0;i<dt[v].size();i++)
	{
		if(dt[v][i]==p) continue;
		dfs2(dt[v][i],v,x+v);
	}
	return;
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=1;i<=n;i++) G[i].clear(),bucket[i].clear(),rG[i].clear(),dt[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		memset(arr,0,sizeof(arr));
		memset(rev,0,sizeof(rev));
		t=0;dfs(n);
		for(int i=t;i>=1;i--)
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
		for(int i=2;i<=t;i++)
		{
			if(idom[i]!=sdom[i]) idom[i]=idom[idom[i]];
			dt[rev[idom[i]]].push_back(rev[i]);
		}
		memset(ans,0,sizeof(ans));
		dfs2(n,-1,0);
		printf("%d",ans[1]);
		for(int i=2;i<=n;i++)
			printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}