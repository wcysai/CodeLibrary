#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXV 205
#define MAXE 42000
#define INF 1000000
using namespace std;
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[MAXE];
int V,E;
int p[MAXV],r[MAXV];
int cost[MAXV][MAXV];
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
    sort(es,es+E,cmp);
    init(V);
    int res=0;
    for(int i=0;i<E;i++)
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
int main()
{
    while(scanf("%d",&V)==1)
    {
        E=(V-1)*V/2;
        int k=0;
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
            {
                scanf("%d",&cost[i][j]);
                if(i<j)
                {
                    es[k].u=i;
                    es[k].v=j;
                    es[k].cost=cost[i][j];
                    k++;
                }
            }
        int ans=kruskal();
        printf("%d\n",ans);
    }
    return 0;
}
