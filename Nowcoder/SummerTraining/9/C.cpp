/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-16 13:40:57
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll total=(1<<10);
ll dp[100][100],bet[100][100];
ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b);}
void solve(ll x,ll y)
{
    if(dp[x][y]!=-1) return;
    solve(x-1,y);solve(x,y-1);
    dp[x][y]=(dp[x-1][y]+dp[x][y-1])/2;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    for(ll i=1;i<=10;i++) dp[0][i]=total,dp[i][0]=-total;
    dp[0][0]=0;
    for(ll i=1;i<=9;i++)
        for(ll j=1;j<=9;j++)
            solve(i,j);
    for(ll i=1;i<=9;i++)
        for(ll j=1;j<=9;j++)
            bet[i][j]=dp[i-1][j]-dp[i][j];
    for(ll i=0;i<=9;i++)
    {
        for(ll j=0;j<=9;j++)
        {
            ll x=bet[i][j],y=total,g=gcd(x,y);
            printf("%5lld/%5lld ",x,y);
        }
        puts("");
    }
    return 0;
}

