#include<bits/stdc++.h>
#define MAXN 6005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
void add(int &a,int b) {a+=b; if(a>=m) a-=m;}
void dec(int &a,int b) {a-=b; if(a<0) a+=m;}
int dp[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    dp[0][0]=1;
    for(int i=1;i<=3*n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            add(dp[i][j],dp[i-1][j]);
            if(j)
            {
                if(i>=2) add(dp[i][j],1LL*dp[i-2][j-1]*(i-1)%m);
                if(i>=3) add(dp[i][j],1LL*dp[i-3][j-1]*(i-1)%m*(i-2)%m);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++) add(ans,dp[3*n][i]);
    printf("%d\n",ans);
    return 0;
}