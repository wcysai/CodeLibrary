#include<bits/stdc++.h>
#define MAXN 305
using namespace std;
int n,m,ans[MAXN][MAXN],dp[MAXN][MAXN];
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main ()
{
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<MAXN;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(gcd(i,j)==1?1:0);
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<MAXN;j++)
            ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+dp[i][j]-dp[i/2][j/2];
    while (scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m) break;
        printf("%d\n",ans[n-1][m-1]*2);
    }
    return 0;
}
