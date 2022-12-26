#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,s[MAXN],a[MAXN],b[MAXN];
ll ans[MAXN];
vector<P> upd[MAXN];
struct segtree{
    int sum[4*MAXN],len[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void flip(int k){
        sum[k]=len[k]-sum[k];
        lazy[k]^=1;
    }
    void pushdown(int k){
        if(lazy[k]){
            for(int i=k*2;i<=k*2+1;i++) flip(i);
            lazy[k]=0;
        }
    }
    void build(int k,int l,int r){
        len[k]=r-l+1; sum[k]=lazy[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y){
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {flip(k); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y); update(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    sort(s+1,s+n+1);
    s[n+1]=INF+1;
    for(int i=1;i<=k;i++){
        scanf("%d%d",&a[i],&b[i]);
        a[i]=lower_bound(s+1,s+n+1,a[i])-s;
        b[i]=upper_bound(s+1,s+n+1,b[i])-s-1;
        upd[a[i]].push_back(P(a[i],b[i]));
        upd[b[i]+1].push_back(P(a[i],b[i]));
    }
    seg.build(1,1,n);
    ll res=0;
    for(int i=1;i<=n;i++){
        for(auto p:upd[i]){
            seg.update(1,1,n,p.F,p.S);
        }
        ans[i]=i-1-seg.query(1,1,n,1,i-1)+seg.query(1,1,n,i+1,n);
        res+=1LL*ans[i]*(ans[i]-1)/2;
    }
    printf("%lld\n",1LL*n*(n-1)*(n-2)/6-res);
    return 0;
}

