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
typedef long double db;
int T,n;
db dp[MAXN][MAXN];
P a[MAXN][MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                scanf("%d%d",&a[i][j].F,&a[i][j].S);
        for(int i=1;i<=n+1;i++)
            for(int j=1;j<=i;j++)
                dp[i][j]=0;
        for(int i=1;i<=n+1;i++) dp[n][i]=0;
        for(int i=n;i>=1;i--)
            for(int j=1;j<=i;j++)
            {
                if(a[i][j].F<a[i][j].S) dp[i][j]=a[i][j].F+dp[i+1][j];
                else if(a[i][j].F>a[i][j].S) dp[i][j]=a[i][j].S+dp[i+1][j+1];
                else dp[i][j]=(dp[i+1][j]+dp[i+1][j+1]+a[i][j].F+a[i][j].S)/2;
            }
        printf("%.15Lf\n",dp[1][1]);
    }
    return 0;
}

