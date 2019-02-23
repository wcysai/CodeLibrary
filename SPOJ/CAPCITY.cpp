#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int n,m,dfn[MAXN],low[MAXN],st[MAXN];
P E[MAXN];
int sz[MAXN];
int vis[MAXN];
int cmp[MAXN],cnt,tot,t;
vector<int> has[MAXN];
vector<int> GG[MAXN];
int dp[MAXN];
void dfs(int v)
{
    dfn[v]=low[v]=++tot;
    vis[v]=1;
    st[t++]=v;
    for(auto to:G[v])
    {
        if(!vis[to])
        {
            dfs(to);
            low[v]=min(low[v],low[to]);
        }
        else if(vis[to]==1) low[v]=min(low[v],dfn[to]);
    }
    if(dfn[v]==low[v])
    {
        cnt++;
        int u;
        do
        {
            u=st[t-1]; t--;
            cmp[u]=cnt;
            vis[u]=2;
        }while(u!=v);
    }
}
int tarjan()
{
    t=tot=cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
    return cnt;
}
deque<int> order;
void dfs_visit(int v)
{
    vis[v]=1;
	for(int i=0;i<(int)GG[v].size();i++)
	{
		int to=GG[v][i];
		if(!vis[to]) dfs_visit(to);
	}
	order.push_front(v);
}
void toposort()
{
	t=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=cnt;i++)
		if(vis[i]==0)
			dfs_visit(i);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);E[i]=P(u,v);
        G[u].push_back(v);
    }
    tarjan();
    for(int i=1;i<=n;i++)
    {
        sz[cmp[i]]++;
        has[cmp[i]].push_back(i);
    }
    for(int i=0;i<m;i++)
    {
        if(cmp[E[i].F]!=cmp[E[i].S])
        {
            GG[cmp[E[i].F]].push_back(cmp[E[i].S]);
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        sort(GG[i].begin(),GG[i].end());
        GG[i].erase(unique(GG[i].begin(),GG[i].end()),GG[i].end());
    }
    toposort();
    for(int i=0;i<(int)order.size();i++)
    {
        int v=order[i];
        dp[v]+=sz[v];
        for(auto to:GG[v])
            dp[to]+=dp[v];
    }
    vector<int> ans;
    for(int i=1;i<=cnt;i++)
        if(dp[i]==n) ans.insert(ans.end(),has[i].begin(),has[i].end());
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(int v:ans) printf("%d ",v);
    puts("");
    return 0;
}

