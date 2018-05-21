#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 1000
#define INF 100000000
using namespace std;
int cost[MAXN+1][MAXN+1],ans;
int d1[MAXN+1];
int d2[MAXN+1];
bool used[MAXN+1];
typedef pair<int,int> P;
int main()
{
    int n,p,x,y,z,m;
    scanf("%d %d %d",&n,&m,&p);
     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          cost[i][j]=INF;
    for(int i=1;i<=n;i++)
        cost[i][i]=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        cost[x][y]=z;
    }
    fill(d1,d1+n+1,INF);
    fill(used,used+n+1,false);
    d1[p]=0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!used[u]&&(v==-1||d1[u]<d1[v])) v=u;
        if(v==-1)break;
        used[v]=true;
        for(int u=1;u<=n;u++)
            d1[u]=min(d1[u],d1[v]+cost[v][u]);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
          swap(cost[i][j],cost[j][i]);
    fill(d2,d2+n+1,INF);
    fill(used,used+n+1,false);
    d2[p]=0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!used[u]&&(v==-1||d2[u]<d2[v])) v=u;
        if(v==-1)break;
        used[v]=true;
        for(int u=1;u<=n;u++)
          d2[u]=min(d2[u],d2[v]+cost[v][u]);
    }
    int ans=-INF;
    for(int i=1;i<=n;i++)
        ans=max(ans,d1[i]+d2[i]);
    printf("%d\n",ans);
    return 0;
}