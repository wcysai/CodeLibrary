/*************************************************************************
    > File Name: 162.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-13 17:15:38
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
ll dp[18][2][2][2][2];//num/no leading zero/zero exist/one exist/A exist
ll dfs(ll now,ll nlead,ll zero,ll one,ll A)
{
    if(dp[now][nlead][zero][one][A]!=-1) return dp[now][nlead][zero][one][A];
    if(now==17)
    {
        if(nlead&&zero&&one&&A) return dp[now][nlead][zero][one][A]=1;
        else return dp[now][nlead][zero][one][A]=0;
    }
    if(!nlead)
    {
        ll x=dfs(now+1,0,0,0,0);
        ll y=dfs(now+1,1,0,0,0);
        ll z=dfs(now+1,1,0,1,0);
        ll p=dfs(now+1,1,0,0,1);
        return dp[now][nlead][zero][one][A]=x+13*y+z+p;
    }
    else
    {
        ll x=dfs(now+1,1,zero,one,A);
        ll y=dfs(now+1,1,1,one,A);
        ll z=dfs(now+1,1,zero,1,A);
        ll p=dfs(now+1,1,zero,one,1);
        return dp[now][nlead][zero][one][A]=x*13+y+z+p;
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    printf("%llx\n",dfs(1,0,0,0,0));
    return 0;
}

