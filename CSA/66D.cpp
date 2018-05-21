#include<bits/stdc++.h>
#define MAXN 1005
#define MAXV 2005
using namespace std;
int n;
int a[MAXN][MAXN];
vector<int> G[MAXV];
int match[MAXV],rmatch[MAXV];
bool used[MAXV];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
// }
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<n;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]) add_edge(i,n+j);
		}
	int p=bipartite_matching();
	if(p!=n)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<n;i++)
		match[i]-=n;
	for(int i=0;i<n;i++)
		rmatch[match[i]]=i;
	for(int i=0;i<n;i++)
	{
		if(match[i]!=i)
		{
			int x=rmatch[i];
			printf("R %d %d\n",i+1,x+1);
			swap(match[i],match[x]);
			rmatch[i]=i;
			rmatch[match[x]]=x;
		}
	}
	return 0;
}