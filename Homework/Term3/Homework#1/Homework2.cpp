#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXV 100000
#define MAXE 300000
#define INF 1000000
using namespace std;
struct edge{int u,v; double cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[MAXE];
int V,E;
int p[MAXV],r[MAXV];
int n,S;
pair<double,double> c[MAXV];
double ans[MAXV];
vector<edge> G;
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
double kruskal()
{
    G.clear();
    sort(es,es+E,cmp);
    init(V);
    int cnt=0;
    ans[0]=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            cnt++;
            ans[cnt]=max(ans[cnt-1],es[i].cost);
        }
    }
    return ans[V-S];
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&S,&V);
        for(int i=0;i<V;i++)
            scanf("%lf %lf",&c[i].first,&c[i].second);
        E=V*(V-1)/2;
        int k=0;
        for(int i=0;i<V;i++)
            for(int j=i+1;j<V;j++)
            {
                es[k].u=i;
                es[k].v=j;
                es[k].cost=sqrt(1.0*(c[i].first-c[j].first)*(c[i].first-c[j].first)+1.0*(c[i].second-c[j].second)*(c[i].second-c[j].second));
                k++;
            }
         double ans=kruskal();
         printf("%0.2f\n",ans);
    }
    return 0;
}

