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
int T,n,m,w[MAXN],c[MAXN];
vector<int> G[MAXN];
bool centroid[MAXN];
int sz[MAXN];
int ans;
int dp[MAXN][MAXN];
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(auto to:G[v])
    {
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(centroid[to]) continue;
        for(int j=0;j<=m;j++) dp[to][j]=dp[v][j];
        dfs(to,v);
        for(int j=w[to];j<=m;j++) dp[v][j]=max(dp[v][j],dp[to][j-w[to]]+c[to]);
    }
}

int solve(int v)
{
    int ans=0;
    memset(dp[v],0,sizeof(dp[v]));
    dfs(v,0);
    for(int j=w[v];j<=m;j++) ans=max(ans,dp[v][j-w[v]]+c[v]);
    centroid[v]=true;
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        int rt=getroot(to,v,sz[to]).S;
        ans=max(ans,solve(rt));
    }
    return ans;
}
void ac()
{
    memset(centroid,false,sizeof(centroid));
    int rt=getroot(1,0,n).S;
    printf("%d\n",solve(rt));
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&w[i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);G[v].push_back(u);
        }
        ac();
    }
    return 0;
}
