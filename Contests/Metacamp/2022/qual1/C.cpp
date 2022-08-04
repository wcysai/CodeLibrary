#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN][MAXN][MAXN],ndp[MAXN][MAXN][MAXN];
char s[MAXN],t[MAXN];
int sum[3][MAXN];//R,P,S
int check(int x,int y)
{
    if(s[x]=='r'&&t[y]=='s') return 1;
    if(s[x]=='p'&&t[y]=='r') return 1;
    if(s[x]=='s'&&t[y]=='p') return 1;
    return 0;
}
void upd(int &a,int b) {a=max(a,b);}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            sum[j][i]=sum[j][i-1];
        if(t[i]=='r') sum[0][i]++; else if(t[i]=='p') sum[1][i]++; else sum[2][i]++;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        memset(ndp,-1,sizeof(ndp));
        for(int j=0;j<=i;j++)
            for(int k=0;j+k<=i;k++)
                for(int l=0;j+k+l<=i;l++)
                {
                    if(dp[j][k][l]==-1) continue;
                    //move
                    if(s[i]=='r') upd(ndp[j+1][k][l],dp[j][k][l]);
                    else if(s[i]=='p') upd(ndp[j][k+1][l],dp[j][k][l]);
                    else upd(ndp[j][k][l+1],dp[j][k][l]);
                    //fight
                    int nxt=i-(j+k+l);
                    upd(ndp[j][k][l],dp[j][k][l]+check(i,nxt));
                }
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        for(int j=0;i+j<=n;j++)
            for(int k=0;i+j+k<=n;k++)
            {
                //printf("i=%d j=%d k=%d dp=%d\n",i,j,k,dp[i][j][k]);
                int res=dp[i][j][k]-i-j-k;
                int pos=n-i-j-k;
                res+=min(i,sum[2][n]-sum[2][pos]);
                res+=min(j,sum[0][n]-sum[0][pos]);
                res+=min(k,sum[1][n]-sum[1][pos]);
                //printf("pos=%d res=%d\n",pos,res);
                ans=max(ans,res);
            }
    printf("%d\n",ans);
    return 0;
}

