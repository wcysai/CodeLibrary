#include<bits/stdc++.h>
#define MAXK 805
#define MAXN 4005
#define INF 1e9
using namespace std;
int n,k,w[MAXN],mat[MAXN][MAXN],dp[MAXK][MAXN],sum[MAXN][MAXN],cal[MAXN][MAXN];
void compute(int i,int jleft,int jright,int kleft,int kright)
{
    int jmid=(jleft+jright)/2;
    int bestk=-1;
    dp[i][jmid]=INF;
    for(int p=kleft;p<jmid;p++)
    {
        if(dp[i-1][p]+cal[p+1][jmid]<dp[i][jmid])
        {
            dp[i][jmid]=dp[i-1][p]+cal[p+1][jmid];
            bestk=p;
        }
    }
    if(jleft<=jmid-1) compute(i,jleft,jmid-1,kleft,bestk);
    if(jmid+1<=jright) compute(i,jmid+1,jright,bestk,kright);
}
int main()
{
    scanf("%d%d\n",&n,&k);
    char buffer[10000];
    for(int i=1; i<=n; i++)
    {
      gets(buffer);
      for(int j=1; j<=n; j++)
        mat[i][j] = buffer[2 * (j - 1)] - '0';
    }
    for(int i=0;i<=n;i++)
    {
        sum[0][i]=0;
        sum[i][0]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+mat[i][j];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            cal[i][j]=sum[j][j]-sum[j][i-1]-sum[i-1][j]+sum[i-1][i-1];
    for(int i=1;i<=n;i++)
        dp[1][i]=cal[1][i];
    for(int i=2;i<=k;i++)
        compute(i,i,n,i-1,n-1);
    printf("%d\n",dp[k][n]/2);
    return 0;
}

