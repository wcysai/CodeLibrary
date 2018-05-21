#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int t,n;
vector<int> G[MAXN];
int pa[MAXN],depth[MAXN],state[MAXN];
void dfs(int x,int p,int d)
{
	pa[x]=p;
	depth[x]=d;
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]==p) continue;
		dfs(G[x][i],x,d+1);
	}
	return;
}
void find_res(int x)
{
	int res=0,cnt1=0,cnt2=0;
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]==pa[x]) continue;
		find_res(G[x][i]);
		if(state[G[x][i]]==0) cnt1++; else cnt2++;
	}
	if(cnt2||cnt1&1) state[x]=-1;
	else state[x]=0; 
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			G[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			G[x-1].push_back(y-1);
			G[y-1].push_back(x-1);
		}
		bool f=false;
		for(int i=0;i<n;i++)
		{
			dfs(i,-1,0);
			memset(state,0,sizeof(state));
			find_res(i);
			if(state[i]==0)
			{
				f=true;
				break;
			}
		}
		if(f) puts("Alice"); else puts("Bob");
	}
	return 0;
}