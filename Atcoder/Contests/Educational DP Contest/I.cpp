#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n;
db p[MAXN];
db dp[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%Lf",&p[i]);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++) dp[i][j]=p[i]*(dp[i-1][j-1])+(1-p[i])*dp[i-1][j];
    }
    db ans=0.0;
    for(int j=1;j<=n;j++) if(j>n-j) ans+=dp[n][j];
    printf("%.15Lf\n",ans);
    return 0;
}

