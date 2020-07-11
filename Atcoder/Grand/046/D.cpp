#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
int dp[MAXN][MAXN][MAXN];
int dp2[MAXN][MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main() 
{
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                dp[i][j][k]=INF;
    dp[0][0][0]=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++)
            for(int k=0;k<=j;k++)
            {
                if(dp[i][j][k]>=3) continue;
                printf("%d %d %d\n",i,j,k);
                dp[i+1][j][k]=0;
                dp[i+1][j+1][k+(str[i+1]=='0')]=min(dp[i+1][j+1][k+(str[i+1]=='0')],dp[i][j][k]+1);
            }
    dp2[0][0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i+j<=n;j++)
        {
            for(int k=0;i+j+k<=n;k++)
            {
                if(str[n-i]=='0')
                {
                    add(dp2[i+1][j][k],dp2[i][j][k]);
                    add(dp2[i][j][k+1],dp2[i][j][k]);
                }
                else
                {
                    add(dp2[i+1][j][k],dp2[i][j][k]);
                    add(dp2[i][j+1][k],dp2[i][j][k]);
                }
                
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        for(int j=0;i+j<=n;j++)
            for(int k=0;i+j+k<=n;k++)
            {
                if(i==0&&j==0&&k==0) continue;
                if((j+k)*2>n-i) continue;
                if(dp[n-i][j+k][j]>=3) continue;
                add(ans,dp2[i][j][k]);
            }
    printf("%d\n",ans);
    return 0;
}