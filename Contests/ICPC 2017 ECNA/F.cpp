#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
int n;
vector<int> G[MAXN];
int sz[MAXN],p[MAXN];
bool used[MAXN];
void dfs(int x,int fa)
{
	int cnt=1;
	used[x]=true;
	p[x]=fa;
	for(int i=0;i<G[x].size();i++)
	{
		if(!used[G[x][i]])
		{
			dfs(G[x][i],x);
			cnt+=sz[G[x][i]];
		}
	}
	sz[x]=cnt;
	return;
}
int main()
{
	scanf("%d",&n);
	n++;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	memset(used,false,sizeof(used));
	dfs(0,-1);
	int res=0,t=0;
	for(int i=0;i<n;i++)
	{
		int cnt=(n-2)*(n-1),s=0;
		for(int j=0;j<G[i].size();j++)
			if(G[i][j]!=p[i]) {cnt-=sz[G[i][j]]*(sz[G[i][j]]-1); s+=sz[G[i][j]];}
		int num=n-s-1;
		cnt-=num*(num-1);
		if(cnt>res)
		{
			res=cnt;
			t=i;
		}
	}
	res=res/2;
	printf("%d ",res);
	int max1=0,max2=0,s=0;
	for(int i=0;i<G[t].size();i++)
	{
		if(G[t][i]!=p[t])
		{
			s+=sz[G[t][i]];
			if(sz[G[t][i]]>max1)
			{
				max2=max1;
				max1=sz[G[t][i]];
			}
			else if(sz[G[t][i]]>max2) max2=sz[G[t][i]];
		}
	}
	if(n-s-1>max1)
	{
		max2=max1;
		max1=n-s-1;
	}
	else if(n-s-1>max2) max2=n-s-1;
	printf("%d\n",res-max1*max2);
	return 0;
}