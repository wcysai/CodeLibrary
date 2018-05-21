#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 300
#define INF 100000000
using namespace std;
int d[MAXN][MAXN];
int ans;
int input[MAXN];
int aver[MAXN];
int main()
{
    int n,m,x;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          d[i][j]=INF;
    for(int i=0;i<n;i++)
        d[i][i]=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        for(int j=0;j<x;j++)
            scanf("%d",&input[j]);
        for(int j=0;j<x-1;j++)
          for(int k=j+1;k<x;k++)
          {
            d[input[j]-1][input[k]-1]=1;
            d[input[k]-1][input[j]-1]=1;
          }
    }
    for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    memset(aver,0,sizeof(aver));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
          aver[i]+=d[i][j];
        aver[i]=(aver[i]*100/(n-1));
    }
    ans=INF;
    for(int i=0;i<n;i++)
        ans=min(ans,aver[i]);
    printf("%d",ans);
    return 0;
}