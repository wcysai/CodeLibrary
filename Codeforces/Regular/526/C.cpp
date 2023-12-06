#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 19
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int p[MAXN],pos[MAXN],fa[MAXN];
int n,q,k,a[MAXN];
vector<int> G[MAXN];
int st[MAXLOGN+1][2*MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
void dfs(int v,int p,int d,int &k){
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
int dis(int u,int v)
{
    return depth[id[u]]+depth[id[v]]-2*depth[id[lca(u,v)]];
}
bool on_path(int x,int y,int z){
   return dis(x,z)+dis(y,z)==dis(x,y); 
}
P unite(P x,P y){
    if(x.F==0) return y;
    if(y.F==0) return x;
    if(x.F==-1||y.F==-1) return P(-1,-1);
    int u=x.F,v=x.S,uu=y.F,vv=y.S;
    P p=P(u,uu); int d=dis(u,uu);
    int dd=dis(u,vv); if(dd>d) {p=P(u,vv); d=dd;}
    dd=dis(v,uu); if(dd>d) {p=P(v,uu); d=dd;}
    dd=dis(v,vv); if(dd>d) {p=P(v,vv); d=dd;}
    dd=dis(u,v); if(dd>d) {p=P(u,v); d=dd;}
    dd=dis(uu,vv); if(dd>d) {p=P(uu,vv); d=dd;}
    if(on_path(p.F,p.S,u)&&on_path(p.F,p.S,v)&&on_path(p.F,p.S,uu)&&on_path(p.F,p.S,vv)) return p;
    else return P(-1,-1);
}
struct segtree{
    P path[4*MAXN];
    void pushup(int k){
        path[k]=unite(path[k*2],path[k*2+1]);
    }
    void build(int k,int l,int r){
        if(l==r){
            path[k]=P(pos[l],pos[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int v){
        if(l==r){
            path[k]=P(v,v);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query(int k,int l,int r,P cur){
        //printf("l=%d r=%d F=%d S=%d\n",l,r,cur.F,cur.S);
        if(l==r){
            P p=unite(cur,path[k]);
            if(p.F==-1) return l; else return l+1;
        }
        int mid=(l+r)/2;
        if(unite(cur,path[k*2]).F!=-1)
            return query(k*2+1,mid+1,r,unite(cur,path[k*2]));
        else return query(k*2,l,mid,cur);
    }
}seg;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&p[i]); pos[p[i]]=i;}
    for(int i=2;i<=n;i++){
        scanf("%d",&fa[i]);
        G[fa[i]].push_back(i); G[i].push_back(fa[i]);
    }
    init(n);
    seg.build(1,0,n-1);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int t;
        scanf("%d",&t);
        if(t==1){
            int x,y;
            scanf("%d%d",&x,&y);
            int xx=p[x],yy=p[y];
            swap(p[x],p[y]);
            swap(pos[xx],pos[yy]);
            seg.update(1,0,n-1,xx,pos[xx]);
            seg.update(1,0,n-1,yy,pos[yy]);
        }
        else{
            printf("%d\n",seg.query(1,0,n-1,P(0,0)));
        }
    }
    return 0;
}

