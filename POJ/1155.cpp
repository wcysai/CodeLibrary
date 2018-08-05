/*************************************************************************
    > File Name: 1155.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 22:56:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
struct edge{int to,cost;};
typedef long long ll;
typedef pair<int,int> P;
vector<edge> G[MAXN];
int N,M,w[MAXN],sz[MAXN];
int dp[MAXN][MAXN];
int save[MAXN];
void dfs(int v,int p)
{
    for(int i=1;i<=N;i++) dp[v][i]=-INF;
    for(int i=1;i<=N;i++) save[i]=-INF;
    save[0]=0;
    sz[v]=1;
    if(v>N-M) {dp[v][0]=0; dp[v][1]=w[v]; return;}
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,cost=G[v][i].cost;
        if(to==p) continue;
        dfs(to,v);
        for(int j=0;j<=sz[v];j++) save[j]=dp[v][j];
        for(int j=0;j<=sz[v];j++)
            for(int k=1;k<=sz[to];k++)
            {
                if(j+k>M) continue;
                dp[v][j+k]=max(dp[v][j+k],save[j]+dp[to][k]-cost);
            }
        sz[v]+=sz[to];
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N-M;i++)
    {
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;j++)
        {
            int v,cost;
            scanf("%d%d",&v,&cost);
            G[i].push_back((edge){v,cost});G[v].push_back((edge){i,cost});
        }
    }
    for(int i=N-M+1;i<=N;i++) scanf("%d",&w[i]);
    dfs(1,0);
    //for(int i=0;i<=M;i++) printf("%d ",dp[2][i]);
    //puts("");
    for(int i=M;i>=0;i--)
        if(dp[1][i]>=0) {printf("%d\n",i); return 0;}
    return 0;
}

