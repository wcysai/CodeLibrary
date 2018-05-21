#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXV 100005
#define MAXLOGV 20
using namespace std;
vector<int> G[MAXV];
int root;
int parent[MAXLOGV][MAXV];
int max_up[MAXLOGV][MAXV];
int min_up[MAXLOGV][MAXV];
int maxmin_up[MAXLOGV][MAXV];
int maxmin_down[MAXLOGV][MAXV];
int depth[MAXV];
int a[MAXV];
int n,q;
void dfs(int v,int p,int d)
{
    parent[0][v]=p;
    if(p==-1)
    {
        max_up[0][v]=min_up[0][v]=a[v];
        maxmin_up[0][v]=maxmin_down[0][v]=0;
    }
    else
    {
        max_up[0][v]=max(a[v],a[p]);
        min_up[0][v]=min(a[v],a[p]);
        maxmin_up[0][v]=max(0,a[p]-a[v]);
        maxmin_down[0][v]=max(0,a[v]-a[p]);
    }
    depth[v]=d;
    for(int i=0;i<G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init_data(int V)
{
    for(int k=0;k+1<MAXLOGV;k++)
    {
        for(int v=0;v<V;v++)
        {
            if(parent[k][v]<0) max_up[k+1][v]=max_up[k][v]; else max_up[k+1][v]=max(max_up[k][v],max_up[k][parent[k][v]]);
            if(parent[k][v]<0) min_up[k+1][v]=min_up[k][v]; else min_up[k+1][v]=min(min_up[k][v],min_up[k][parent[k][v]]);
            if(parent[k][v]<0) maxmin_up[k+1][v]=maxmin_up[k][v];
            else maxmin_up[k+1][v]=max(max(maxmin_up[k][v],maxmin_up[k][parent[k][v]]),max_up[k][parent[k][v]]-min_up[k][v]);
            if(parent[k][v]<0) maxmin_down[k+1][v]=maxmin_down[k][v];
            else maxmin_down[k+1][v]=max(max(maxmin_down[k][v],maxmin_down[k][parent[k][v]]),max_up[k][v]-min_up[k][parent[k][v]]);
        }
    }
}
void init(int V)
{
    dfs(root,-1,0);
    for(int k=0;k+1<MAXLOGV;k++)
    {
        for(int v=0;v<V;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
    init_data(V);
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
int compute(int u,int v)
{
    int p=lca(u,v);
    int ans1=0,up=a[u];
    for(int k=0;k<MAXLOGV;k++)
        if((depth[u]-depth[p])>>k&1)
        {
            ans1=max(max_up[k][u]-up,max(ans1,maxmin_up[k][u]));
            up=min(up,min_up[k][u]);
            u=parent[k][u];
        }
    int ans2=0,down=a[v];
    for(int k=0;k<MAXLOGV;k++)
        if((depth[v]-depth[p])>>k&1)
        {
            ans2=max(down-min_up[k][v],max(ans2,maxmin_down[k][v]));
            down=max(down,max_up[k][v]);
            v=parent[k][v];
        }
    return max(max(ans1,ans2),down-up);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    root=0;
    init(n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",compute(x-1,y-1));
    }
    return 0;
}

