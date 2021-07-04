#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
vector<int> G[MAXN];
int dp[MAXN][3];//0: deleted 1: not deleted and has neighbour 2: not deleted and no neighbour
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void dfs(int v,int p)
{
    dp[v][0]=dp[v][1]=dp[v][2]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        dp[v][0]=1LL*dp[v][0]*(dp[to][0]+dp[to][1])%MOD;
        dp[v][1]=1LL*dp[v][1]*((dp[to][0]+dp[to][1])%MOD+dp[to][2])%MOD;
        dp[v][2]=1LL*dp[v][2]*dp[to][0]%MOD;
    }
    dec(dp[v][1],dp[v][2]);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(1,0);
        int ans=dp[1][0];
        add(ans,dp[1][1]);
        printf("%d\n",ans);
    }
    return 0;
}