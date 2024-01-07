#include<bits/stdc++.h>
#define MAXN 500005
#define MOD 1000000007
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k,a[MAXN],b[MAXN];
ll c[MAXN];
struct node{
    ll curwine,curwater,winecap,watercap;
    void init(ll x,ll y,ll z){
        curwine=min(x,y);
        curwater=min(z,x-curwine);
        winecap=y-curwine;
        watercap=winecap+(z-curwater);
        //printf("x=%lld y=%lld z=%lld %lld %lld %lld %lld\n",x,y,z,curwine,curwater,winecap,watercap);
    }
    void merge(node &ls,node &rs){
        curwine=ls.curwine+rs.curwine+min(rs.winecap,ls.curwater);
        curwater=rs.curwater+max(0LL,min(ls.curwater,rs.watercap)-rs.winecap);
        ll rem=rs.winecap-min(rs.winecap,ls.curwater);
        ll rem2=rs.watercap-min(rs.watercap,ls.curwater);
        winecap=min(INF,ls.winecap+min(ls.watercap-ls.winecap,rem));
        watercap=min(ls.watercap,rem2+ls.winecap);
    }
};
struct segtree{
    node val[4*MAXN];
    void pushup(int k) {val[k].merge(val[k*2],val[k*2+1]);}
    void build(int k,int l,int r){
        if(l==r) {
            //printf("init %d\n",l);
            val[k].init(a[l],b[l],c[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void modify(int k,int l,int r,int pos,ll x,ll y,ll z){
        if(l==r){
            val[k].init(x,y,z);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) modify(k*2,l,mid,pos,x,y,z); else modify(k*2+1,mid+1,r,pos,x,y,z);
        pushup(k);
    }
    void print(int k,int l,int r){
        int mid=(l+r)/2;
        if(l==r);
        else{
        print(k*2,l,mid); print(k*2+1,mid+1,r);}
        printf("l=%d r=%d curwine=%lld curwater=%lld winecap=%lld watercap=%lld\n",l,r,val[k].curwine,val[k].curwater,val[k].winecap,val[k].watercap);
    }
}seg;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n-1;i++) scanf("%lld",&c[i]); c[n]=INF;
    seg.build(1,1,n);
    //seg.print(1,1,n);
    for(int i=0;i<q;i++){
        int p; ll x,y,z;
        scanf("%d%lld%lld%lld",&p,&x,&y,&z);
        seg.modify(1,1,n,p,x,y,z);
        //seg.print(1,1,n);
        printf("%lld\n",seg.val[1].curwine);
    }
    return 0;
}

