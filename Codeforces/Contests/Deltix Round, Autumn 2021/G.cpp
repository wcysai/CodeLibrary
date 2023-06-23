#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
ll a[MAXN],b[MAXM];
ll da[MAXN],db[MAXM];
struct segtree{
    ll sum[4*MAXM],lazy[4*MAXM],maxi[4*MAXM];
    int len[4*MAXM];
    void add(int k,ll v){
        sum[k]+=len[k]*v;
        maxi[k]+=v; lazy[k]+=v;
    }
    void pushup(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r){
        len[k]=r-l+1;
        if(l==r){
            sum[k]=maxi[k]=db[l]; return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,ll v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query_sum(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query_sum(k*2,l,mid,x,y)+query_sum(k*2+1,mid+1,r,x,y);
    }
    int get_pos(int k,int l,int r,ll v){
        if(l==r) return l;
        pushdown(k);
        int mid=(l+r)/2;
        if(maxi[k*2]>=v) return get_pos(k*2,l,mid,v); else return get_pos(k*2+1,mid+1,r,v);
    }
}seg;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    ll sumb=0,b1=0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) {scanf("%lld",&b[i]); sumb+=b[i];}
    b1=b[1];
    for(int i=1;i<=n-1;i++) da[i]=a[i+1]-a[i];
    for(int i=1;i<=m-1;i++) db[i]=b[i+1]-b[i];
    seg.build(1,1,m-1);
    for(int i=0;i<q;i++){
        int type,k,d; scanf("%d%d%d",&type,&k,&d);
        if(type==1){
            for(int j=n-k+1;j<=n;j++) a[j]+=1LL*(j-n+k)*d;
            for(int j=1;j<=n-1;j++) da[j]=a[j+1]-a[j];
        }
        else{
            sumb+=1LL*k*(k+1)/2*d;
            if(k==m) b1+=d;
            seg.update(1,1,m-1,m-k,m-1,d);
        }
        int cur=1;
        ll ans=sumb;
        for(int j=1;j<=n-1;j++){
            int pos=seg.get_pos(1,1,m-1,da[j]);
            if(pos==m-1&&seg.query_sum(1,1,m-1,m-1,m-1)<da[j]) pos=m;
            ans+=a[j];
            if(pos>cur){
                ans+=1LL*(pos-cur)*a[j];
                cur=pos;
            }
            ans+=(b1+seg.query_sum(1,1,m-1,1,cur-1));
        }
        ans+=1LL*(m-cur+1)*a[n];
        printf("%lld\n",ans);
    }
    return 0;
}

