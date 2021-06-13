#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000000000000LL
using namespace std;
typedef long long ll;
ll a[MAXN];
ll n,k;
int sum[MAXN];
ll dp[MAXN][MAXN];
short knuth[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            dp[i][j]=INF;
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(len==2)
            {
                dp[i][j]=a[i]*a[j];
                knuth[i][j]=j;
            }
            else
            {
                for(int k=knuth[i][j-1];k<=knuth[i+1][j];k++)
                    if(dp[i][k]+dp[k+1][j]+1LL*(sum[k]-sum[i-1])*(sum[j]-sum[k])<dp[i][j])
                    {
                        dp[i][j]=dp[i][k]+dp[k+1][j]+1LL*(sum[k]-sum[i-1])*(sum[j]-sum[k]);
                        knuth[i][j]=k;
                    }
            }
        }
    printf("%lld\n",dp[1][n]);
    return 0;
}

