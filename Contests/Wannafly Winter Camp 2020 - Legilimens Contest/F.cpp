#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot,t;
struct edge{int to,cost;};
vector<edge> G[MAXN];
int st[MAXN],ed[MAXN],fa[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN],facost[MAXN],wcost[MAXN];
ll added[MAXN];
void add(ll &a,ll b) {a+=b;}
void dec(ll &a,ll b) {a-=b;}
void add_edge(int u,int v,int cost)
{
    G[u].push_back((edge){v,cost});
    G[v].push_back((edge){u,cost});
}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
struct segtree
{
    ll sum[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(int k,int l,int r)
    {
        sum[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int p,ll v)
    {
        if(l==r)
        {
            sum[k]+=v;
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v);  else update(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
void dfs1(int v,int p)
{
    fa[v]=p;sz[v]=1;
    for(auto e:G[v])
    {
        int to=e.to,cost=e.cost;
        if(to==p) continue;
        facost[to]=cost;
        dfs1(to,v);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
}
void dfs2(int v,int p,int num)
{
    top[v]=num;
    spos[v]=st[v]=++tot;
    tpos[tot]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(auto e:G[v])
    {
        int to=e.to,cost=e.cost;
        if(to==wson[v]) wcost[v]=cost;
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
    ed[v]=tot;
}
void init()
{
    tot=0;
    memset(wson,0,sizeof(wson));
    dfs1(1,1);
    dfs2(1,0,1);
    seg.build(1,1,n);
}
int main()
{
    scanf("%d",&n); 
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    init();
    scanf("%d",&q);
    int cur=1;
    for(int i=0;i<q;i++)
    {
        int type,v,x;
        scanf("%d%d",&type,&v);
        if(type==1)
        {
            scanf("%d",&x);
            seg.update(1,1,n,st[v],x);
            int u=v;
            while(top[u]!=1)
            {
                u=top[u];
                added[fa[u]]+=1LL*x*facost[u];
                u=fa[u];
            }     
        }
        else
        {
            cur=v;    
        }
        ll ans=added[cur];
        if(cur!=1)
        {
            int cost=facost[cur];
            ans-=1LL*cost*seg.query(1,1,n,st[cur],ed[cur]);
            ans+=1LL*cost*seg.query(1,1,n,1,n);
        }
        if(wson[cur])
        {
            int cost=wcost[cur];
            ans+=1LL*cost*seg.query(1,1,n,st[wson[cur]],ed[wson[cur]]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}