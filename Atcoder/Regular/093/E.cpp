#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
ll x;
struct edge{int to,cost;};
struct edge2{int u,v,w;};
edge2 a[MAXM];
vector<edge> G[MAXN];
vector<edge> tree[MAXN];
int fa[MAXN],dep[MAXN],cost[MAXN];
map<P,int> mp;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
bool cmp(edge2 p,edge2 q)
{
    return p.w<q.w;
}
void add_edge(int u,int v,int w)
{
    G[u].push_back((edge){v,w});
    G[v].push_back((edge){u,w});
}
void add_tree_edge(int u,int v,int w)
{
    tree[u].push_back((edge){v,w});
    tree[v].push_back((edge){u,w});
}
int p[MAXN],r[MAXN];
void init(int n)
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
ll kruskal()
{
    sort(a,a+m,cmp);
    init(n);
    ll ret=0;
    for(int i=0;i<m;i++)
    {
        if(!same(a[i].u,a[i].v))
        {
            ret+=a[i].w;
            unite(a[i].u,a[i].v);
            mp[P(a[i].u,a[i].v)]=1;
            add_tree_edge(a[i].u,a[i].v,a[i].w);
        }
    }
    return ret;
}
void dfs(int v,int p,int d,int c)
{
    fa[v]=p;dep[v]=d;cost[v]=c;
    for(auto e:tree[v])
    {
        if(e.to==p) continue;
        dfs(e.to,v,d+1,e.cost);
    }
}
int find_max(int u,int v)
{
    int ans=0;
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v])
    {
        ans=max(ans,cost[u]);
        u=fa[u];
    }
    while(u!=v)
    {
        ans=max(ans,cost[u]);ans=max(ans,cost[v]);
        u=fa[u];v=fa[v];
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%lld",&x);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u>v) swap(u,v);
        add_edge(u,v,w);
        a[i].u=u;a[i].v=v;a[i].w=w;
    }
    ll res=kruskal();
    if(res>x)
    {
        puts("0");
        return 0;
    }
    ll d=x-res;
    int less=0,equal=0,greater=0;
    dfs(1,0,0,0);
    for(int i=0;i<m;i++)
    {
        if(mp[P(a[i].u,a[i].v)]) continue;
        ll now=res-find_max(a[i].u,a[i].v)+a[i].w;
        if(now==x) equal++;
        else if(now>x) greater++;
        else less++;
    }
    assert(equal+greater+less==(m-(n-1)));
    int ans=0;
    if(d==0)
    {
        ans=pow_mod(2,n-1);dec(ans,2);
        ans=1LL*ans*pow_mod(2,m-(n-1))%MOD;
        add(ans,2LL*(pow_mod(2,equal)-1)*pow_mod(2,m-(n-1)-equal)%MOD);
        printf("%d\n",ans);
    }
    else
    {
        assert(d>0);
        ans=2LL*(pow_mod(2,equal)-1)*pow_mod(2,greater)%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

