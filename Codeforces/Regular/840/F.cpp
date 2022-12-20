#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define MAXLOGN 20
#define MAXM 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,tot,t,bcc_cnt,mcnt;
vector<int> G[MAXN],bcc[MAXN];
int dfn[MAXN],low[MAXN],bccno[MAXN];
int U[MAXM],V[MAXM];
int save[MAXM];
bool isbridge[MAXM];
vector<int> tree[MAXN];
//bridge tree:
//edge-biconnected components are connected by bridges
void add_edge(int u,int v)
{
    U[++mcnt]=u;V[mcnt]=v;
    G[u].push_back(mcnt);G[v].push_back(mcnt);
}
int adj(int u,int e)
{
    return U[e]==u?V[e]:U[e];
}
void dfs1(int v,int edge)
{
    dfn[v]=low[v]=++tot;
    for(auto e:G[v])
    {
        if(e==edge) continue;
        int to=adj(v,e);
        if(!dfn[to])
        {
            dfs1(to,e);
            low[v]=min(low[v],low[to]);
        }
        else low[v]=min(low[v],dfn[to]);
    }
    if(low[v]==dfn[v]&&edge!=-1) isbridge[edge]=true;
}
void dfs2(int v)
{
    dfn[v]=1;
    bccno[v]=bcc_cnt;
    bcc[bcc_cnt].push_back(v);
    for(auto e:G[v])
    {
        int to=adj(v,e);
        if(isbridge[e]) continue;
        if(!dfn[to]) dfs2(to);
    }
}
int tarjan()
{
    bcc_cnt=tot=0;
    memset(dfn,0,sizeof(dfn));
    memset(isbridge,false,sizeof(isbridge));
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs1(i,-1);
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            bcc_cnt++;
            dfs2(i);
        }
    }
    return bcc_cnt;
}
void build_bridge_tree()
{
    tarjan();
    for(int i=1;i<=bcc_cnt;i++)
    {
        for(auto x:bcc[i])
        {
            for(auto e:G[x])
            {
                if(isbridge[e]) continue;
                save[n+i]++; 
            }
            tree[n+i].push_back(x); tree[x].push_back(n+i);
        }
    }
    for(int i=1;i<=bcc_cnt;i++) save[n+i]/=2;
    for(int i=1;i<=mcnt;i++) if(isbridge[i]) {tree[U[i]].push_back(V[i]); tree[V[i]].push_back(U[i]);}
}
int st[MAXLOGN+1][4*MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1],sum[MAXN],fa[MAXN];
int id[MAXN];
void dfs(int v,int p,int d,int s,int &k)
{
    id[v]=k; fa[v]=p;
    vs[k]=v; sum[v]=s+save[v];
    depth[k++]=d;
    for(int i=0;i<(int)tree[v].size();i++)
    {
        if(tree[v][i]!=p)
        {
            dfs(tree[v][i],v,d+1,sum[v],k);
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
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(1,0,0,0,k);
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
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
int dis(int u,int v)
{
    int l=lca(u,v);
    return sum[u]+sum[v]-sum[l]-sum[fa[l]];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    build_bridge_tree();
    init(n+bcc_cnt);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",dis(u,v));
    }
    return 0;
}
