#include<bits/stdc++.h>
#define MAXN 20
#define MAXM 400
#define INF 1000000000
using namespace std;
int t,n,m,min_res;
bool valid[MAXN];
vector<int> G[MAXN];
int color[MAXN];
bool dfs_visit(int v)
{
	color[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(!valid[to]) continue;
		if(color[to]==1) return false;
		if(color[to]==0) if(!dfs_visit(to)) return false;
	}
	color[v]=2;
	return true;
}
bool dfs()
{
	memset(color,0,sizeof(color));
	for(int i=0;i<n;i++)
		if(valid[i]&&(color[i]==0)&&(!dfs_visit(i))) return false; 
	return true;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			G[i].clear();
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			G[x-1].push_back(y-1);
		}
		int ans=INF;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				if((i>>j)&1) {cnt++; valid[j]=false;} 
				else valid[j]=true;
			}
			if(cnt>=ans) continue;
			if(dfs()) ans=cnt;
		}
		printf("%d\n",ans+n);
	}
	return 0;
}