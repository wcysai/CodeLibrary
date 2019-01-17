#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 155
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int dp[MAXN][MAXN][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
//restrict=
//0: can only link to l
//1: can only link to r
//2: both
int solve(int now,int rem,int flag)
{
    if(now-rem<3) return 0;
    if(rem==0) return 1;
    if(dp[now][rem][flag]!=-1) return dp[now][rem][flag];
    int &ans=dp[now][rem][flag];
    ans=0;
    add(ans,solve(now-1,rem-1,1));
    add(ans,solve(now-1,rem,1));
    if(flag)
    {
        for(int i=3;now+2-i>=3;i++)
            for(int j=0;j<=rem-1;j++)
                add(ans,1LL*solve(i,j,1)*solve(now+2-i,rem-1-j,0)%MOD);
    }
    return dp[now][rem][flag]=ans;
}
int main()
{
    scanf("%d%d",&n,&k);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(n,k-1,1));
    return 0;
}

