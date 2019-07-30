#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN][MAXN];
ll sum[2][MAXN][MAXN];
ll dp[MAXN][MAXN];
ll getcost(int id,int fromx,int fromy,int tox,int toy)
{
    if(fromx>fromy||tox>toy) return 0;
    return sum[id][fromy][toy]-sum[id][fromx-1][toy]-sum[id][fromy][tox-1]+sum[id][fromx-1][tox-1];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            scanf("%d",&a[i][j]);
        }
    for(int k=0;k<2;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                int add=(i<j?1:0)^(k==0?1:0);
                sum[k][i][j]=sum[k][i][j-1]+a[i][j]*(1-add);
            }
    for(int k=0;k<2;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                sum[k][i][j]=sum[k][i][j]+sum[k][i-1][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    //
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(dp[i][j]==INF) continue;
            for(int k=i+1;k<=n;k++)
                dp[k][i]=min(dp[k][i],dp[i][j]+getcost(1,k+1,n,j+1,i)+getcost(0,i+1,k,i+1,k));
        }
    }
    ll ans=INF;
    for(int i=0;i<=n;i++) ans=min(ans,dp[n][i]);
    printf("%lld\n",ans);
    return 0;
}
