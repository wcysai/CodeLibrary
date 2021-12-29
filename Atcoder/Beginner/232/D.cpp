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
bool dp[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    memset(dp,false,sizeof(dp));
    dp[1][1]=true;
    int ans=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='#') continue;
            if(i==1&&j==1) continue;
            if(dp[i-1][j]||dp[i][j-1]) 
            {
                dp[i][j]=true;
                ans=max(ans,i+j-1);
            }
        }
    printf("%d\n",ans);
    return 0;
}