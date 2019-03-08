#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define MAXD 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define next vdsofas
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m,d;
int u[MAXN],v[MAXN];
vector<int> G[MAXN];
string str[MAXN];
bool vs[MAXN][MAXD];
void dfs(int v,int cur)
{
    int next=(cur+1)%d;
    vs[v][cur]=true;
    for(auto to:G[v])
    {
        if(vs[to][next]) continue;
        dfs(to,next);
    }
}
int dfn[MAXN],low[MAXN],st[MAXN];
int vis[MAXN];
int cmp[MAXN],cnt,tot,t;
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
        int u;
        cnt++;
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
int res[MAXN],dp[MAXN],p,ans;
vector<int> GG[MAXN];
deque<int> order;
void dfs_visit(int v)
{
    vis[v]=true;
	for(auto to:GG[v])
		if(!vis[to])
			dfs_visit(to);
	order.push_front(v);
}
void toposort()
{
    memset(vis,false,sizeof(vis));
	for(int i=1;i<=p;i++)
		if(!vis[i]) dfs_visit(i);
}
void dfs2(int v)
{
    ans=max(ans,dp[v]);
    for(auto to:GG[v]) dfs2(to);
}
int main()
{
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(v[i]);
    }
    for(int i=1;i<=n;i++) cin>>str[i];
    dfs(1,0);
    ans=0;
    p=tarjan();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<d;j++) if(vs[i][j]&&str[i][j]=='1') {res[cmp[i]]++; break;}
    }
    for(int i=0;i<m;i++)
    {
        if(cmp[u[i]]!=cmp[v[i]]) GG[cmp[u[i]]].push_back(cmp[v[i]]);
    }
    toposort();
    for(int i=0;i<(int)order.size();i++)
    {
        int v=order[i];
        dp[v]=max(dp[v],res[v]);
        for(auto to:GG[v]) dp[to]=max(dp[to],dp[v]+res[to]);
    }
    dfs2(cmp[1]);
    printf("%d\n",ans);
    return 0;
}

