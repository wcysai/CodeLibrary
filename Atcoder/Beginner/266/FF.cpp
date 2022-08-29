#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 400005
#define MAXM 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot,t,bcc_cnt,mcnt;
vector<int> G[MAXN],bcc[MAXN];
int sta[MAXN],dfn[MAXN],low[MAXN],bccno[MAXN];
bool art[MAXN];
vector<int> tree[MAXN];
int id[MAXN];
int N,cyc;
//block-cut tree:
//vertex-biconnected components are connected by their shared articulation point
void dfs(int v,int p,int &tot)
{
    dfn[v]=low[v]=++tot;
    sta[t++]=v;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(!dfn[to])
        {
            dfs(to,v,tot);
            low[v]=min(low[v],low[to]);
            if(low[to]>=dfn[v])
            {
                art[v]=(dfn[v]>1||dfn[to]>2);
                bcc_cnt++;
                bcc[bcc_cnt].push_back(v); bccno[v]=bcc_cnt;
                while(bcc[bcc_cnt].back()!=to)
                {
                    bccno[sta[t-1]]=bcc_cnt;
                    bcc[bcc_cnt].push_back(sta[t-1]),t--;
                }
            }
        }
        else low[v]=min(low[v],dfn[to]);
    }
}
int tarjan()
{
    bcc_cnt=t=0;
    memset(dfn,0,sizeof(dfn));
    memset(art,false,sizeof(art));
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,-1,tot=0);
    return bcc_cnt;
}
void build_block_cut_tree()
{
    tarjan();N=0;
    for(int i=1;i<=n;i++) if(art[i]) id[i]=++N;
    for(int i=1;i<=bcc_cnt;i++)
    {
        N++;
        if(bcc[i].size()>2) cyc=N;
        for(auto v:bcc[i])
        {
            if(!art[v]) id[v]=N;
            else
            {
                tree[id[v]].push_back(N);
                tree[N].push_back(id[v]);
            }
        }
    }
}
int st[MAXLOGN+1][4*MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int tid[MAXN];
void dfs_tree(int v,int p,int d,int &k)
{
    tid[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<(int)tree[v].size();i++)
    {
        if(tree[v][i]!=p)
        {
            dfs_tree(tree[v][i],v,d+1,k);
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
    dfs_tree(1,0,0,k);
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
    return vs[query(min(tid[u],tid[v]),max(tid[u],tid[v]))];
}
int dis(int u,int v)
{
    return depth[tid[u]]+depth[tid[v]]-2*depth[tid[lca(u,v)]];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    build_block_cut_tree();
    init(N);
    assert(cyc!=-1);
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x=id[x]; y=id[y];
        if(dis(x,y)==dis(x,cyc)+dis(y,cyc)) puts("No"); else puts("Yes");
    }
    return 0;
}

