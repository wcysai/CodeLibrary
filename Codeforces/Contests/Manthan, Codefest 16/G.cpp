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
int n,m,q,tot,a[MAXN];
vector<int> G[MAXN];
int st[MAXN],ed[MAXN],rev[MAXN];
bitset<1000> pr;
void dfs(int v,int p){
    st[v]=++tot; rev[tot]=v;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
    }
    ed[v]=tot;
}
struct segtree{
    bitset<1000> bs[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k){
        bs[k]=bs[k*2]|bs[k*2+1];
    }
    void add(int k,int v){
        v%=m;
        lazy[k]=(lazy[k]+v)%m;
        bs[k]=(bs[k]<<v)|(bs[k]>>(m-v));
    }
    void pushdown(int k){
        if(lazy[k]){
            for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
            lazy[k]=0;
        }
    }
    void build(int k,int l,int r){
        if(l==r) {bs[k].set(a[rev[l]]%m); return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    bitset<1000> query(int k,int l,int r,int x,int y){
        if(l>y||x>r) {bitset<1000> tmp; return tmp;}
        if(l>=x&&r<=y) return bs[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)|query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=2;i<=m-1;i++)
    {
        pr.set(i);
        for(int j=2;j*j<=i;j++) if(i%j==0) pr.reset(i);
    }
    dfs(1,0);
    seg.build(1,1,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int type,v,x;
        scanf("%d%d",&type,&v);
        if(type==1){
            scanf("%d",&x);
            seg.update(1,1,n,st[v],ed[v],x);
        }
        else{
            auto b=seg.query(1,1,n,st[v],ed[v]);
            printf("%d\n",(int)(b&pr).count());
        }
    }
    return 0;
}

