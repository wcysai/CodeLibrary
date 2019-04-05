#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,mcnt,t,tot;
int U[MAXN],V[MAXN],st[MAXN];
int dfn[MAXN],low[MAXN];
vector<int> G[MAXN];
bool isbridge[MAXN];
bool used[MAXN];
vector<int> ans;
void add_edge(int u,int v)
{
    U[++mcnt]=u;V[mcnt]=v;
    G[u].push_back(mcnt);G[v].push_back(mcnt);
}
int adj(int u,int e)
{
    return U[e]==u?V[e]:U[e];
}
void dfs(int v,int edge)
{
    dfn[v]=low[v]=++tot;
    st[t++]=v;
    used[edge]=true;
    for(auto e:G[v])
    {
        int to=adj(v,e);
        if(used[e]) continue;
        if(!dfn[to])
        {
            dfs(to,e);
            low[v]=min(low[v],low[to]);
        }
        else low[v]=min(low[v],dfn[to]);
    }
    if(low[v]==dfn[v]&&edge!=-1) isbridge[edge]=true;
}
int main()
{
    freopen("bridges.in","r",stdin);
    freopen("bridges.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    memset(isbridge,false,sizeof(isbridge));
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,-1);
    for(int i=1;i<=m;i++) if(isbridge[i]) ans.push_back(i);
    printf("%d\n",(int)ans.size());
    for(auto v:ans) printf("%d ",v);
    puts("");
    return 0;
}
