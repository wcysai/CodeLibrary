#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 19
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
ll d[MAXN];
int st[MAXLOGN+1][4*MAXN],u[MAXN],v[MAXN];
vector<int> G[MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN],sum[MAXN];
int save[MAXN];
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
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
int par[MAXN];
ll ans[MAXN];
void dfs2(int v,int p){
    for(auto to:G[v]){
        if(to==p) continue;
        sum[to]+=sum[v];
        dfs2(to,v);
    }
}
bool solve(){
    for(int i=1;i<=n-1;i++) par[i+1]=(d[i]&1);
    for(int i=2;i<=n;i++) par[i]^=par[i-1];
    sum[1]=0;
    for(int i=0;i<n-1;i++){
        int son=(depth[id[u[i]]]<depth[id[v[i]]]?v[i]:u[i]);
        if(par[u[i]]!=par[v[i]]) sum[son]=1; else sum[son]=0;
    }
    dfs2(1,0);
    for(int i=1;i<=n-1;i++){
        int val=sum[i]+sum[i+1]-2*sum[save[i]];
        assert(val>=0);
        if(val>d[i]) return false;
        d[i]-=val; d[i]>>=1;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(v[i]); G[v[i]].push_back(u[i]);
    }
    init(n);
    for(int i=1;i<=n-1;i++) save[i]=lca(i,i+1);
    for(int i=1;i<=n-1;i++) scanf("%lld",&d[i]);
    bool f=true;
    for(int j=0;j<40;j++){
        if(!solve()) {f=false; break;}
        for(int i=0;i<n-1;i++){
            int son=(depth[id[u[i]]]<depth[id[v[i]]]?v[i]:u[i]);
            if(par[u[i]]!=par[v[i]]) ans[i]+=(1LL<<j); 
        }
    }
    for(int i=0;i<n-1;i++) if(!ans[i]) f=false;
    if(!f) puts("-1");
    else{
        for(int i=0;i<n-1;i++) printf("%lld\n",ans[i]);
    }
    return 0;
}
