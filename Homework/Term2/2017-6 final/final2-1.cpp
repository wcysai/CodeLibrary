#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAXN 100
#define INF 1000000000
using namespace std;
int grid[MAXN][MAXN],n,m;
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          scanf("%d",&grid[i][j]);
    int f;
    for(int i=1;i<n;i++)
    {
        int x=grid[i][0]-grid[0][0];
        f=1;
        for(int j=1;j<m;j++)
            if(grid[i][j]-grid[0][j]!=x)
            {
              f=0;
              break;
            }
        if(!f)
        {
            printf("-1\n");
            break;
        }
    }
    if(!f) continue;
    int p=INF,q=INF,t=0;
    for(int i=0;i<n;i++)
    {
      if(grid[i][0]<p)
      {
          p=grid[i][0];
          t=i;
      }
    }
    for(int i=0;i<m;i++)
        q=min(q,grid[t][i]);
    int s=0;
    for(int i=0;i<m;i++)
        s+=grid[t][i];
    for(int i=0;i<n;i++)
        s+=grid[i][0]-p;
    if((n<m)&&(q>0))
    {
        s-=(m-n)*q;
    }
    printf("%d\n",s);
    }
    return 0;
}
