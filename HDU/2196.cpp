/*************************************************************************
    > File Name: 2196.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 20:12:53
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
struct edge{int to,cost;};
int n,k,a[MAXN];
vector<edge> G[MAXN];
int dp[MAXN][2];
void dfs1(int v,int p)
{
    dp[v][0]=0;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,cost=G[v][i].cost;
        if(to==p) continue;
        dfs1(to,v);
        dp[v][0]=max(dp[v][0],dp[to][0]+cost);
    }
}
void dfs2(int v,int p)
{
    int mx=0,mx2=0;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,cost=G[v][i].cost;
        if(to==p) continue;
        int res=cost+dp[to][0];
        if(res>mx)
        {
            mx2=mx;
            mx=res;
        }
        else if(res>mx2) mx2=res;
    }
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,cost=G[v][i].cost;
        if(to==p) continue;
        dp[to][1]=max(dp[to][1],dp[v][1]+cost);
        if(cost+dp[to][0]==mx) dp[to][1]=max(dp[to][1],mx2+cost);
        else dp[to][1]=max(dp[to][1],mx+cost);
        dfs2(to,v);
    }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        memset(dp,0,sizeof(dp));for(int i=1;i<=n;i++) G[i].clear();
        for(int i=2;i<=n;i++)
        {
            int v,cost;
            scanf("%d%d",&v,&cost);
            G[i].push_back((edge){v,cost});G[v].push_back((edge){i,cost});
        }
        dfs1(1,0);dfs2(1,0);
        for(int i=1;i<=n;i++) printf("%d\n",max(dp[i][0],dp[i][1]));
    }
    return 0;
}

