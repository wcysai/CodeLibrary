#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int ans;
struct segtree
{
    int maxi[4*MAXN],mini[4*MAXN];
    void pushdown(int k)
    {
        for(int i=k*2;i<=k*2+1;i++)
        {
            maxi[i]=max(maxi[k],maxi[i]);
            mini[i]=min(mini[k],mini[i]);
        }
    }
    void build(int k,int l,int r)
    {
        maxi[k]=-INF; mini[k]=INF;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            maxi[k]=max(maxi[k],v);
            mini[k]=min(mini[k],v);
            return;
        }
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v);
        update(k*2+1,mid+1,r,x,y,v);
    }
    void solve(int k,int l,int r)
    {
        if(l==r) {ans=min(ans,maxi[k]-mini[k]); return;}
        pushdown(k);
        int mid=(l+r)/2;
        solve(k*2,l,mid); solve(k*2+1,mid+1,r);
    }
}seg;
int main()
{
    ans=INF;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    seg.build(1,1,n);
    for(int i=1;i<=n/2;i++)
    {
        int to=n+1-i;
        seg.update(1,1,n,i+1,to-1,a[i]+a[to]);
        seg.update(1,1,n,1,i-1,a[i]+a[to+1]);
        seg.update(1,1,n,to,n,a[i]+a[to-1]);
    }
    seg.update(1,1,n,1,n/2,a[n/2+1]+a[n/2+2]);
    seg.update(1,1,n,n/2+2,n,a[n/2+1]+a[n/2]);
    for(int i=n/2+1;i<=n;i++)
    {
        int to=n+1-i;
        seg.update(1,1,n,to+1,i-1,a[i]+a[to]);
        seg.update(1,1,n,1,to,a[i]+a[to+1]);
        seg.update(1,1,n,i+1,n,a[i]+a[to-1]);
    }
    seg.solve(1,1,n);
    printf("%d\n",ans);
    return 0;
}

