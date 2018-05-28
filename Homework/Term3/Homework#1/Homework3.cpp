#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXV 105
#define MAXE 20000
#define INF 1000000
#define MAXN 100000
using namespace std;
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[MAXE];
int V,E;
int p[MAXV],r[MAXV];
vector<int> G;
void init(int n)
{
    for(int i=0;i<n;i++)
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
int kruskal()
{
    G.clear();
    sort(es,es+E,cmp);
    init(V);
    int res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            G.push_back(i);
            res+=e.cost;
        }
    }
    for(int i=0;i<G.size();i++)
    {
        int res2=0;
        init(V);
        for(int j=0;j<E;j++)
        {
            if(j==G[i]) continue;
            edge e=es[j];
            if(!same(e.u,e.v))
            {
                unite(e.u,e.v);
                res2+=e.cost;
            }
        }
        bool f=true;
        for(int j=1;j<V;j++)
            if(!same(0,j)) {f=false; break;}
        if(f&&res2==res) {res=-1; break;}
    }
    return res;
}
int main()
{
    int query;
    scanf("%d",&query);
    while(query--)
    {
        scanf("%d %d",&V,&E);
        int x,y,z;
        for(int i=0;i<E;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            es[i].u=x-1;
            es[i].v=y-1;
            es[i].cost=z;
        }
         int ans=kruskal();
         if(ans!=-1) printf("%d\n",ans); else printf("Not Unique!\n");
    }
    return 0;
}

