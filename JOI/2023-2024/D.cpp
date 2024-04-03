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
int n,k,q,a[MAXN],b[MAXN],l[MAXN],r[MAXN];
struct segtree{
    int maxi[4*MAXN],lazy[4*MAXN];
    void st(int k,int v) {maxi[k]=v; lazy[k]=v;}
    void pushdown(int k){
        if(lazy[k]==0) return;
        for(int i=k*2;i<=k*2+1;i++) st(i,lazy[k]);
        lazy[k]=0;
    }
    void pushup(int k){
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r){
        lazy[k]=maxi[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void modify(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {
            st(k,v); return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        modify(k*2,l,mid,x,y,v); modify(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
vector<P> qry[MAXN];
vector<pair<P,int> > upd[MAXN];
int bit[MAXN];
int ans[MAXN];
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    seg.build(1,1,2*n);
    for(int i=1;i<=n;i++){
        l[i]=seg.query(1,1,2*n,b[i],a[i]);
        seg.modify(1,1,2*n,b[i],a[i],i);
    }
    seg.build(1,1,2*n);
    for(int i=n;i>=1;i--){
        r[i]=n+1-seg.query(1,1,2*n,b[i],a[i]);
        seg.modify(1,1,2*n,b[i],a[i],n+1-i);
    }
    seg.build(1,1,2*n);
    for(int i=1;i<=n;i++){
        upd[l[i]+1].push_back(make_pair(P(i,r[i]),1));
        upd[i+1].push_back(make_pair(P(i,r[i]),-1));
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        qry[x].push_back(P(y,i));
    }
    for(int i=1;i<=n;i++){
        for(auto p:upd[i]){
            add(p.F.F,p.S); add(p.F.S,-p.S);
        }
        for(auto p:qry[i]) ans[p.S]=sum(p.F);
    }
    for(int i=0;i<q;i++) if(!ans[i]) puts("Yes"); else puts("No");
    return 0;
}

