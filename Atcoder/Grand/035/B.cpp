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
int n,m,tot;
vector<int> G[MAXN];
int val[MAXN];
int p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
struct node
{
    int x,y,z;
};
vector<node> ans;
int dfs(int v,int p)
{
    int last=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        int ret=dfs(to,v);
        if(ret==0)
        {
            if(last==0) last=to;
            else
            {
                ans.push_back((node){last,v,to});
                last=0;
            }
        }
        else ans.push_back((node){ret,to,v});
    }
    return last;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) val[i]=i;
    init(n);
    tot=n;
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(same(u,v))
        {
            tot++;
            val[tot]=u;
            add_edge(tot,v);
        }
        else 
        {
            unite(u,v);
            add_edge(u,v);
        }
    }
    if(dfs(1,0)) {puts("-1"); return 0;}
    for(auto p:ans) printf("%d %d\n%d %d\n",val[p.y],val[p.x],val[p.y],val[p.z]);
    return 0;
}

