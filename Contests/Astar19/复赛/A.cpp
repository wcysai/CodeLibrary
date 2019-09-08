#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
int l[MAXN],r[MAXN];
ll dp[MAXN][2];
vector<int> G[MAXN];
void dfs(int v,int p)
{
    dp[v][0]=dp[v][1]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        dp[v][0]+=max(abs(l[v]-l[to])+dp[to][0],abs(l[v]-r[to])+dp[to][1]);
        dp[v][1]+=max(abs(r[v]-l[to])+dp[to][0],abs(r[v]-r[to])+dp[to][1]);
    }
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
        for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        dfs(1,0);
        printf("%lld\n",max(dp[1][0],dp[1][1]));
    }
    return 0;
}
