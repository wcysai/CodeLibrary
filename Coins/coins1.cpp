/*************************************************************************
    > File Name: coins1.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-19 10:25:44
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll dp[MAXN][MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) dp[i][i]=a[i];
    for(ll len=2;len<=n;len++)
    {
        for(ll i=1;i+len-1<=n;i++)
        {
            ll j=i+len-1;
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    if(dp[1][n]>0) puts("Alice"); else if(dp[1][n]<0) puts("Bob"); else puts("Draw");
    return 0;
}

