#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 22
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN],rG[MAXN],dt[MAXN],bucket[MAXN];
int sdom[MAXN],idom[MAXN],arr[MAXN],rev[MAXN],par[MAXN],dsu[MAXN],label[MAXN],lb[MAXN],rb[MAXN];
P E[MAXN];
int n,m,t;
void dfs1(int v)
{
    lb[v]=++t;
    for(int i=0;i<dt[v].size();i++)
        dfs1(dt[v][i]);
    rb[v]=t;
}
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
		int to=G[v][i];
		if(!arr[to]) dfs(to),par[arr[to]]=arr[v];
		rG[arr[to]].push_back(arr[v]);
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			rG[i].clear();
			dt[i].clear();
			bucket[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			E[i].F=u;E[i].S=v;
			G[u].push_back(v);
		}
		for(int i=1;i<=n;i++)
			sdom[i]=i,idom[i]=0,label[i]=i,dsu[i]=i,arr[i]=0,rev[i]=0; 
		t=0;dfs(1);n=t;
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
		}
		for(int i=2;i<=n;i++)
		{
			if(idom[i]!=-1) dt[idom[i]].push_back(i);
		}
		idom[1]=1;
		vector<int> ans;
		ans.clear();
		memset(lb,0,sizeof(lb));
		memset(rb,0,sizeof(rb));
		t=0;dfs1(1);
		for(int i=1;i<=m;i++)
		{			
			if(idom[arr[E[i].F]]==0||idom[arr[E[i].S]]==0) continue;
			if(lb[arr[E[i].S]]<=lb[arr[E[i].F]]&&rb[arr[E[i].S]]>=rb[arr[E[i].F]]) continue;
			ans.push_back(i);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
		puts(""); 
	}
	return 0;
}