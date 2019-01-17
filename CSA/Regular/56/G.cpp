#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 22
#define MAXM 12
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,INV;
//dp[pos][val][mask]:
//probability that current position is pos and its value is val
//and the set of used stages is denoted by mask
//satisfying max(a_1,a_2,...,a_pos)<=curm
int dp[MAXN][3*MAXM][(1<<10)];
int p[MAXM][MAXN][3];
int ans[MAXM*3];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;} 
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
    INV=pow_mod(1000000,MOD-2);
    scanf("%d%d",&n,&m);
    for(int k=0;k<3;k++)
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&p[i][j][k]);
                p[i][j][k]=1LL*p[i][j][k]*INV%MOD;
            }
    memset(ans,0,sizeof(ans));
    for(int curm=1;curm<=3*m;curm++)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<m;k++)
            {
                for(int mask=0;mask<(1<<m)-1;mask++)
                {
                    if(mask&(1<<k)) continue;
                    for(int j=0;j<=curm;j++)
                    {
                        if(!dp[i][j][mask]) continue;
                        if(j+1<=curm) add(dp[i][j+1][mask^(1<<k)],1LL*p[k][i][0]*dp[i][j][mask]%MOD);
                        if(j+2<=curm) add(dp[i][j+2][mask^(1<<k)],1LL*p[k][i][1]*dp[i][j][mask]%MOD);
                        if(j+3<=curm) add(dp[i][j+3][mask^(1<<k)],1LL*p[k][i][2]*dp[i][j][mask]%MOD);
                    }
                }
            }
            for(int mask=0;mask<(1<<m);mask++) 
                for(int j=0;j<=curm;j++)
                    add(dp[i+1][0][mask],dp[i][j][mask]);
            if(i==n-1) for(int j=0;j<=curm;j++) add(ans[curm],dp[i][j][(1<<m)-1]);
        }
    }
    int res=0;
    for(int i=1;i<=3*m;i++) add(res,1LL*i*(ans[i]-ans[i-1]+MOD)%MOD);
    printf("%d\n",res);
    return 0;
}
