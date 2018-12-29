#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXLOGN 20
#define MAXM 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,c[MAXM];
struct edge {ll to,cost;};
vector<edge> G[MAXN];
ll st[MAXLOGN][2*MAXN];
ll vs[MAXN*2-1];
ll depth[MAXN*2-1],dep[MAXN];
ll id[MAXN];
bool cmp(ll u,ll v)
{
    return c[u]<c[v];
}
void dfs(ll v,ll p,ll d,ll dd,ll &k)
{
    id[v]=k;
    vs[k]=v;
    dep[v]=dd;
    depth[k++]=d;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i].to,cost=G[v][i].cost;
        if(to!=p)
        {
            dfs(to,v,d+1,dd+cost,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
ll getMin(ll x, ll y)
{
    return depth[x]<depth[y]?x:y;
}

void rmq_init(ll n)
{
    for(ll i=1;i<=n;++i) st[0][i]=i;
    for(ll i=1;1<<i<n;++i)
        for(ll j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(ll V)
{
    ll k=0;
    dfs(1,0,0,0,k);
    rmq_init(V*2-1);
}
ll query(ll l, ll r)
{
    ll k=31-__builtin_clz(r-l+1);
    return getMin(st[k][l],st[k][r-(1<<k)+1]);
}
ll lca(ll u,ll v)
{
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
ll dis(ll u,ll v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
vector<int> leaves;
ll res[(1<<MAXM)][MAXM];
ll dp[MAXM][(1<<MAXM)];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++) scanf("%lld",&c[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back((edge){v,w});
        G[v].push_back((edge){u,w});
    }
    for(ll i=2;i<=n;i++) if(G[i].size()==1) leaves.push_back(i);
    assert((int)leaves.size()<=m);
    vector<int> node;
    for(ll i=1;i<=m;i++) node.push_back(i);
    sort(node.begin(),node.end(),cmp);
    while(node.size()>leaves.size()) node.erase(node.begin()+1);
    init(n);
    m=(int)node.size();
    for(ll mask=0;mask<(1<<m)-1;mask++)
    {
        for(ll j=0;j<m;j++)
        {
            ll ans=1;
            for(ll k=0;k<m;k++)
            {
                if(!(mask&(1<<k))) continue;
                ll l=lca(leaves[k],leaves[j]);
                if(depth[id[l]]>depth[id[ans]]) ans=l;
            }
            res[mask][j]=dis(ans,leaves[j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(ll i=0;i<m;i++)
    {
        for(ll mask=0;mask<(1<<m)-1;mask++)
        {
            if(dp[i][mask]==-1) continue;
            for(ll j=0;j<m;j++)
            {
                dp[i+1][mask|(1<<j)]=max(dp[i+1][mask|(1<<j)],dp[i][mask]+c[node[i]]*res[mask][j]);
            }
        }
    }
    ll ans=0;
    for(ll mask=0;mask<(1<<m);mask++) ans=max(ans,dp[m][mask]);
    printf("%lld\n",ans);
    return 0;
}

