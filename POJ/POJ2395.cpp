#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAX_V 1005
#define MAX_E 20005
using namespace std;
int par[MAX_V],rank[MAX_V];
struct edge
{
    int from;
    int to;
    int cost;
};
bool cmp(edge x,edge y)
{
    return x.cost<y.cost;
}
edge es[MAX_E];
int V,E,p;
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rank[i]=0;
    }
}
int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if (x==y) return;
    if(rank[x]<rank[y])
        par[x]=y;
    else
    {
      par[y]=x;
      if(rank[x]==rank[y]) rank[x]++;
    }
    return;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int kruskal()
{
    sort(es,es+E,cmp);
    init(V);
    int res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.from,e.to))
        {
            unite(e.from,e.to);
            res=max(res,e.cost);
        }
    }
    return res;
}
int main()
{
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;i++)
    {
      scanf("%d %d %d",&es[i].from,&es[i].to,&es[i].cost);
      es[i].to--;
      es[i].from--;
    }
    printf("%d\n",kruskal());
    return 0;
}
