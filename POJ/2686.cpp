#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX_N 8
#define MAX_M 30
#define INF 10000000
using namespace std;
int n,m,p,a,b;
int t[MAX_N];
int d[MAX_M][MAX_M];
double dp[1<<MAX_N][MAX_M];
void solve()
{
    for(int i=0;i<1<<n;i++)
        fill(dp[i],dp[i]+m,INF);
    dp[(1<<n)-1][a-1]=0;
    double res=INF;
    for(int S=(1<<n)-1;S>=0;S--)
    {
        res=min(res,dp[S][b-1]);
        for(int v=0;v<m;v++)
        {
            for(int i=0;i<n;i++)
            {
                if(S>>i&1)
                {
                    for(int u=0;u<m;u++)
                    {
                        if(d[v][u]>=0)
                        {
                            dp[S&~(1<<i)][u]=min(dp[S&~(1<<i)][u],dp[S][v]+(double)d[v][u]/t[i]);
                        }
                    }
                }
            }
        }
    }
    if(res==INF)
        {
            printf("Impossible\n");
        }
    else
    {
        printf("%.3f\n",res);
    }
}
int main()
{
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b)==5)
    {
        if(n==0) break;
    memset(d,-1,sizeof(d));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        scanf("%d",&t[i]);
    for(int i=0;i<m;i++) d[i][i]=0;
    int x,y,z;
    for(int i=0;i<p;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        d[x-1][y-1]=z;
        d[y-1][x-1]=z;
    }
    solve();
    }
    return 0;
}
