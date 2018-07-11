/*************************************************************************
    > File Name: 2809.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-11 15:08:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
ll n,m,q,t=0,tot=0,cnt,a[MAXN],b[MAXN],root[MAXN],st[MAXN],ed[MAXN],p[MAXN],num[MAXN],val[MAXN],ord[MAXN];
ll lson[MAXM],rson[MAXM],sum[MAXM],sz[MAXM];
bool cmp(ll x,ll y)
{
    return a[x]<a[y];
}
void merge(ll k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
    sz[k]=sz[lson[k]]+sz[rson[k]];
}
void build(ll &k,ll l,ll r)
{
    k=++tot;
    sz[k]=sum[k]=0;
    if(l==r) return;
    ll mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
}
void insert(ll &k,ll last,ll l,ll r,ll p,ll v)
{
    k=++tot;
    sum[k]=sum[last];sz[k]=sz[last];
    if(l==r) {sum[k]+=v; sz[k]++; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    ll mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,v);
    else insert(rson[k],rson[last],mid+1,r,p,v);
    merge(k);
}
ll query(ll k1,ll k2,ll l,ll r,ll num)
{
    ll s=sum[k2]-sum[k1],z=sz[k2]-sz[k1];
    if(num>=s) return z;
    if(l==r) return 0;
    ll mid=(l+r)/2;
    ll ls=sum[lson[k2]]-sum[lson[k1]],lz=sz[lson[k2]]-sz[lson[k1]];
    if(num>=ls) return lz+query(rson[k1],rson[k2],mid+1,r,num-ls);
    else return query(lson[k1],lson[k2],l,mid,num);
}
void dfs(ll v,ll p)
{
    st[v]=++t;val[t]=a[v];ord[t]=num[v];
    for(ll i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs(G[v][i],v);
    }
    ed[v]=t;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        a[i]=y;b[i]=z;p[i]=i;
        if(x!=0) {G[x].push_back(i);G[i].push_back(x);}
    }
    sort(p+1,p+n+1,cmp);
    //for(ll i=1;i<=n;i++) printf("%lld %lld\n",st[i],ed[i]);
    for(ll i=1;i<=n;i++) num[p[i]]=i;
    dfs(1,0);
    build(root[0],1,n);
    //for(ll i=1;i<=n;i++) printf("%lld %lld\n",ord[i],val[i]);
    for(ll i=1;i<=n;i++)
        insert(root[i],root[i-1],1,n,ord[i],val[i]);
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll pp=query(root[st[i]-1],root[ed[i]],1,n,m);
        //printf("%lld %lld\n",i,pp);
        ans=max(ans,b[i]*pp);
    }
    printf("%lld\n",ans);
    return 0;
}

