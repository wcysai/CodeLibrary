#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,K,B,C;
int a[MAXN];
void update(int &a,int b) {a=min(a,b);}
int dp[2][MAXN][2*MAXN];
//dp[i][j][k]: currently at i, j blended to go, k swapped out
int main()
{
    scanf("%d%d%d%d",&n,&K,&B,&C);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=1;i++)
        for(int j=0;j<=K-1;j++)
            for(int k=0;k<=1000;k++)
                dp[i][j][k]=INF;
    dp[0][0][500]=0;
    for(int i=0;i<n;i++)
    {
        int now=i&1,nxt=now^1;
        for(int j=0;j<=K-1;j++)
            for(int k=0;k<=1000;k++)
                dp[nxt][j][k]=INF;
        for(int j=0;j<=K-1;j++)
        {
            for(int k=0;k<=1000;k++)
            {
                if(dp[now][j][k]==INF) continue;
                if(j==0)
                {
                    update(dp[nxt][j][k],dp[now][j][k]+a[i+1]);// choose
                    update(dp[nxt][j][k-1],dp[now][j][k]);// use
                    update(dp[nxt][K-1][k],dp[now][j][k]+B); //start & go
                    update(dp[nxt][K-1][k+1],dp[now][j][k]+B+C+a[i+1]);//start & swap
                }
                else
                {
                    update(dp[nxt][j-1][k],dp[now][j][k]); //go
                    update(dp[nxt][j-1][k+1],dp[now][j][k]+C+a[i+1]); //swap
                }
            }
        }
    }
    int ans=INF;
    for(int i=0;i<=K-1;i++) ans=min(ans,dp[n&1][i][500]);
    printf("%d\n",ans);
    return 0;
}
