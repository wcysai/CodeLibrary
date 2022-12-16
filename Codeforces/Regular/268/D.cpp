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
vector<P> G[MAXN];
int n,tot,sz[MAXN],a[MAXN],save[MAXN];
int per[MAXN];
ll d[MAXN];
set<int> all;
set<int> ind[MAXN];
ll ans;
void add_edge(int u,int v,int w){
    G[u].push_back(P(v,w));
    G[v].push_back(P(u,w));
}
P getroot(int v,int p,int t)
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++){
        int to=G[v][i].F;
        if(to==p) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void dfs(int v,int p)
{
    ans+=2*d[v]; sz[v]=1;
    for(auto e:G[v]){
        if(e.F==p) continue;
        d[e.F]=d[v]+e.S;
        dfs(e.F,v);
        sz[v]+=sz[e.F];
    }
}
void dfs2(int v,int p,int id)
{
    ind[id].insert(v); save[v]=id;
    for(auto e:G[v])
    {
        if(e.F==p) continue;
        dfs2(e.F,v,id);
    }
}
struct segtree
{
    P mini[4*MAXN];
    int fst[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k) {fst[k]=min(fst[k*2],fst[k*2+1]); mini[k]=min(mini[k*2],mini[k*2+1]);}
    void add(int k,int v) {mini[k].F+=v; lazy[k]+=v;}
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) {add(i,lazy[k]);}
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        if(l>=r) {mini[k]=P(a[l],l); fst[k]=*ind[l].begin(); return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void update2(int k,int l,int r,int pos,int v)
    {
        if(l==r) {fst[k]=v; return;}
        int mid=(l+r)/2;
        if(pos<=mid) update2(k*2,l,mid,pos,v); else update2(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query_first(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return fst[k];
        int mid=(l+r)/2;
        return min(query_first(k*2,l,mid,x,y),query_first(k*2+1,mid+1,r,x,y));
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(INF,0);
        if(l>=x&&r<=y) return mini[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    P p=getroot(1,0,n);
    dfs(p.S,0);
    printf("%lld\n",ans);
    for(auto e:G[p.S])
    {
        a[++tot]=n-2*sz[e.F];
        dfs2(e.F,p.S,tot);
    }
    seg.build(1,1,tot);
    bool root=false;
    for(int i=1;i<=n;i++)
    {
        seg.update(1,1,tot,1,tot,-1);
        if(i!=p.S) seg.update(1,1,tot,save[i],save[i],1);
        P mini=seg.query(1,1,tot,1,tot);
        if(mini.F==-1)
        {
            int fst=*ind[mini.S].begin();
            per[i]=fst;
            ind[mini.S].erase(fst); 
            seg.update(1,1,tot,mini.S,mini.S,1);
            int y=ind[mini.S].size()?*ind[mini.S].begin():INF;
            seg.update2(1,1,tot,mini.S,y);
        }
        else
        {
            int id=save[i];
            int fst=min(seg.query_first(1,1,tot,1,id-1),seg.query_first(1,1,tot,id+1,tot));
            if(!root&&fst>p.S)
            {
                fst=p.S;
                root=true;
            }
            per[i]=fst;
            if(save[fst]) 
            {
                ind[save[fst]].erase(fst); seg.update(1,1,tot,save[fst],save[fst],1);
                int y=ind[save[fst]].size()?*ind[save[fst]].begin():INF;
                seg.update2(1,1,tot,save[fst],y);
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d%c",per[i],i==n?'\n':' ');
    return 0;
}

