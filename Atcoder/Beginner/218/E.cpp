#include<bits/stdc++.h>
#define MAXV 200005
#define MAXE 200005
#define INF 1000000000
using namespace std;
typedef long long ll;
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost>e2.cost;
}
edge es[MAXE];
int V,E;
int p[MAXV],r[MAXV];
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
ll kruskal()
{
    sort(es,es+E,cmp);
    init(V);
    ll res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            res+=e.cost;
        }
        else if(e.cost>0) res+=e.cost;
    }
    return res;
}
int main()
{
    scanf("%d%d",&V,&E);
    ll ans=0;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ans+=w;
        es[i]=(edge){u,v,-w};
    }
    printf("%lld\n",ans+kruskal());
    return 0;
}
