#include<bits/stdc++.h>
#define MAXLOGN 18
#define MAXN 200005
#define INF 1000000000
#define MOD 924844033
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y;
vector<int> G[MAXN],H[MAXN];
int pa[MAXLOGN][MAXN];
int depth[MAXN];
bool good[MAXN];
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)H[v].size();i++)
        if(H[v][i]!=p) dfs(H[v][i],v,d+1);
}
void init(int V)
{
    dfs(y,-1,0);
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
vector<P> edges;
int ans=0;
void dfs2(int v,int p,int d)
{
    if(depth[v]<=d) return;
    if(good[v]) ans=INF; else ans=max(ans,2*depth[v]);
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v,d+1);
    }
}
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
        edges.push_back(P(u,v));
    }
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        H[u].push_back(v); H[v].push_back(u);
    }
    init(n);
    memset(good,false,sizeof(good));
    for(auto p:edges)
        if(dis(p.F,p.S)>=3)
            good[p.F]=good[p.S]=true;
    dfs2(x,0,0);
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}