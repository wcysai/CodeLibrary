/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-14 22:11:53
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
vector<double> dp[MAXN];
void solve(int n)
{
    if(dp[n].size()!=0) return;
    dp[n].resize(n);
    if(n==1) {dp[n][0]=1.0; return;}
    for(int i=0;i<n;i++) dp[n][i]+=n;
    if(n&1)
    {
        solve(n/2);solve((n+1)/2);
        for(int i=0;i<n/2;i++) dp[n][i]+=dp[n/2][i]/2;
        for(int i=n/2;i<n;i++) dp[n][i]+=dp[(n+1)/2][i-n/2]/2;
        for(int i=0;i<(n+1)/2;i++) dp[n][i]+=dp[(n+1)/2][i]/2;
        for(int i=(n+1)/2;i<n;i++) dp[n][i]+=dp[n/2][i-(n+1)/2]/2;
    }
    else
    {
        solve(n/2);
        for(int i=0;i<n/2;i++) dp[n][i]+=dp[n/2][i];
        for(int i=n/2;i<n;i++) dp[n][i]+=dp[n/2][i-n/2];
    }
}
int n;
int main()
{
    scanf("%d",&n);
    solve(n);
    for(int i=0;i<n;i++) printf("%.10f ",dp[n][i]);
    return 0;
}

