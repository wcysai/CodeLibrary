#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define MAXV 201
#define INF 1000000000
using namespace std;
double d[MAXV][MAXV];
pair<int,int> xy[MAXV];
int V;
void floyd_warshall()
{
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
          for(int j=0;j<V;j++) d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
}
int main()
{
    int k=0;
    while(scanf("%d",&V)==1)
    {
        k++;
        if(V==0) break;
        for(int i=0;i<V;i++)
            scanf("%d %d",&xy[i].first,&xy[i].second);
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                d[i][j]=sqrt((double)((xy[i].first-xy[j].first)*(xy[i].first-xy[j].first)+(xy[i].second-xy[j].second)*(xy[i].second-xy[j].second)));
        floyd_warshall();
        printf("Scenario #%d\n",k);
        printf("Frog Distance = %.3f\n\n",d[0][1]);
    }
    return 0;
}

