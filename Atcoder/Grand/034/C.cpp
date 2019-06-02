#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll N,X;
ll b[MAXN],l[MAXN],u[MAXN];
vector<ll> v;
struct segtree
{
    ll sum[4*MAXN];
    ll cnt[4*MAXN];
    void pushup(ll k)
    {
        cnt[k]=cnt[k*2]+cnt[k*2+1];
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(ll k,ll l,ll r)
    {
        sum[k]=0; cnt[k]=0;
        if(l==r) return;
        ll mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(ll k,ll l,ll r,ll p,ll val)
    {
        if(l==r)
        {
            cnt[k]+=val;
            sum[k]=1LL*cnt[k]*v[l];
            return;
        }
        ll mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,val); else update(k*2+1,mid+1,r,p,val);
        pushup(k);
    }
    pair<ll,ll> query(ll k,ll l,ll r,ll s)
    {
        if(s<=0) return make_pair(0LL,0LL);
        if(l==r) 
        {
            ll need=max(0LL,(s-1)/v[l]+1);
            return make_pair(need,1LL*need*v[l]);
        }
        ll mid=(l+r)/2;
        if(sum[k*2+1]>=s) return query(k*2+1,mid+1,r,s);
        else
        {
            pair<ll,ll> p=query(k*2,l,mid,s-sum[k*2+1]);
            p.F+=cnt[k*2+1]; p.S+=sum[k*2+1];
            return p;
        }
    }
}seg;
int main()
{
    ll need=0,ans=INF;
    scanf("%lld%lld",&N,&X);
    for(ll i=1;i<=N;i++) 
    {
        scanf("%lld%lld%lld",&b[i],&l[i],&u[i]);
        need+=1LL*b[i]*l[i];
        v.push_back(1LL*X*u[i]-1LL*b[i]*(u[i]-l[i]));
    }
    v.push_back(-1);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ll sz=(int)v.size()-1;
    seg.build(1,1,sz);
    for(ll i=1;i<=N;i++)
    {
        ll res=1LL*X*u[i]-1LL*b[i]*(u[i]-l[i]);
        ll id=lower_bound(v.begin(),v.end(),res)-v.begin();
        seg.update(1,1,sz,id,1);
    }
    for(ll i=1;i<=N;i++)
    {
        ll res=1LL*X*u[i]-1LL*b[i]*(u[i]-l[i]);
        ll id=lower_bound(v.begin(),v.end(),res)-v.begin();
        seg.update(1,1,sz,id,-1);
        if(l[i]!=0)
        {
            ll r=X*l[i];
            pair<ll,ll> ret=seg.query(1,1,sz,need-r);
            ll more=min(X,(ret.S+r-need)/l[i]);
            ans=min(ans,X-more+1LL*ret.F*X);
        }
        ll cost=b[i]*(u[i]-l[i]);
        ll r=X*u[i];
        pair<ll,ll> ret=seg.query(1,1,sz,need+cost-r);
        ll more=min(X,(ret.S+r-need-cost)/u[i]);
        ans=min(ans,X-more+1LL*ret.F*X);
        seg.update(1,1,sz,id,1);
    }
    printf("%lld\n",ans);
    return 0;
}

