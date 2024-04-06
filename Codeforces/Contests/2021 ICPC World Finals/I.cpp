#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s,a[MAXN];
int get_dist(int x,int y){
    if(x>y) swap(x,y);
    return min(y-x,x+n-y);
}
struct segtree{
    int a[4*MAXN];//minimum of dp[i]+i
    int b[4*MAXN];//minimum of dp[i]-i
    int lazy[4*MAXN];
    void pushup(int k){
        a[k]=min(a[k*2],a[k*2+1]);
        b[k]=min(b[k*2],b[k*2+1]);
    }
    void add(int k,int v){
        a[k]+=v; b[k]+=v; lazy[k]+=v;
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r){
        lazy[k]=0;
        if(l==r){
            a[k]=get_dist(l,s)+l; b[k]=get_dist(l,s)-l;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void modify(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        modify(k*2,l,mid,x,y,v); modify(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y,int id){
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y){
            if(id==0) return a[k];
            else return b[k];
        }
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y,id),query(k*2+1,mid+1,r,x,y,id));
    }
    int get_nxt_pos(int k,int l,int r,int pos,int val){//first position x>=pos such that dp[x]-x<=val 
        if(r<pos||b[k]>val) return -1;
        if(l==r) return l;
        pushdown(k);
        int mid=(l+r)/2;
        int lans=get_nxt_pos(k*2,l,mid,pos,val);
        if(lans!=-1) return lans; else return get_nxt_pos(k*2+1,mid+1,r,pos,val);
    }
    int get_pre_pos(int k,int l,int r,int pos,int val){//last position x<=pos such that dp[x]+x<=val 
        if(l>pos||a[k]>val) return -1;
        if(l==r) return l;
        pushdown(k);
        int mid=(l+r)/2;
        int rans=get_pre_pos(k*2+1,mid+1,r,pos,val);
        if(rans!=-1) return rans; else return get_pre_pos(k*2,l,mid,pos,val);
    }
}seg;
vector<P> v;
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;i++){
        int d,t;
        scanf("%d%d",&d,&t);
        v.push_back(P(d,t));
    }
    sort(v.begin(),v.end(),greater<P>());
    seg.build(1,1,n);
   // for(int i=1;i<=n;i++) printf("%d\n",seg.query(1,1,n,i,i,0)-i);
    /*for(int i=1;i<=n;i++) printf("%d ",seg.query(1,1,n,i,i,0)-i);
    printf("\n");*/
    for(auto p:v){
        int x=p.S,y=(p.S==n?1:x+1);
        int xval=seg.query(1,1,n,x,x,0)-x,yval=seg.query(1,1,n,y,y,0)-y;
        if(xval==yval) continue;
        if(xval<yval){
            seg.modify(1,1,n,x,x,1); seg.modify(1,1,n,y,y,-1);
            swap(xval,yval);
            int z=(x==1?n:x-1),zval=seg.query(1,1,n,z,z,0)-z;
            if(zval+1<xval) seg.modify(1,1,n,x,x,-1);
            int pos=seg.get_nxt_pos(1,1,n,y+1,yval-y);
            if(pos==-1){
                seg.modify(1,1,n,y+1,n,-1);
                pos=seg.get_nxt_pos(1,1,n,1,yval-y+n);
                if(pos==-1) pos=y;
                seg.modify(1,1,n,1,pos-1,-1);
            }
            else seg.modify(1,1,n,y+1,pos-1,-1);
        }
        else{
            seg.modify(1,1,n,x,x,-1); seg.modify(1,1,n,y,y,1);
            swap(xval,yval);
            int z=(y==n?1:y+1),zval=seg.query(1,1,n,z,z,0)-z;
           // printf("zval=%d\n",zval);
            if(zval+1<yval) seg.modify(1,1,n,y,y,-1);
            int pos=seg.get_pre_pos(1,1,n,x-1,xval+x);
          //  printf("pos=%d\n",pos);
            if(pos==-1){
                seg.modify(1,1,n,1,x-1,-1);
                pos=seg.get_pre_pos(1,1,n,n,xval+x+n);
                if(pos==-1) pos=x;
                seg.modify(1,1,n,pos+1,n,-1);
            }
            else seg.modify(1,1,n,pos+1,x-1,-1);
        }
       // for(int i=1;i<=n;i++) printf("%d ",seg.query(1,1,n,i,i,0)-i);
       // printf("\n");
    }
    for(int i=1;i<=n;i++) printf("%d\n",seg.query(1,1,n,i,i,0)-i);
    return 0;
}

