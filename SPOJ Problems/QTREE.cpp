#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXV 20005
#define MAXLOGV 20
using namespace std;
typedef long long ll;
struct edge{ll id,to,cost;};
ll n,q,s,t;
ll a[MAXV],b[MAXV],w[MAXV];
char type[10];
ll st[MAXLOGV][MAXV*2];
ll pre[MAXV*2];
vector<edge> G[MAXV];
ll root;
ll vs[MAXV*2-1];
ll depth[MAXV*2-1];
ll id[MAXV];
ll es[MAXV*2];
ll bit[MAXV*2];
ll sum(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x)
{
    while(i<=(n-1)*2)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void dfs(ll v,ll p,ll d,ll &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(ll i=0;i<G[v].size();i++)
    {
        edge &e=G[v][i];
        if(e.to!=p)
        {
            add(k,e.cost);
            es[e.id*2]=k;
            dfs(e.to,v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
            add(k,-e.cost);
            es[e.id*2+1]=k;
        }
    }
}
ll getMin(ll x, ll y)
{
    return depth[x] < depth[y] ? x : y;
}

void rmq_init(ll n)
{
    for(ll i=1;i<=n;++i) st[0][i]=i;
    for(ll i=1;1<<i<=n;++i)
        for(ll j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<i-1)]);
}
void init(ll V)
{
    memset(bit,0,sizeof(bit));
    ll k=0;
    dfs(root,-1,0,k);
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
    return vs[query(min(id[u],id[v]),max(id[u],id[v])+1)];
}
int main()
{
    scanf("%I64d",&t);
    while(t--)
    {    
        scanf("%I64d",&n);
        for(int i=0;i<n;i++)
            G[i].clear();
        for(ll i=0;i<n-1;i++)
            scanf("%I64d%I64d%I64d",&a[i],&b[i],&w[i]);
        root=n/2;
        for(ll i=0;i<n-1;i++)
        {
            G[a[i]-1].push_back((edge){i,b[i]-1,w[i]});
            G[b[i]-1].push_back((edge){i,a[i]-1,w[i]});
        }
        init(n);
        while(true)
        {
            ll u,v;
            scanf("%s",type);
            if(type[0]=='D') break;
            scanf("%I64d%I64d",&u,&v);
            if(type[0]=='Q')
            {
                ll p=lca(u-1,v-1);
                printf("%I64d\n",sum(id[u-1])+sum(id[v-1])-sum(id[p])*2);
            }
            else
            {
                ll k=u-1;
                add(es[k*2],v-w[k]);
                add(es[k*2+1],w[k]-v);
                w[k]=v;
            }
        }
    }
    return 0;
}
