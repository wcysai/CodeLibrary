#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,tot,top[MAXN],dep[MAXN],spos[MAXN],tpos[MAXN],wson[MAXN],sz[MAXN],pa[MAXN];
vector<int> G[MAXN]; 
int l[MAXN],r[MAXN],st[MAXN],ed[MAXN];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void madd(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void mdec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
struct segtree{
    int len[4*MAXN],sum[2][4*MAXN],lazy[2][4*MAXN],ans[4*MAXN];
    void build(int k,int l,int r){
        len[k]=r-l+1;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void pushup(int k){
        for(int i=0;i<2;i++){
            sum[i][k]=sum[i][k*2];
            madd(sum[i][k],sum[i][k*2+1]);
        }
        ans[k]=ans[k*2]; madd(ans[k],ans[k*2+1]);
    }
    void add(int id,int k,int v){
        madd(ans[k],1LL*v*sum[1-id][k]%MOD);
        madd(sum[id][k],1LL*len[k]*v%MOD);
        madd(lazy[id][k],v);
    }
    void pushdown(int k){
        for(int i=0;i<2;i++){
            if(!lazy[i][k]) continue;
            for(int j=k*2;j<=k*2+1;j++) {
                add(i,j,lazy[i][k]);
            }
            lazy[i][k]=0;
        }
    }
    void update(int k,int l,int r,int x,int y,int id,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            add(id,k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,id,v); update(k*2+1,mid+1,r,x,y,id,v);
        pushup(k);
    }
    int query(){
        return ans[1];
    }
}seg;
void dfs1(int v,int p,int d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs1(to,v,d+1);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
}
void dfs2(int v,int p,int num)
{
    top[v]=num;
    spos[v]=++tot;
    tpos[tot]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void update(int id,int v,int val){
    while(top[v]!=1)
    {
        seg.update(1,1,n,spos[top[v]],spos[v],id,val);
        v=pa[top[v]];
    }
    seg.update(1,1,n,spos[top[v]],spos[v],id,val);
}
void init()
{
    tot=0;
    memset(wson,0,sizeof(wson));
    dfs1(1,1,1);
    dfs2(1,0,1);
    seg.build(1,1,n);
}
int val[MAXN];
vector<P> upd[MAXN];
int main()
{
    scanf("%d",&n);
    int prod=1;
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&l[i],&r[i]);
        int len=r[i]-l[i]+1;
        prod=1LL*prod*len%MOD;
        val[i]=pow_mod(len,MOD-2);
        upd[l[i]].push_back(P(i,1)); 
        upd[r[i]+1].push_back(P(i,-1));
    }
    for(int i=0;i<n-1;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    init();
    int ans=0;
    for(int i=1;i<=100000;i++){
        for(auto p:upd[i]){
            int v=p.F,z=(p.S==1?val[v]:MOD-val[v]);
            seg.update(1,1,n,1,n,0,z);
            update(0,v,MOD-z);
            update(1,v,z);
        }
        madd(ans,seg.query());
        //printf("i=%d ans=%d\n",i,ans);
    }
    ans=1LL*ans*prod%MOD;
    printf("%d\n",ans);
    return 0;
}

