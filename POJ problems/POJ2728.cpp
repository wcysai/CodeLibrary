#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXV 1005
#define MAXE 3000000
#define INF 1000000000
#define eps 1e-6
using namespace std;
int V,E;
struct coord
{
    double x,y,z;
}c[MAXV];
double cost[MAXV][MAXV],a[MAXV][MAXV],b[MAXV][MAXV];
double mincost[MAXV];
bool used[MAXV];
double prim(double x)
{
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cost[i][j]=b[i][j]-x*a[i][j];
    for(int i=0;i<V;i++)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    double res=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<V;u++)
          if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        for(int u=0;u<V;u++)
            mincost[u]=min(mincost[u],cost[v][u]);
    }
    return res;
}
int main()
{
    while(scanf("%d",&V)==1)
    {
        if(V==0) break;
        for(int i=0;i<V;i++)
            scanf("%lf %lf %lf",&c[i].x,&c[i].y,&c[i].z);
        E=V*(V-1)/2;
        int k=0;
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
            {
                a[i][j]=sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y));
                b[i][j]=max(c[i].z-c[j].z,c[j].z-c[i].z);
            }
         double left=0;
         double right=1000;
         double mid;
         while(right-left>eps)
         {
              mid=(left+right)/2;
             if(prim(mid)<=0) right=mid; else left=mid;
         }
         printf("%0.3f\n",mid);
    }
    return 0;
}


