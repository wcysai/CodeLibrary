#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define MAXLOGN 12
#define MAXQ 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
vector<P> G[MAXN];
int fa[MAXN],dep[MAXN];
int mark[MAXN];
ll ans[MAXQ];
int s[MAXQ],t[MAXQ],k[MAXQ];
vector<int> save[MAXN];
namespace IO {
    const int MX = 4e7;
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
void add_edge(int u,int v,int w){
    G[u].push_back(P(v,w));
    G[v].push_back(P(u,w));
}
int st[MAXLOGN+1][4*MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
ll wt[MAXN*2-1];
int id[MAXN];
void dfs(int v,int p,int d,int &k,ll dd)
{
    id[v]=k;
    vs[k]=v;
    wt[v]=dd;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++){
        if(G[v][i].F!=p){
            dfs(G[v][i].F,v,d+1,k,dd+G[v][i].S);
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
void init(int root){
    int k=0;
    dfs(root,0,0,k,0);
    rmq_init(n*2-1);
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
vector<int> leaves;
int main(){
    IO::begin();
    IO::read(n); IO::read(q);
    ll sum=0;
    for(int i=0;i<n-1;i++){
        int u,v,w;
        IO::read(u); IO::read(v); IO::read(w);
        add_edge(u,v,w); sum+=w;
    }
    for(int i=1;i<=n;i++) if(G[i].size()==1) leaves.push_back(i);
    //puts("done");
    for(int i=0;i<q;i++){
        IO::read(s[i]); IO::read(k[i]); IO::read(t[i]);
        save[s[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        init(i);
        for(auto x:save[i]){
            int v1=lca(t[x],k[x]);
            if(v1==t[x]) {ans[x]=-1; continue;}
            ans[x]=2*sum;
            int d=depth[id[v1]];
            //printf("x=%d\n",x);
            for(auto y:leaves){
                int v2=lca(k[x],y);
                if(depth[id[v2]]<=d) ans[x]=min(ans[x],2*sum-wt[y]);
                else ans[x]=min(ans[x],2*sum-wt[y]+2*(wt[v2]-wt[v1]));
                //printf("y=%d v1=%d v2=%d d1=%d d2=%d w1=%lld w2=%lld ans=%lld\n",y,v1,v2,dep[id[v1]],dep[id[v2]]ans[x]);
            }
        }
        //printf("%lld\n",ans);
    }
    for(int i=0;i<q;i++){
        if(ans[i]==-1) puts("impossible"); else printf("%lld\n",ans[i]);
    }
    return 0;
}

