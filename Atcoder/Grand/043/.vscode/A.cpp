#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char str[MAXN][MAXN];
int dp[MAXN][MAXN];
void upd(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j]=INF;
    if(str[0][0]=='#') dp[0][0]=1; else dp[0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(i==0&&j==0) continue;
            if(i>0)
            {
                if(str[i][j]=='.'||str[i-1][j]=='#') upd(dp[i][j],dp[i-1][j]);
                else upd(dp[i][j],dp[i-1][j]+1);
            }
            if(j>0)
            {
                if(str[i][j]=='.'||str[i][j-1]=='#') upd(dp[i][j],dp[i][j-1]);
                else upd(dp[i][j],dp[i][j-1]+1);
            }
        }
    printf("%d\n",dp[n-1][m-1]);
    return 0;
}