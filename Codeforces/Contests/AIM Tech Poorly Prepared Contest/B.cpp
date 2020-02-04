#include<bits/stdc++.h>
#define MAXN 45005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef bitset<45005> bs;
vector<int> G[MAXN];
vector<int> order;
bool vis[MAXN];
ll ans;
int n,m;
void dfs_visit(int v)
{
    vis[v]=true;
	for(auto to:G[v]) if(!vis[to]) dfs_visit(to);
	order.push_back(v);
}
void toposort()
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs_visit(i);
}
bs dp[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[v].push_back(u);
    }
    toposort();
    for(auto x:order)
    {
        dp[x].set(x-1);
        for(auto to:G[x]) dp[x]|=dp[to];
        int cnt=dp[x].count();
        ans+=1LL*cnt*cnt;
    }
    printf("%lld\n",ans);
    return 0;
}