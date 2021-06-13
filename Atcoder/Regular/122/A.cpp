#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
P dp[MAXN][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[1][0]=P(1,a[1]); dp[1][1]=P(0,0);
    for(int i=2;i<=n;i++)
    {
        dp[i][0].F=dp[i-1][0].F; dp[i][0].S=dp[i-1][0].S; add(dp[i][0].S,dp[i-1][1].S);
        add(dp[i][0].F,dp[i-1][1].F);
        add(dp[i][0].S,1LL*dp[i-1][0].F*a[i]%MOD);
        add(dp[i][0].S,1LL*dp[i-1][1].F*a[i]%MOD);
        dp[i][1].F=dp[i-1][0].F; dp[i][1].S=dp[i-1][0].S;
        add(dp[i][1].S,1LL*dp[i-1][0].F*(MOD-a[i])%MOD);
    }
    int ans=dp[n][0].S;
    add(ans,dp[n][1].S);
    printf("%d\n",ans);
    return 0;
}