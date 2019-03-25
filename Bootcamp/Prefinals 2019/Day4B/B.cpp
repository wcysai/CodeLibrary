#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 8000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,q,tot,cnt,st[MAXN],ed[MAXN],root[MAXN];
ll lson[MAXM],rson[MAXM],sum[MAXM];
void merge(ll k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
}
void build(ll &k,ll l,ll r)
{
    k=++tot;
    if(l==r) {sum[k]=0; return;}
    ll mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
    merge(k);
}
void insert(ll &k,ll last,ll l,ll r,ll p,ll v)
{
    k=++tot;
    sum[k]=sum[last];
    if(l==r) {sum[k]=v; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    ll mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,v);
    else insert(rson[k],rson[last],mid+1,r,p,v);
    merge(k);
}
ll query(ll &k,ll l,ll r,ll x,ll y)
{
    if(!k) return 0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return sum[k];
    ll mid=(l+r)/2;
    return query(lson[k],l,mid,x,y)+query(rson[k],mid+1,r,x,y);
}
int main()
{
    scanf("%lld",&n);
    build(root[0],1,n+1);
    st[0]=ed[0]=1;
    for(ll i=1;i<=n;i++)
    {
        ll t,p,v;
        scanf("%lld",&t);
        if(t==1)
        {
            scanf("%lld%lld",&p,&v);
            insert(root[i],root[p],1,n+1,ed[p],v);
            st[i]=st[p]; ed[i]=ed[p]+1;
        }
        else
        {
            scanf("%lld",&p);
            assert(st[p]!=ed[p]);
            printf("%lld\n",query(root[p],1,n+1,st[p],st[p]));
            insert(root[i],root[p],1,n+1,st[p],0);
            st[i]=st[p]+1; ed[i]=ed[p];
        }
    }
    return 0;
}


