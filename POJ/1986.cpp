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
#define MAXV 50030
#define MAXLOGV 32
using namespace std;
struct edge{int to,cost;};
int N,M,Q;
int st[MAXLOGV][MAXV*2];
vector<edge> G[MAXV];
int root;
int vs[MAXV*2-1];
int depth[MAXV*2-1];
int id[MAXV],dis[MAXV];
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<G[v].size();i++)
    {
        edge e=G[v][i];
        if(e.to!=p)
        {
            dis[e.to]=dis[v]+e.cost;
            dfs(e.to,v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
int getMin(int x, int y)
{
    return depth[x]<depth[y]?x:y;
}

void rmq_init(int n)
{
    for(int i=1;i<=n;++i) st[0][i]=i;
    for(int i=1;1<<i<=n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<i-1)]);
}
void init(int V)
{
    int k=0;
    memset(dis,0,sizeof(dis));
    dfs(root,-1,0,k);
    rmq_init(V*2-1);
}
int query(int l, int r)
{
    int k=31-__builtin_clz(r-l+1);
    return getMin(st[k][l],st[k][r-(1<<k)+1]);
}
int lca(int u,int v)
{
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v])+1)];
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        char ch;
        scanf("%d%d%d %c\n",&x,&y,&z,&ch);
        G[x-1].push_back((edge){y-1,z});
        G[y-1].push_back((edge){x-1,z});
    }
    root=0;
    init(N);
    scanf("%d",&Q);
    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        printf("%d\n",dis[x]+dis[y]-2*dis[lca(x,y)]);
    }
    return 0;
}
