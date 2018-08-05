/*************************************************************************
    > File Name: 4033.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 22:07:07
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll to,cost;};
ll n,K,sz[MAXN];
vector<edge> G[MAXN];
ll dp[MAXN][MAXN];
ll save[MAXN];
void dfs(ll v,ll p)
{
    sz[v]=1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i].to,cost=G[v][i].cost;
        if(to==p) continue;
        dfs(to,v);
        memset(save,0,sizeof(save));
        for(ll j=0;j<=min(K,sz[v]);j++)
            for(ll k=0;k<=min(K,sz[to]);k++)
            {
                if(j+k<=K)
                {
                    ll t=k*(K-k)+(sz[to]-k)*(n-K-(sz[to]-k));
                    save[j+k]=max(save[j+k],dp[v][j]+dp[to][k]+t*cost);
                }
            }
        sz[v]+=sz[to];
        for(ll j=0;j<=sz[v];j++) dp[v][j]=save[j];
    }
}
int main()
{
    scanf("%lld%lld",&n,&K);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back((edge){v,w});G[v].push_back((edge){u,w});
    }
    dfs(1,0);
    printf("%lld\n",dp[1][K]);
    return 0;
}

