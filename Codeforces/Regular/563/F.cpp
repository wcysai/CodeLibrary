#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 400005
#define MAXLOGN 18
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
int n,q;
int st[MAXLOGN][2*MAXN];
vector<int> G[MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
vector<int> choices;
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
int getMin(int x, int y)
{
    return depth[x]<depth[y]?x:y;
}

void rmq_init(int n)
{
    for(int i=1;i<=n;++i) st[0][i]=i;
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(1,0,0,k);
    rmq_init(V*2-1);
}
int query(int l, int r)
{
    int k=31-__builtin_clz(r-l+1);
    return getMin(st[k][l],st[k][r-(1<<k)+1]);
}
int lca(int u,int v)
{
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
int getdis()
{
    printf("d %d\n",1);
    fflush(stdout);
    int x; scanf("%d",&x);
    return x;
}
int getlca()
{
    int v=choices[0];
    for(int i=1;i<(int)choices.size();i++) v=lca(v,choices[i]);
    return v;
}
void update(int v)
{
    vector<int> tmp; tmp.clear();
    for(int i=0;i<(int)choices.size();i++) if(lca(choices[i],v)==v) tmp.push_back(choices[i]);
    choices=tmp;
}
void go()
{
    int v=getlca();
    printf("s %d\n",v);
    fflush(stdout);
    int u;
    scanf("%d",&u);
    update(u);
}
void answer(int v)
{
    printf("! %d\n",v);
    fflush(stdout);
    exit(0);
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
    init(n);
    int d=getdis();
    if(d==0) answer(1);
    for(int i=1;i<=n;i++) if(depth[id[i]]==d) choices.push_back(i);
    while(choices.size()>1) go();
    assert(choices.size()!=0);
    answer(choices[0]);
    return 0;
}

