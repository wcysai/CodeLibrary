#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define MAXV 1001
#define MAXE 100005
#define INF 1000000000
using namespace std;
int cost[MAXV][MAXV];
int d[MAXV];
bool used[MAXV];
void dijkstra(int s)
{
    fill(d,d+1001,INF);
    fill(used,used+1001,false);
    d[s]=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<1001;u++)
            if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
        if(v==-1) break;
        used[v]=true;
        for(int u=0;u<1001;u++)
            d[u]=min(d[u],d[v]+cost[v][u]);
    }
}
int E,n,m;
int main()
{
    while(scanf("%d %d %d",&E,&n,&m)==3)
    {
        for(int i=0;i<=1000;i++)
            for(int j=0;j<=1000;j++)
                cost[i][j]=i==j?0:INF;
        int x,y,z;
        for(int i=0;i<E;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            if(cost[x][y]>z) cost[x][y]=cost[y][x]=z;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            cost[0][x]=cost[x][0]=0;
        }
        dijkstra(0);
        int ans=INF;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            ans=min(ans,d[x]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
