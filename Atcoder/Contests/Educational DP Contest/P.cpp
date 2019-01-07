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
int n,k,a[MAXN],dp[MAXN][2];
vector<int> G[MAXN];
void add(int &a,int b){a+=b; if(a>=MOD) a-=MOD;}
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int v,int p)
{
    dp[v][0]=dp[v][1]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        dp[v][0]=1LL*dp[v][0]*dp[to][1]%MOD;
        dp[v][1]=1LL*dp[v][1]*(dp[to][0]+dp[to][1])%MOD;
    }
}
int main()
{
    scanf("%d",&n);
    if(n==1) {puts("2"); return 0;}
    for(int i=0;i<n-1;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    dfs(1,0);printf("%d\n",(dp[1][0]+dp[1][1])%MOD);
    return 0;
}

