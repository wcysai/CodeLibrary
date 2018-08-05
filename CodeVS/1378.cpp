/*************************************************************************
    > File Name: 1378.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 21:21:31
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,M;
vector<int> G[MAXN];
int w[MAXN];
int dp[MAXN][MAXN];
void dfs(int v)
{
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        dfs(to);
        for(int j=M+1;j>=1;j--)
            for(int k=1;k<=j;k++)
                dp[v][j]=max(dp[v][j],dp[v][j-k]+dp[to][k]);
    }
    for(int i=M+1;i>=1;i--) dp[v][i]=dp[v][i-1]+w[v];
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        int x;
        scanf("%d%d",&x,&w[i]);
        G[x].push_back(i);
    }
    dfs(0);
    printf("%d\n",dp[0][M+1]);
    return 0;
}

