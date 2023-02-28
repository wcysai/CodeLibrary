#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],hot[MAXN],cold[MAXN],cnt[MAXN];
struct segtree{
    ll mini[4*MAXN];
    void pushup(int k){
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void build(int k,int l,int r){
        mini[k]=INF;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int pos,ll v){
        if(l==r) {mini[k]=min(mini[k],v); return;}
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y){
        if(l>=x&&r<=y) return mini[k];
        if(l>y||x>r) return INF;
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        seg.build(1,1,k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=k;i++) scanf("%d",&cold[i]);
        for(int i=1;i<=k;i++) scanf("%d",&hot[i]);
        seg.update(1,1,k,a[1],0);
        ll ans=cold[a[1]];
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]) ans+=hot[a[i]];
            else{
                ans+=cold[a[i]];
                ll z=seg.query(1,1,k,1,k),y=seg.query(1,1,k,a[i],a[i]);
                seg.update(1,1,k,a[i-1],min(z,y+hot[a[i]]-cold[a[i]]));
            }
        }
        printf("%lld\n",ans+seg.query(1,1,k,1,k));
    }
    return 0;
}

