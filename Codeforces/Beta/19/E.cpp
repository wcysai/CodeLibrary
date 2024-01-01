#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
int r[MAXN],p[MAXN],faid[MAXN];
int u[MAXN],v[MAXN];
int f[MAXN],fa[MAXN],sum[2][MAXN];
bool isroot[MAXN];
void init_dsu(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
vector<int> G[MAXN];
vector<int> tree,nontree,err,nonerr,ans;
int st[MAXLOGN+1][4*MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
int color[MAXN];
void dfs(int v,int p,int d,int &k,int c)
{
    color[v]=c; fa[v]=p;
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k,-c);
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
    for(int i=1;i<=n;i++) if(!color[i]) dfs(i,0,0,k,1);
    rmq_init(V*2);
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
    return depth[id[u]]+depth[id[v]]-2*depth[id[lca(u,v)]];
}
void add_chain(int u,int v,int type){
    int l=lca(u,v);
    sum[type][u]++; sum[type][v]++; sum[type][l]-=2;
}
bool vis[MAXN];
void accumulate(int v,int p){
    vis[v]=true;
    for(auto to:G[v]){
        if(to==p) continue;
        accumulate(to,v);
        for(int i=0;i<2;i++) sum[i][v]+=sum[i][to];
    }
}
void accumulate_all(){
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[i]) 
            accumulate(i,0);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init_dsu(n);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
        if(same(u[i],v[i])) nontree.push_back(i);
        else{
            G[u[i]].push_back(v[i]);
            G[v[i]].push_back(u[i]);
            tree.push_back(i);
            unite(u[i],v[i]);
        }
    }
    init(n);
    for(auto x:nontree){
        if(color[u[x]]==color[v[x]]) {err.push_back(x); add_chain(u[x],v[x],1);}
        else {nonerr.push_back(x); add_chain(u[x],v[x],0);}
    }
    for(auto x:tree){
        if(fa[u[x]]==v[x]) faid[u[x]]=x; else faid[v[x]]=x;
    }
    if(!err.size()){
        printf("%d\n",m);
        for(int i=1;i<=m;i++) printf("%d ",i);
        printf("\n");
        return 0;
    }
    if(err.size()==1) ans.push_back(err[0]);
    accumulate_all();
    for(int i=1;i<=n;i++){
        if(fa[i]){
            if(sum[0][i]==0&&sum[1][i]==(int)err.size()) ans.push_back(faid[i]);
        }
    }
    printf("%d\n",(int)ans.size());
    sort(ans.begin(),ans.end());
    for(auto x:ans) printf("%d ",x);
    printf("\n");
    return 0;
}

