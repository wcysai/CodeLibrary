#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,x[MAXN],v[MAXN];
struct segtree{
    int len[4*MAXN];
    ll lazy[4*MAXN],sum[4*MAXN];
    void st(int k,ll v){
        sum[k]=1LL*len[k]*v;
        lazy[k]=v;
    }
    void pushup(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) st(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r,int v){
        len[k]=r-l+1;
        if(l==r){
            if(l==1) sum[k]=v; else sum[k]=1LL*v*n; 
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid,v); build(k*2+1,mid+1,r,v);
        pushup(k);
    }
    void modify(int k,int l,int r,int x,int y,ll v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            st(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        modify(k*2,l,mid,x,y,v); modify(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
struct segtree2{
    ll res[4*MAXN];
    ll lazy[4*MAXN],sum[4*MAXN];
    void st(int k,int v){
        sum[k]=1LL*res[k]*v;
        lazy[k]=v;
    }
    void pushup(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) st(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r,int v){
        res[k]=1LL*(l+r)*(r-l+1)/2;
        if(l==r){
            sum[k]=1LL*res[k]*v; 
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid,v); build(k*2+1,mid+1,r,v);
        pushup(k);
    }
    void modify(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            st(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        modify(k*2,l,mid,x,y,v); modify(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg2;
set<P> s;
void init(int v1,int posn){
    seg.build(1,1,n,v1);
    seg2.build(1,1,n,v1);
}
ll query_ans(int l,int r){
    return seg.query(1,1,n,l,r)-seg2.query(1,1,n,l,r);
}
void update_point(int x,int v){
    auto it=s.lower_bound(P(x,v));
    int posr=it->F;
    it--;
    int posl=it->F,vl=it->S;
    seg.modify(1,1,n,posl+1,x,1LL*vl*x);
    seg2.modify(1,1,n,posl+1,x,vl);
    seg.modify(1,1,n,x+1,posr,1LL*v*posr);
    seg2.modify(1,1,n,x+1,posr,v);
    s.insert(P(x,v));
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    int v1=1,posn=n;
    for(int i=1;i<=m;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&v[i]);
    for(int i=1;i<=m;i++){
        if(x[i]==1) {v1=v[i]; s.insert(P(x[i],v[i]));}
        else if(x[i]==n) {s.insert(P(x[i],v[i]));}
    }
    init(v1,posn);
    for(int i=1;i<=m;i++){
        if(x[i]!=1&&x[i]!=n) update_point(x[i],v[i]);
    }
    for(int i=0;i<q;i++){
        int type,x,v,l,r;
        scanf("%d",&type);
        if(type==1){
            scanf("%d%d",&x,&v);
            update_point(x,v);
        }
        else{
            scanf("%d%d",&l,&r);
            printf("%lld\n",query_ans(l,r));
        }
    }
    return 0;
}

