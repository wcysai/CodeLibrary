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
#define MAXV 100030
#define MAXQ 100030
#define MAXLOGV 20
using namespace std;
struct edge{int id,to,cost;};
int n,q,s;
int a[MAXV],b[MAXV],w[MAXV];
int type[MAXQ];
int x[MAXQ],t[MAXQ];
int st[MAXLOGV][MAXV*2];
int pre[MAXV*2];
vector<edge> G[MAXV];
int root;
int vs[MAXV*2-1];
int depth[MAXV*2-1];
int id[MAXV];
int es[MAXV*2];
int bit[MAXV*2];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=(n-1)*2)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<G[v].size();i++)
    {
        edge &e=G[v][i];
        if(e.to!=p)
        {
            add(k,e.cost);
            es[e.id*2]=k;
            dfs(e.to,v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
            add(k,-e.cost);
            es[e.id*2+1]=k;
        }
    }
}
int getMin(int x, int y)
{
    return depth[x] < depth[y] ? x : y;
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
    memset(bit,0,sizeof(bit));
    int k=0;
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
void solve()
{
    root=n/2;
    for(int i=0;i<n-1;i++)
    {
        G[a[i]-1].push_back((edge){i,b[i]-1,w[i]});
        G[b[i]-1].push_back((edge){i,a[i]-1,w[i]});
    }
    init(n);
    int v=s-1;
    for(int i=0;i<q;i++)
    {
        if(type[i]==0)
        {
            int u=x[i]-1;
            int p=lca(v,u);
            printf("%d\n",sum(id[v])+sum(id[u])-sum(id[p])*2);
            v=u;
        }
        else
        {
            int k=x[i]-1;
            add(es[k*2],t[i]-w[k]);
            add(es[k*2+1],w[k]-t[i]);
            w[k]=t[i];
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&q,&s);
    for(int i=0;i<n-1;i++)
        scanf("%d%d%d",&a[i],&b[i],&w[i]);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&type[i],&x[i]);
        if(type[i]==1) scanf("%d",&t[i]);
    }
    solve();
    return 0;
}
