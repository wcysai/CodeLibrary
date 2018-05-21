#include<bits/stdc++.h>
#define MAXV 100005
#define MAXE 200005
#define MAXW 100005
using namespace std;
struct edge
{
    int from,to,cost;
}save[MAXE];
bool cmp(edge x,edge y)
{
    return x.cost<y.cost;
}
int color[MAXV];
const int blocks=400;
int V,E,Q,T;
int p[MAXV],r[MAXV];
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
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&V,&E,&Q);
        for(int i=0;i<V;i++)
            scanf("%d",&color[i]);
        for(int i=0;i<E;i++)
            scanf("%d%d%d",&save[i].from,&save[i].to,save[i].cost);
        sort(save,save+E,cmp);

    }
}
