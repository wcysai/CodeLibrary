#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,dp[MAXN][MAXN];
char str[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1) dp[i][j]=1;
            else if(str[i][j]=='.') dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD; else dp[i][j]=0;
        }
    printf("%d\n",dp[n][m]);
    return 0;
}

