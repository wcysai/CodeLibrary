#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,dp[MAXN][MAXN],part[MAXN][MAXN],sum[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d",&n,&k);
    dp[1][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(!dp[i][j]) continue;
            add(dp[i+1][j+1],dp[i][j]);
            add(dp[i+1][j-1],1LL*dp[i][j]*j%MOD);
            add(dp[i+1][j],1LL*dp[i][j]*(i-j)%MOD);
        }
    }
    for(int i=1;i<=k;i++) part[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        sum[0]=0;
        for(int j=1;j<=n;j++) {sum[j]=sum[j-1]; add(sum[j],part[i-1][j]);}
        for(int j=i;j<=n;j++)
        {
            int l=max(1,j-k);
            part[i][j]=sum[j-1]-sum[l-1];
            add(part[i][j],MOD);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,1LL*part[i][n]*dp[i][0]%MOD);
    printf("%d\n",ans);
    return 0;
}

