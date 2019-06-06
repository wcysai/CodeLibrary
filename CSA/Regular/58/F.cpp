#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
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
int n;
map<P,int> mp;
vector<int> G[MAXN];
bool oncyc[MAXN];
int vis[MAXN];
int ans[MAXN],fa[MAXN];
int dp[MAXN][2];
int val[MAXN];
vector<int> cycle;
void dfs(int v,int p)
{
    vis[v]=1;
    fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p||vis[to]==2) continue;
        if(vis[to]==1)
        {
            int now=v;
            while(now!=to)
            {
                cycle.push_back(now);
                now=fa[now];
                assert(now!=0);
            }
            cycle.push_back(to);
        }
        else dfs(to,v);
    }
    vis[v]=2;
}
void compute_dp(int v,int p)
{
    dp[v][0]=dp[v][1]=0;
    int mx1=0,mx2=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(oncyc[to]) continue;
        compute_dp(to,v);
        dp[v][1]=max(dp[v][1],dp[to][1]);
        if(dp[to][0]+1>mx1)
        {
            mx2=mx1;
            mx1=dp[to][0]+1;
        }
        else if(dp[to][0]+1>mx2) mx2=dp[to][0]+1;
    }
    dp[v][0]=mx1;
    dp[v][1]=max(dp[v][1],mx1+mx2);
}
struct node
{
    int maxi,mini,maxsum;
    void init(int v,int id)
    {
        maxi=v+id;
        mini=v-id;
        maxsum=-INF;
    }
    void merge(node &lhs,node &rhs)
    {
        maxi=max(lhs.maxi,rhs.maxi);
        mini=max(lhs.mini,rhs.mini);
        maxsum=max(max(lhs.maxsum,rhs.maxsum),lhs.mini+rhs.maxi);
    }
};
struct segtree
{
    node tnode[4*MAXN];
    void pushup(int k)
    {
        tnode[k].merge(tnode[k*2],tnode[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r) 
        {
            tnode[k].init(val[l],l);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    node query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return (node){-INF,-INF,-INF};
        if(l>=x&&r<=y) return tnode[k];
        int mid=(l+r)/2;
        node newnode=(node){-INF,-INF,-INF};
        node node1=query(k*2,l,mid,x,y),node2=query(k*2+1,mid+1,r,x,y);
        newnode.merge(node1,node2);
        return newnode;
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        assert(!mp[P(u,v)]);
        G[u].push_back(v); G[v].push_back(u);
        mp[P(u,v)]=mp[P(v,u)]=i;
    }
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    dfs(1,0);
    memset(oncyc,false,sizeof(oncyc));
    for(auto v:cycle) oncyc[v]=true;
    int res=0;
    for(auto v:cycle) 
    {
        compute_dp(v,0);
        res=max(res,dp[v][1]);
    }
    int sz=(int)cycle.size();
    for(int i=0;i<2*sz;i++)
    {
        val[i+1]=dp[cycle[i%sz]][0];
    }
    seg.build(1,1,2*sz); 
    for(int i=0;i<sz;i++)
    {
        int last=cycle[(i-1+sz)%sz],now=cycle[i],id=mp[P(last,now)];
        ans[id]=seg.query(1,1,2*sz,1+i,sz+i).maxsum;
        ans[id]=max(ans[id],res);
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}

