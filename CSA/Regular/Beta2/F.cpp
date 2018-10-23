/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-16 10:54:22
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
int n,k,a[MAXN];
vector<int> G[MAXN];
int dp[MAXN][4];
void dfs(int v,int p)
{
    dp[v][0]=dp[v][2]=0;dp[v][1]=-INF;
    int sum=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        dp[v][2]+=max(dp[to][1]+1,dp[to][0]);
        sum+=dp[to][0];
    }
    dp[v][0]=max(dp[v][0],sum);
    if(G[v].size()>1) dp[v][1]=max(dp[v][1],sum);
    int cnt=0,minx1=INF,minx2=INF,minx3=INF;
    sum=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        minx3=min(minx3,dp[to][0]-dp[to][3]);
        if(dp[to][3]>=dp[to][0]) {cnt++; sum+=dp[to][3];}
        else
        {
            sum+=dp[to][0];
            if(dp[to][0]-dp[to][3]<minx1)
            {
                minx2=minx1;
                minx1=dp[to][0]-dp[to][3];
            }
            else if(dp[to][0]-dp[to][3]<minx2) minx2=dp[to][0]-dp[to][3];
        }
    }
    if(cnt>=2) dp[v][0]=max(dp[v][0],sum+1);
    else if(cnt==1) dp[v][0]=max(dp[v][0],sum-minx1+1);
    else dp[v][0]=max(dp[v][0],sum-minx1-minx2+1);
    if(G[v].size()>1) dp[v][1]-=minx3;
    dp[v][3]=max(dp[v][1],dp[v][2]);
    printf("%d %d %d %d %d\n",v,dp[v][0],dp[v][1],dp[v][2],dp[v][3]);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",max(dp[1][0],dp[1][3]));
    return 0;
}

