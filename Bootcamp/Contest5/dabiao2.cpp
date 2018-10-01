/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 18:50:07
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
int R,F,G;
int dp[MAXN];
bool used[105];
set<int> has[MAXN];
int solve(int x)
{
    if(dp[x]!=-1) return dp[x];
    if(x<F) return dp[x]=0;
    memset(used,false,sizeof(used));
    for(int i=2;i*(F-1)<x;i++)
    {
        int minx=x/i,maxx=(x-1)/i+1;
        if(minx==maxx)
        {
            int cnt=x/minx;
            if(cnt&1) has[x].insert(solve(minx));
        }
        else
        {
            int cntmax=(x-minx*i),cntmin=i-cntmax;
            int nxt=0;
            if(cntmax&1) nxt^=solve(maxx);
            if(cntmin&1) nxt^=solve(minx);
            if(nxt) has[x].insert(nxt);
        }
    }
    int ans=-1;
    for(auto it:has[x]) used[it]=true;
    for(int i=1;;i++) if(!used[i]) {ans=i; break;}
    for(auto it:has[x]) used[it]=false;
    return dp[x]=ans;
}
int main()
{
    memset(used,false,sizeof(used));
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&F)==1)
    {
        memset(dp,-1,sizeof(dp));
        for(int i=3;i<=10000;i+=2) 
        {
            if(solve(i)!=solve(i-2)) printf("%d %d\n",i,solve(i));
        }
        puts("done");
    }
    return 0;
}

