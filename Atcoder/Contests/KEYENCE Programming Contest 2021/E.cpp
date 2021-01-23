#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,a[MAXN];
int dp[MAXN][MAXN][MAXN][2];
int solve(int l,int r,int x,int whose)//0: Snuke 1: Andy
{
    if(l==0&&r==N+1) return 0;
    if(dp[l][r][x][whose]!=-1) return dp[l][r][x][whose];
    if(whose==0)
    {
        int res=solve(l,r,x,1);
        if(x>0&&l!=0) res=max(res,solve(l-1,r,x-1,0)+a[l]);
        if(x>0&&r!=N+1) res=max(res,solve(l,r+1,x-1,0)+a[r]);
        return dp[l][r][x][whose]=res;
    }
    else
    {
        if(l==0&&r==N) return dp[l][r][x][whose]=0;
        if(l==1&&r==N+1) return dp[l][r][x][whose]=0;
        if(l==0||a[l]<a[r]) return dp[l][r][x][whose]=solve(l,r+1,x+1,0);
        else return dp[l][r][x][whose]=solve(l-1,r,x+1,0);
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=N;i++) printf("%d\n",solve(i,i+1,1,0));
    return 0;
}