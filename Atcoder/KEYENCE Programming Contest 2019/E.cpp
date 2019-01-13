#include<bits/stdc++.h>
#define MAXN 200005
#define MAXE 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,d,a[MAXN];
struct edge{ll u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[MAXE];
ll V,E;
ll p[MAXN],r[MAXN];
void add_edge(ll u,ll v,ll cost)
{
    es[E++]=(edge){u,v,cost};
}
void init(ll n)
{
    for(ll i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
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
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
ll kruskal()
{
    sort(es,es+E,cmp);
    init(V);
    ll res=0;
    for(ll i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
set<P> ss;
int main()
{
    scanf("%lld%lld",&n,&d);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    ss.clear();
    ll now=d;
    ss.insert(P(a[1],1));
    for(ll i=2;i<=n;i++)
    {
        auto it=ss.begin();
        ll to=it->S,cost=it->F;
        add_edge(i,to,cost+now+a[i]);
        ss.insert(P(a[i]-now,i));
        now+=d;
    }
    ss.clear();
    now=d; ss.insert(P(a[n],n));
    for(ll i=n-1;i>=1;i--)
    {
        auto it=ss.begin();
        ll to=it->S,cost=it->F;
        add_edge(i,to,cost+now+a[i]);
        ss.insert(P(a[i]-now,i));
        now+=d;
    }
    V=n; printf("%lld\n",kruskal());
    return 0;
}

