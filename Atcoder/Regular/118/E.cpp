#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long long ll;
int n,a[MAXN];
int dp[MAXN][MAXN][MAXN][2][2],fact[MAXN];
bool banned[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    fact[0]=1;
    for(int i=1;i<=200;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&n);
    int cnt=0;
    memset(banned,false,sizeof(banned));
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]==-1) cnt++; else banned[a[i]]=true;
    }
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0][0]=1;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
        {
            if(i==0&&j==0) continue;
            if(i>=1&&i<=n&&a[i]==j) continue;
            for(int k=0;k<=n;k++)
            {
                //go from left, not choose current grid
                if(j) 
                {
                    add(dp[i][j][k][0][0],dp[i][j-1][k][0][0]);
                    add(dp[i][j][k][1][0],dp[i][j-1][k][1][0]);
                    add(dp[i][j][k][0][0],dp[i][j-1][k][0][1]);
                    add(dp[i][j][k][1][0],dp[i][j-1][k][1][1]);
                }
                //go from above, not choose current grid
                if(i)
                {
                    add(dp[i][j][k][0][0],dp[i-1][j][k][0][0]);
                    add(dp[i][j][k][0][1],dp[i-1][j][k][0][1]);
                    add(dp[i][j][k][0][0],dp[i-1][j][k][1][0]);
                    add(dp[i][j][k][0][1],dp[i-1][j][k][1][1]);
                }
                //go from left and choose current grid
                if(i>=1&&i<=n&&j>=1&&j<=n&&(a[i]==-1)&&!banned[j]&&k)
                {
                    add(dp[i][j][k][1][1],dp[i][j-1][k-1][0][0]);
                    add(dp[i][j][k][1][1],dp[i][j-1][k-1][0][1]);
                }
                //go from above and choose current grid
                if(i>=1&&i<=n&&j>=1&&j<=n&&(a[i]==-1)&&!banned[j]&&k)
                {
                    add(dp[i][j][k][1][1],dp[i-1][j][k-1][0][0]);
                    add(dp[i][j][k][1][1],dp[i-1][j][k-1][1][0]);
                }
            }
        }
    int ans=0;
    for(int i=0;i<=cnt;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                if(i&1) dec(ans,1LL*dp[n+1][n+1][i][j][k]*fact[cnt-i]%MOD); else add(ans,1LL*dp[n+1][n+1][i][j][k]*fact[cnt-i]%MOD);
    printf("%d\n",ans);
    return 0;
}