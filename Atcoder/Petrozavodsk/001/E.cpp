#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n;
bool f=false;
vector<int> G[MAXN];
int fa[MAXN],deg[MAXN];
void dfs(int v,int p)
{
	fa[v]=p;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v);
	}
	return;
}
int find_ans(int v)
{
	int cnt=0,res=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==fa[v]) continue;
		int val=find_ans(G[v][i]);
		if(val==0) cnt++;
		res+=val;
	}
	if(cnt>0) return res+cnt-1; else return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		deg[x]++;deg[y]++;
	}
	bool f=false;
	int ans;
	for(int i=0;i<n;i++)
	{
		if(deg[i]>=3)
		{
			f=true;
			dfs(i,-1);
			ans=find_ans(i);
			break;
		}
	}
	if(!f)
	{
		printf("1\n");
		return 0;
	}
	printf("%d\n",ans);
	return 0;
}