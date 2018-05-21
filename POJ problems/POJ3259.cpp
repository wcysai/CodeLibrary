#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAXN 1000000
using namespace std;
struct edge
{
    int u,v;
    int cost;
};
int main()
{
edge e[50002];
int dist[25001];
int n,m,t,x,y,z,p,flag;
scanf("%d",&p);
for(int k=1;k<=p;k++)
{
fill(dist,dist+25001,MAXN);
dist[1]=0;
scanf("%d %d %d",&n,&m,&t);
for(int i=1;i<=m;i++)
{
    scanf("%d %d %d",&x,&y,&z);
    e[2*i-1].u=x;
    e[2*i-1].v=y;
    e[2*i-1].cost=z;
    e[2*i].u=y;
    e[2*i].v=x;
    e[2*i].cost=z;
}
for(int i=2*m+1;i<=2*m+t;i++)
{
    scanf("%d %d %d",&x,&y,&z);
    e[i].u=x;
    e[i].v=y;
    e[i].cost=-z;
}
for(int i=1;i<=n;i++)
    for(int j=1;j<=2*m+t;j++)
         if (dist[e[j].v]>dist[e[j].u]+e[j].cost)
            dist[e[j].v]=dist[e[j].u]+e[j].cost;
flag=1;
for(int i=1; i<=2*m+t;i++)
    if(dist[e[i].v] > dist[e[i].u] + e[i].cost)
        {
            flag=0;
            break;
        }
if(flag==0) printf("YES\n"); else printf("NO\n");
}
return 0;
}
