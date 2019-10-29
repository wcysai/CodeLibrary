#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
ll K;
int l[MAXN],r[MAXN];
ll p[MAXN];
vector<P> v[MAXN];
struct segtree
{
    P maxi[4*MAXN];
    ll lazy[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++)
        {
            lazy[i]+=lazy[k];
            maxi[i].F+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            maxi[k]=P(K*l,l);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void add(int k,int l,int r,int x,int y,ll v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            maxi[k].F+=v;
            lazy[k]+=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        add(k*2,l,mid,x,y,v); add(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(-INF,-1);
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d%lld",&n,&K);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%lld",&l[i],&r[i],&p[i]);
        v[r[i]].push_back(P(l[i],p[i]));
    }
    ll ans=0;
    int maxl=-1,maxr=-1;
    seg.build(1,1,200000);
    for(int i=1;i<=200000;i++)
    {
        for(auto x:v[i]) seg.add(1,1,200000,1,x.F,x.S);
        P res=seg.query(1,1,200000,1,i);
        if(res.F-1LL*K*(i+1)>ans)
        {
            ans=res.F-1LL*K*(i+1);
            maxr=i;
            maxl=res.S;
        }
    }
    if(ans==0) puts("0");
    else
    {
        int m=0;
        vector<int> ids;
        for(int i=1;i<=n;i++)
        {
            if(l[i]>=maxl&&r[i]<=maxr)
            {
                m++;
                ids.push_back(i);
            }
        }
        printf("%lld %d %d %d\n",ans,maxl,maxr,m);
        for(auto x:ids) printf("%d ",x);
    }
    return 0;
}
