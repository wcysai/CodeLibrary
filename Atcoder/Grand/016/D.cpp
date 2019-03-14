#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,s,a[MAXN],b[MAXN];
map<int,int> mpa,mpb;
map<int,int> mp;
vector<int> G[MAXN];
int dfn[MAXN],low[MAXN],st[MAXN];
int vis[MAXN];
int cmp[MAXN],cnt,tot,t,V;
void add_vertex(int v)
{
    if(!mp[v])mp[v]=++V;
}
void add_edge(int u,int v)
{
    G[mp[u]].push_back(mp[v]);
    G[mp[v]].push_back(mp[u]);
}
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
        do
        {
            u=st[t-1]; t--;
            cmp[u]=cnt;
            vis[u]=2;
        }while(u!=v);
        cnt++;
    }
}
int tarjan()
{
    t=tot=cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=V;i++) if(!dfn[i]) dfs(i);
    return cnt;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s^=a[i];mpa[a[i]]++;
    }
    mpa[s]++;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        mpb[b[i]]++;
    }
    int id=-1;
    for(auto p:mpb)
    {
        if(mpa[p.F]<mpb[p.F])
        {
            puts("-1");
            return 0;
        }
    }
    for(auto p:mpa) if(mpa[p.F]>mpb[p.F]) id=p.F;
    int cnt=0;
    for(int i=1;i<=n;i++) if(a[i]!=b[i]) cnt++;
    if(cnt==0) {puts("0"); return 0;} 
    else 
    {
        add_vertex(s);add_vertex(id);
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[i])
            {
                add_vertex(a[i]);add_vertex(b[i]);
                add_edge(a[i],b[i]);
            }
        }
        printf("%d\n",tarjan()+cnt-1);
    }
    return 0;
}

