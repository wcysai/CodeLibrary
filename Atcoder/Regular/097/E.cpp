#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[2*MAXN];
char ch[2*MAXN][2];
int posb[MAXN],posw[MAXN];
int cntbb[MAXN][MAXN],cntbw[MAXN][MAXN],cntwb[MAXN][MAXN],cntww[MAXN][MAXN];
int dp[2*MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%s",ch[i]);
        scanf("%d",&a[i]);
        if(ch[i][0]=='B') posb[a[i]]=i; else posw[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cntbb[i][j]=cntbb[i][j-1];
            if(posb[j]>posb[i]) cntbb[i][j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cntbw[i][j]=cntbw[i][j-1];
            if(posw[j]>posb[i]) cntbw[i][j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cntwb[i][j]=cntwb[i][j-1];
            if(posb[j]>posw[i]) cntwb[i][j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cntww[i][j]=cntww[i][j-1];
            if(posw[j]>posw[i]) cntww[i][j]++;
        }
    }
    for(int i=0;i<=2*n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<=min(i,n);j++)
        {
            int b=j,w=i-j;
            if(j<n) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+cntbb[j+1][j+1]+cntbw[j+1][w]);
            if(w<n) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+cntww[w+1][w+1]+cntwb[w+1][b]);
        }
    }
    printf("%d\n",dp[2*n][n]);
    return 0;
}

