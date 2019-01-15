#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,dp[MAXN][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=1000001;i++) dp[i][0]=0,dp[i][1]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        dp[x][0]=max(dp[x][0],dp[x-1][0]+1);
        dp[x+1][1]=max(dp[x+1][1],dp[x][0]+1);
        dp[x][1]=max(dp[x][1],dp[x-1][1]+1);
    }
    int ans=0;
    for(int i=1;i<=1000001;i++) ans=max(ans,dp[i][1]);
    printf("%d\n",ans);
    return 0;
}
