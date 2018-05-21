#include<bits/stdc++.h>
#define MAXK 20005
#define MAXN 2005
#define INF 1e9
using namespace std;
int n,k,a[MAXN][21],sum[MAXN][21],dp[MAXK][MAXN];
int cal(int a,int b)
{
    int s=0;
    for(int i=20;i>=0;i--)
    {
        s<<=1;
        if(sum[b][i]-sum[a-1][i]>0) s+=1;
    }
    return s;
}
int main()
{
    scanf("%d%d",&n,&k);;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<=20;j++)
            a[i][j]=(x>>j)&1;
    }
    for(int i=0;i<=20;i++)
        sum[0][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<20;j++)
            sum[i][j]=a[i][j]+sum[i-1][j];
    for(int i=1;i<=n;i++)
        dp[1][i]=cal(1,i);

    printf("%d\n",dp[k][n]);
    return 0;
}


