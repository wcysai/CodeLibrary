#include<bits/stdc++.h>
#define MAXV 2005
#define MAXLOGV 30
#define INF 1000000000
using namespace std;
vector<int> G[MAXV];
int root;
int parent[MAXLOGV][MAXV];
int depth[MAXV];
int t,n,m;
int a[MAXV];
void dfs(int v,int p,int d)
{
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(root,-1,0);
    for(int k=0;k+1<MAXLOGV;k++)
    {
        for(int v=0;v<V;v++)
        {
            if(parent[v][k]<0) parent[k+1][v]=-1;
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
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            G[i].clear();
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            x--,y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        init(n);
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++)
                ans=max(ans,dis(a[i]-1,a[j]-1));
        printf("%.2f\n",(double)(ans/2));
    }
    return 0;
}
