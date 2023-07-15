#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,A;
struct segtree{
    int maxi[4*MAXN],lazy[4*MAXN];
    void build(int k,int l,int r){
        lazy[k]=maxi[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void pushup(int k){
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void add(int k,int v){
        maxi[k]+=v; lazy[k]+=v;
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void update(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
vector<P> add[MAXN];
int main()
{
    scanf("%d%d%d",&n,&k,&A);
    ll cost=0;
    for(int i=1;i<=n;i++){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        cost+=c;
        add[k-y].push_back(P(x,c));
    }
    int res=0;
    for(int i=1;i<=k;i++){
        for(auto p:add[i]){
            seg.update(1,0,k,0,p.F,p.S);
        }
        res=max(res,seg.query(1,0,k,0,i-1)-i*A);
        seg.update(1,0,k,i,i,res+i*A);
    }
    printf("%d\n",cost-res);
    return 0;
}

