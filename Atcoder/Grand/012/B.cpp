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
int n,m,q,v[MAXN],d[MAXN],c[MAXN];
int color[MAXN],dis[MAXN];
bool vis[MAXN][11];
vector<int> G[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void paint(int v,int d,int c)
{
    if(vis[v][d]) return;
    vis[v][d]=true;
    if(d==0) {color[v]=c; return;}
    paint(v,d-1,c);
    for(auto to:G[v]) paint(to,d-1,c);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++) scanf("%d%d%d",&v[i],&d[i],&c[i]);
    memset(vis,false,sizeof(vis));
    for(int i=q-1;i>=0;i--) paint(v[i],d[i],c[i]);
    for(int i=1;i<=n;i++) printf("%d\n",color[i]);
    return 0;
}

