#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
vector<int> G[MAXN];
int st[MAXN],ed[MAXN],fa[MAXN],sz[MAXN];
ll res[MAXN],ans[MAXN];
void dfs(int v,int p)
{
    fa[v]=p; sz[v]=1;
    st[v]=++tot;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v); sz[v]+=sz[to];
    }
    ed[v]=tot;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=2;i<=n;i++)
    {
        int delta=(n-sz[i])-sz[i];
        res[1]+=sz[i];
        res[st[i]]+=delta; res[ed[i]+1]-=delta;
    }
    for(int i=1;i<=n;i++) res[i]+=res[i-1];
    for(int i=1;i<=n;i++) ans[i]=res[st[i]];
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}