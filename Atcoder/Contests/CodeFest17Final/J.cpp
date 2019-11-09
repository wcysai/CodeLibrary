#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
struct edge{int to,cost;};
vector<edge> G[MAXN];
int n,cnt,a[MAXN];
int p[MAXN],r[MAXN];
ll fans;
struct min2
{
    P val[2];
    void init() {val[0]=val[1]=P(-1,INF);}
    void add(P p)
    {
        if(p.F==val[0].F) { if(p.S<val[0].S) val[0]=p;}
        else if(p.F==val[1].F) { if(p.S<val[1].S) val[1]=p;}
        else if(p.S<val[0].S) { val[1]=val[0]; val[0]=p;}
        else if(p.S<val[1].S) val[1]=p;
        if(val[0].S>val[1].S) swap(val[0],val[1]);
    }
    P get(int x)
    {
        if(val[0].F!=-1&&val[0].F!=x) return val[0];
        else if(val[1].F!=-1&&val[1].F!=x) return val[1];
        return P(-1,INF);
    }
    void add(min2 rhs,int cost)
    {
        if(rhs.val[0].F!=-1) add(P(rhs.val[0].F,rhs.val[0].S+cost));
        if(rhs.val[1].F!=-1) add(P(rhs.val[1].F,rhs.val[1].S+cost));
    }
};
min2 f[MAXN],ans[MAXN];
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
void add_edge(int u,int v,int cost)
{
    G[u].push_back((edge){v,cost});
    G[v].push_back((edge){u,cost});
}
void dfs1(int v,int p)
{
    f[v].init();
    for(auto e:G[v])
    {
        int to=e.to,cost=e.cost;
        if(to==p) continue;
        dfs1(to,v);
        f[v].add(P(find(to),a[to]+cost));
        f[v].add(f[to],cost);
    }
}
void dfs2(int v,int p)
{
    ans[find(v)].add(f[v],a[v]);
    for(auto e:G[v])
    {
        int to=e.to,cost=e.cost;
        if(to==p) continue;
        f[to].add(P(find(v),a[v]+cost));
        f[to].add(f[v],cost);
        dfs2(to,v);
    }
}
ll boruvka()
{
    init(n);
    cnt=n; fans=0;
    while(cnt>1)
    {
        for(int i=1;i<=n;i++) ans[i].init();
        dfs1(1,0);
        dfs2(1,0);
        for(int i=1;i<=n;i++)
        {
            P res=ans[i].get(i);
            if(res.F!=-1&&!same(res.F,i))
            {
                unite(res.F,i); cnt--;
                fans+=res.S;
            }
        }
    }
    return fans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v,cost;
        scanf("%d%d%d",&u,&v,&cost);
        add_edge(u,v,cost);
    }
    printf("%lld\n",boruvka());
    return 0;
}
