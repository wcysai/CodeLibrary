#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int dp[MAXN][2];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=0;
        dp[0][0]=dp[0][1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(!dp[i-1][j]) continue;
                for(int k=0;k<3;k++)
                {
                    int cnt=2-k+j;
                    if(cnt!=a[i]) continue;
                    int nj=(k==2||(k==1&&j==1))?0:1;
                    dp[i][nj]=true;
                }
            }
        }
        if(dp[n][0]||dp[n][1]) puts("YES"); else puts("NO");
    }
    return 0;
}

