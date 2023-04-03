#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 120005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,p[MAXN];
struct segtree{
    int lazy[4*MAXN];
    int lazy2[4*MAXN];
    P mini[4*MAXN];
    ll hsum[4*MAXN];
    void pushup(int k){
        if(mini[k*2].F==mini[k*2+1].F){
            mini[k].F=mini[k*2].F;
            mini[k].S=mini[k*2].S+mini[k*2+1].S;
        }
        else mini[k]=min(mini[k*2],mini[k*2+1]);
        hsum[k]=hsum[k*2]+hsum[k*2+1];
    }
    void add(int k,int v){
        mini[k].F+=v;
        lazy[k]+=v;
    }
    void addh(int k,int v){
        hsum[k]+=1LL*v*mini[k].S;
        lazy2[k]+=v;
    }
    void pushdown(int k){
        if(lazy[k]){
            for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
            lazy[k]=0;
        }
        if(lazy2[k]){
            for(int i=k*2;i<=k*2+1;i++){
                if(mini[i].F==mini[k].F) addh(i,lazy2[k]);
            }
            lazy2[k]=0;
        }
    }
    void build(int k,int l,int r){
        if(l==r){
            mini[k]=P(l,1);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            add(k,v); return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return hsum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
vector<int> save[MAXN];
int l[MAXN],r[MAXN];
ll ans[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    seg.build(1,1,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d",&l[i],&r[i]);
        save[r[i]].push_back(i);
    }
    vector<int> mini,maxi;
    for(int i=1;i<=n;i++){
        seg.update(1,1,n,1,i-1,-1);
        seg.update(1,1,n,i,i,-i);
        while(mini.size()&&p[mini.back()]>p[i]) {
            int rb=mini.back(),val=p[rb],lb;
            mini.pop_back();
            if(mini.size()) lb=mini.back()+1; else lb=1;
            //printf("i=%d lb=%d rb=%d val=%d\n",i,lb,rb,val-p[i]);
            seg.update(1,1,n,lb,rb,val-p[i]); 
        }
        mini.push_back(i);
        while(maxi.size()&&p[maxi.back()]<p[i]) {
            int rb=maxi.back(),val=p[rb],lb;
            maxi.pop_back();
            if(maxi.size()) lb=maxi.back()+1; else lb=1;
            //printf("i=%d lb=%d rb=%d val=%d\n",i,lb,rb,p[i]-val);
            seg.update(1,1,n,lb,rb,p[i]-val);
        }
        maxi.push_back(i);
        seg.addh(1,1);
        for(auto x:save[i]){
            ans[x]=seg.query(1,1,n,l[x],r[x]);
        }
    }
    for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}

