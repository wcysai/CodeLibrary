#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,x,y,a[MAXN],b[MAXN];
int dp[MAXN][MAXN],ndp[MAXN][MAXN];
void upd(int &x,int y) {x=min(x,y);}
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for(int i=0;i<=x;i++)
        for(int j=0;j<=y;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int t=1;t<=n;t++)
    {
        for(int i=0;i<=x;i++)
            for(int j=0;j<=y;j++)
                ndp[i][j]=dp[i][j];
        for(int i=0;i<=x;i++)
            for(int j=0;j<=y;j++)
            {
                if(dp[i][j]==INF) continue;
                upd(ndp[min(x,i+a[t])][min(y,j+b[t])],dp[i][j]+1);
            }
        swap(dp,ndp);
    }
    if(dp[x][y]==INF) puts("-1"); else printf("%d\n",dp[x][y]);
    return 0;
}