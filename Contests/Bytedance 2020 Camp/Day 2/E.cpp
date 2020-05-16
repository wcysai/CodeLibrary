#include<bits/stdc++.h>
#define MAXV 1000005
#define MAXN 1000005
#define INF 1000000000
#define MAXLOGV 21
using namespace std;
int cnt,k,a[MAXN];
struct edge
{
    int to,cost;
};
vector<edge> G[MAXV];
int parent[MAXLOGV][MAXV];
int depth[MAXV],dfn[MAXV],dis[MAXV],st[MAXV];
int n,q,tot;
void add_edge(int from,int to)
{
    cnt++;
}
bool cmp(int x,int y)
{
    return dfn[x]<dfn[y];
}
void dfs(int v,int p,int d,int minx)
{
    dfn[v]=++tot;
    dis[v]=minx;
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i].to!=p) dfs(G[v][i].to,v,d+1,min(minx,G[v][i].cost));
}
void init(int V)
{
    dfs(1,-1,0,INF);
    for(int k=0;k+1<MAXLOGV;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAXLOGV;k++)
    {
        if((depth[v]-depth[u])>>k&1)
            v=parent[k][v];
    }
    if(u==v) return u;
    for(int k=MAXLOGV-1;k>=0;k--)
    {
        if(parent[k][u]!=parent[k][v])
        {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
stack<int> stk;
void solve() 
{
	sort(a, a + k, cmp);
	int m = k;
	for (int j = 1; j < m; ++j)
		a[k++] = lca(a[j - 1], a[j]);
	sort(a, a + k, cmp);
	k = unique(a, a + k) - a;
	stk.push(a[0]);
	for (int j = 1; j < k; ++j) 
    {
		int u = lca(stk.top(), a[j]);
		while (depth[stk.top()] > depth[u]) stk.pop();
		assert(stk.top() == u);
		stk.push(a[j]);
		cnt+= depth[a[j]] - depth[u];
	}
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back((edge){v,0});
        G[v].push_back((edge){u,0});
    }
    init(n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&k);
        cnt=0;
        for(int j=0;j<k;j++) scanf("%d",&a[j]);
        solve();
        printf("%d\n",cnt);
    }
    return 0;
}
