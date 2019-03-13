#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define MAXH 405
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
int n,h,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int indeg[MAXH],outdeg[MAXH];
bool vis[MAXH];
vector<int> G[MAXH];
void add_edge(int u,int v)
{
    outdeg[u]++;indeg[v]++;
    G[u].push_back(v);G[v].push_back(u);
}
bool dfs(int v)
{
    bool f=indeg[v]!=outdeg[v];
    vis[v]=true;
    for(auto to:G[v]) if(!vis[to]) f|=dfs(to);
    return f;
}
int main()
{
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        int l,r;
        if(c[i]==0) l=a[i]; else l=-c[i];
        if(d[i]==0) r=-b[i]; else r=d[i];
        add_edge(l+h,r+h);
    }
    bool f=true;
    for(int i=0;i<=h;i++) if(outdeg[i]>indeg[i]) f=false;
    for(int i=h+1;i<=2*h;i++) if(indeg[i]>outdeg[i]) f=false;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=2*h;i++) if((indeg[i]||outdeg[i])&&!vis[i]) f&=dfs(i);
    if(f) puts("YES"); else puts("NO");
    return 0;
}

