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
int n,m,t,a[MAXN];
vector<int> G[MAXN],rG[MAXN];
int d[MAXN],f[MAXN],p[MAXN],color[MAXN],dp[MAXN];
deque<int> order;
void dfs_visit(int v)
{
	d[v]=++t;
	color[v]=1;
	for(int i=0;i<(int)G[v].size();i++)
	{
		int to=G[v][i];
		if(color[to]==0)
		{
			p[to]=v;
			dfs_visit(to);
		}
	}
	color[v]=2;
	order.push_front(v);
	f[v]=++t;
}
void toposort()
{
	t=0;
	memset(color,0,sizeof(color));
	memset(p,-1,sizeof(p));
	for(int i=1;i<=n;i++)
		if(color[i]==0)
			dfs_visit(i);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    toposort();
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(auto v:order)
    {
        for(auto to:rG[v]) dp[v]=max(dp[v],dp[to]+1);
        ans=max(ans,dp[v]);
    }
    printf("%d\n",ans);
    return 0;

}

