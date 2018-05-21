#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 11
#define INF 10000000
using namespace std;
int d[MAXN][MAXN];
int dp[1<<MAXN][MAXN];
int n;
void solve()
{
    for(int S=0;S<1<<n;S++)
    {
        fill(dp[S],dp[S]+n,INF);
    }
    dp[(1<<n)-1][0]=0;
    for(int S=(1<<n)-2;S>=0;S--)
    {
        for(int v=0;v<n;v++)
        {
            for(int u=0;u<n;u++)
            {
                if(!(S>>u&1))
                {
                    dp[S][v]=min(dp[S][v],dp[S|(1<<u)][u]+d[v][u]);
                }
            }
        }
    }
    printf("%d\n",dp[0][0]);
}
int main()
{
    scanf("%d",&n);
    while(n!=0)
    {
    n+=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&d[i][j]);
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    solve();
    scanf("%d",&n);
    }
    return 0;
}
