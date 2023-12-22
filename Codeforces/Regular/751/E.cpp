#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,q,k,a[MAXN],b[MAXN];
int st[MAXN],sz[MAXN],s,t;
struct segtree{
    vector<int> len,mini;
    vector<ll> save;
    vector<int> v;
    ll f(int k,int v){
        if(len[k]==1) return min(mini[k],v);
        if(mini[k*2]<=v) return f(k*2,v)+save[k];//save[k] saves f(k*2+1,mini[k*2]);
        return 1LL*v*len[k*2]+f(k*2+1,v);
    }
    void pushup(int k){
        mini[k]=min(mini[k*2],mini[k*2+1]);
        save[k]=f(k*2+1,mini[k*2]);
    }
    void build(int k,int l,int r){
        len[k]=r-l+1;
        if(l==r) {mini[k]=v[l-1]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void init(int n,vector<int> &val){
        len.resize(4*n+1); save.resize(4*n+1); mini.resize(4*n+1);
        v=val;
        build(1,1,n);
    }
    void update(int k,int l,int r,int pos,int v){
        if(l==r){
            mini[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return P(0,v);
        if(l>=x&&r<=y){
            ll res=f(k,v);
            return P(res,min(v,mini[k]));
        }
        int mid=(l+r)/2;
        P p=query(k*2,l,mid,x,y,v);
        P q=query(k*2+1,mid+1,r,x,y,p.S);
        return make_pair(p.F+q.F,q.S);
    }
    
}seg[MAXN];
int main(){
    scanf("%d%d%d",&n,&q,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        while(s<t&&a[st[t-1]]>=a[i]) t--;
        st[t++]=i;
        b[i]=a[st[s]];
        if(st[s]==i-k+1) s++;
    }
    int num=(n+k-1)/k+1;
    for(int i=0;i<k;i++) {
        vector<int> tmp;
        for(int j=i;j<n;j+=k) tmp.push_back(b[j]);
        tmp.push_back(0);
        sz[i]=(int)tmp.size();
        seg[i].init((int)tmp.size(),tmp);
    }
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        l--; r--;
        int x=l%k,y=r%k,num=(r-l)/k+1,ed=l+(num-1)*k;
        //printf("a=%d num=%d\n",a[l],num);
        seg[x].update(1,1,sz[x],l/k+1,a[l]);
        printf("%lld\n",seg[x].query(1,1,sz[x],l/k+1,l/k+num,INF).F);
        seg[x].update(1,1,sz[x],l/k+1,b[l]);
    }
    return 0;
}

