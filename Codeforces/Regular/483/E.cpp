#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 20
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
vector<int> G[MAXN];
int pa[MAXLOGN][MAXN];
int low[MAXLOGN][MAXN];
int depth[MAXN];
int n,m,q;
int u[MAXN],v[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,0,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void dfs2(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
        if(depth[low[0][to]]<depth[low[0][v]]) low[0][v]=low[0][to];
    }
}
P get_res(int from,int to)
{
    int cnt=0,cur=from;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(depth[low[k][cur]]<depth[to])
        {
            cur=low[k][cur];
            cnt+=(1<<k);
        }
    }
    return P(cur,cnt);
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        add_edge(i,p);
    }
    init(n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++) low[0][i]=i;
    for(int i=1;i<=m;i++) 
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int l=lca(u,v);
        if(depth[low[0][u]]>depth[l]) low[0][u]=l;
        if(depth[low[0][v]]>depth[l]) low[0][v]=l;
    }
    dfs2(1,0);
    for(int k=0;k+1<MAXLOGN;k++)
        for(int v=1;v<=n;v++)
            low[k+1][v]=low[k][low[k][v]];
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int l=lca(u,v);
        
    }
    return 0;
}
