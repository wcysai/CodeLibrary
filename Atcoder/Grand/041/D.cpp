#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,MOD,dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d%d",&n,&MOD);
    dp[1][0]=1;
    for(int i=2;i<=n;i++)
    {
        int mult=(i<=n/2+1?i-2:n+1-i)+1;
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=mult) add(dp[i][j],dp[i][j-mult]);
        }
    }
    int ans=0;
    for(int j=0;j<=n;j++) add(ans,1LL*dp[n][j]*(n-j)%MOD);
    printf("%d\n",ans);
    return 0;
}