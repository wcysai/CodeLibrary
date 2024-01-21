#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],p[MAXN],r[MAXN];
vector<int> G[MAXN];
vector<int> T[MAXN];
bool valid[MAXN];
int st[MAXLOGN+1][4*MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
void dfs(int v,int p,int d,int &k){
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++){
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
int getMin(int x, int y){
    return depth[x]<depth[y]?x:y;
}

void rmq_init(int n){
    for(int i=1;i<=n;++i) st[0][i]=i;
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(1,0,0,k);
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
int dis(int u,int v){
    return depth[id[u]]+depth[id[v]]-2*depth[id[lca(u,v)]];
}
void init_dsu(int n){
    for(int i=1;i<=n;i++) p[i]=i;
}
int find(int x){
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}
void unite(int x,int y){
    x=find(x); y=find(y);
    if(x==y) return;
    p[x]=y;
}
bool cmp(int x,int y){
    return a[x]<a[y];
}
ll dp[MAXN];
void dfs2(int v){
    dp[v]=0;
    for(auto to:T[v]){
        dfs2(to);
        dp[v]=max(dp[v],dp[to]+dis(v,to));
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) r[i]=i;
    sort(r+1,r+n+1,cmp);
    init_dsu(n);
    init(n);
    for(int i=1;i<=n;i++){
        valid[r[i]]=true;
        for(auto to:G[r[i]]){
            if(valid[to]){
                T[r[i]].push_back(find(to));            
                unite(to,r[i]);
            }
        }
    }
    dfs2(r[n]);
    printf("%lld\n",dp[r[n]]);
    return 0;
}

