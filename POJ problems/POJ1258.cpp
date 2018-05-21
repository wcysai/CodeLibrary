#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAXN 101
using namespace std;
struct edge
{
    int u,v;
    int cost;
};
bool cmp(edge m,edge n)
{
    return m.cost<n.cost;
}
int p[MAXN];

int find(int x) {return p[x]==x ? x : p[x]=find(p[x]);}

bool same(int x,int y) {return find(x)==find(y);}

void unite(int x,int y)
{
    int u = find(x);
    int v = find(y);
    if(u != v) p[u] = v;
}
edge e[MAXN*MAXN];
int n,k,sum,graph[MAXN][MAXN];
int main()
{
   while (scanf("%d",&n)!=(EOF))
   {
    k=0;
    sum=0;
    for(int i=1;i<=n;i++)
        p[i] = i;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
       {
          scanf("%d",&graph[i][j]);
          if(graph[i][j]!=0)
          {
              e[k].u=i;
              e[k].v=j;
              e[k].cost=graph[i][j];
              k++;
          }
       }
    sort(e,e+k,cmp);
    for(int i=0;i<k;i++)
    {
        if(!same(e[i].u,e[i].v))
        {
            unite(e[i].u,e[i].v);
            sum+=e[i].cost;
            n--;
        }
        if(n==0) break;
    }
    printf("%d\n",sum);
   }
    return 0;
}
