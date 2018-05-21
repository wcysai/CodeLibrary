#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<assert.h>
#include<queue>
#include<stack>
#include<deque>
#define MAXV 505
#define MAXE 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,m,V,E;
vector<int> G[MAXV];
int match[MAXV];
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
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;v++)
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
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		scanf("%d%d",&m,&E);
		V=n+m;
		for(int i=0;i<V;i++)
			G[i].clear();
		for(int i=0;i<E;i++)
		{
			int x,u,v;
			scanf("%d%d%d",&x,&u,&v);
			add_edge(u-1,v+n-1);
		}
		printf("%d\n",bipartite_matching());
	}
	return 0;
}