#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
int dp[MAXN][MAXN][2];
int s[MAXN][MAXN],diag[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int get_sum(int l1,int r1,int l2,int r2)
{
    int x=s[r1][r2];
    dec(x,s[l1-1][r2]);
    dec(x,s[r1][l2-1]);
    add(x,s[l1-1][l2-1]);
    return x;
}
int get_diag(int x,int y)
{
    return diag[x][y];
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    if(a>b) swap(a,b);
    dp[0][0][1]=1; 
    diag[0][0]=1;
    for(int j=0;j<=n;j++) s[0][j]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0][0]=get_sum(max(0,i-a+1),i-1,0,b-1);
        for(int j=1;j<=n;j++)
        {
            dp[i][j][1]=dp[i-1][j-1][1];
            add(dp[i][j][1],dp[i-1][j-1][0]);
            if(i>=a&&j>=a) add(dp[i][j][0],get_diag(i-a,j-a));
            if(j>=b) add(dp[i][j][0],get_sum(max(0,i-a+1),i-1,j,j));
        }
        for(int j=0;j<=n;j++)
        {
            s[i][j]=s[i-1][j];
            add(s[i][j],dp[i][j][1]);
            if(j) 
            {
                add(s[i][j],s[i][j-1]);
                dec(s[i][j],s[i-1][j-1]);
            }
            diag[i][j]=dp[i][j][1];
            if(j) add(diag[i][j],diag[i-1][j-1]);
        }
    }
    int ans=0;
    for(int i=b;i<=n;i++) 
    {
        add(ans,dp[n][i][0]);
        add(ans,dp[n][i][1]);
    }
    printf("%d\n",ans);
    return 0;
}