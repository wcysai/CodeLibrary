#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll a[MAXN];
int dp[MAXN][MAXN];
ll sum[MAXN];
int s[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    dp[0][0]=1;
    s[1][0]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
        for(int j=1;j<=i;j++)
            add(dp[i][j],s[j][sum[i]%j]);
        for(int j=1;j<=n;j++) add(s[j][sum[i]%j],dp[i][j-1]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}