#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
char str[MAXN][MAXN];
int dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            str[i][j]='.';
    int inv3=pow_mod(3,MOD-2);
    for(int i=0;i<k;i++)
    {
        int x,y;
        char ch;
        scanf("%d %d %c",&x,&y,&ch);
        str[x][y]=ch;
    }
    dp[n][m]=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(i==n&&j==m) continue;
            if(str[i][j]=='.')
            {
                add(dp[i][j],2LL*dp[i+1][j]%MOD);
                add(dp[i][j],2LL*dp[i][j+1]%MOD);
                dp[i][j]=1LL*dp[i][j]*inv3%MOD;
            } 
            else if(str[i][j]=='R') add(dp[i][j],dp[i][j+1]);
            else if(str[i][j]=='D') add(dp[i][j],dp[i+1][j]);
            else
            {
                add(dp[i][j],dp[i][j+1]);
                add(dp[i][j],dp[i+1][j]);
            }
        }
    }
    int ans=dp[1][1];
    ans=1LL*ans*pow_mod(3,n*m-k)%MOD;
    printf("%d\n",ans);
    return 0;
}