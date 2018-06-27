#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MAXV 1005
#define MAXE 21005
#define INF 1000000000
using namespace std;
struct edge{int from,to,cost;};
edge es[MAXE];
int d[MAXV];
int E;
int V,ML,MD;
bool shortest_path(int s)
{
    for(int i=0;i<V;i++) d[i]=INF;
    d[s]=0;
    bool update;
    int cnt=0;
    while(true)
    {
        update=false;
        for(int i=0;i<E;i++)
        {
            edge e=es[i];
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost)
            {
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
        }
        if(!update) break;
        if(cnt==V-1) return false;
        cnt++;
    }
    return true;
}
int main()
{
    scanf("%d %d %d",&V,&ML,&MD);
    E=V+ML+MD-1;
    for(int i=0;i<V-1;i++)
    {
        es[i].from=i+1;
        es[i].to=i;
        es[i].cost=0;
    }
    int x,y,z;
    for(int i=V-1;i<V+ML-1;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        x--,y--;
        es[i].from=x;
        es[i].to=y;
        es[i].cost=z;
    }
    for(int i=V+ML-1;i<V+ML+MD-1;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        x--,y--;
        es[i].from=y;
        es[i].to=x;
        es[i].cost=-z;
    }
    if(!shortest_path(0)) printf("-1\n");
    else if(d[V-1]==INF) printf("-2\n");
    else printf("%d\n",d[V-1]);
    return 0;
}
