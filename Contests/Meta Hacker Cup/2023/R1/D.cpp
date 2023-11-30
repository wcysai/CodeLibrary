#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,q,k,a[MAXN];
struct segtree{
    P maxi[4*MAXN],mini[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k){
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void flip(int k){
        P ma=maxi[k]; ma.F=MOD-ma.F; ma.S=-ma.S;
        P mi=mini[k]; mi.F=MOD-mi.F; mi.S=-mi.S;
        maxi[k]=mi; mini[k]=ma;
        lazy[k]^=1;
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) flip(i);
        lazy[k]=0;
    }
    void build(int k,int l,int r){
        lazy[k]=0;
        if(l==r){
            maxi[k]=P(a[l],-l); mini[k]=P(a[l],l);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y){
        if(x>r||l>y) return;
        if(l>=x&&r<=y){
            flip(k); return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y); update(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
}seg;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        seg.build(1,1,n);
        ll ans=0;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            seg.update(1,1,n,l,r);
            P p=seg.maxi[1];
            ans-=p.S;
        }
        printf("Case #%d: %lld\n",t,ans);
    }
    return 0;
}

