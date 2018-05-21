#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 13
#define MAXM 13
using namespace std;
typedef long long ll;
int grid[MAXN];
ll dp[MAXM][(1<<MAXN)];
int n,m;
int main()
{
    memset(grid,0,sizeof(grid));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        for(int j=0;j<m;j++)
        {
          scanf("%d",&x);
          grid[i]=grid[i]*2+x;
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<(1<<m);i++)
    {
        if((i&grid[0])==i&&!(i&(i<<1)))dp[0][i]=1; else dp[0][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            if((j&grid[i])==j&&!(j&(j<<1)))
                for(int k=0;k<(1<<m);k++)
                {
                  if((j&k)==0) dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000000;
                }
        }
    }
    ll s=0;
    for(int j=0;j<(1<<m);j++)
        s=(s+dp[n-1][j])%1000000000;
    printf("%lld\n",s);
    return 0;
}


