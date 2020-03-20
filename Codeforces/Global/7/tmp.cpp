#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p[MAXN],q[MAXN],a[MAXN];
vector<P> v;
struct segtree
{
    P mini[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            mini[k]=P(a[k],l);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int v1,int v2)
    {
        if(l==r)
        {
            mini[k]=P(v1,v2);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v1,v2); else update(k*2+1,mid+1,r,pos,v1,v2);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(INF,0);
        if(l>=x&&r<=y) return mini[k];
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
ll ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&p[i]);
        v.push_back(P(p[i],i));
    }
    sort(v.begin(),v.end(),greater<P>());
    for(int i=1;i<=n;i++) scanf("%d",&q[i]);
    for(int i=1;i<=n;i++) a[q[i]]=i;
    seg.build(1,1,n);
    for(int i=0;i<n;i++)
    {
        int pos=v[i].S;
        P p=seg.query(1,1,n,pos,n);
        ans[p.S]+=v[i].F;
        seg.update(1,1,n,p.S,INF,0);
    }
    for(int i=n;i>=1;i++) ans[i]+=ans[i+1];
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    puts("");
    return 0;
}