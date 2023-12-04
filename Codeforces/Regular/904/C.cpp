#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,l[MAXN],r[MAXN];
vector<P> upd[MAXN];
vector<int> dis;
struct segtree{
    int lazy[4*MAXN],mini[4*MAXN];
    void pushup(int k){
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void add(int k,int v){
        mini[k]+=v; lazy[k]+=v;
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r){
        lazy[k]=0;
        if(l==r) {mini[k]=0; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        //printf("k=%d l=%d r=%d x=%d y=%d v=%d\n",k,l,r,x,y,v);
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return mini[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        dis.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&l[i],&r[i]);
            if(l[i]>1) dis.push_back(l[i]-1); 
            dis.push_back(l[i]); dis.push_back(r[i]); if(r[i]+1<=m) dis.push_back(r[i]+1); 
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        int sz=(int)dis.size();
        for(int i=1;i<=sz+1;i++) upd[i].clear();
        for(int i=0;i<n;i++){
            l[i]=lower_bound(dis.begin(),dis.end(),l[i])-dis.begin()+1;
            r[i]=lower_bound(dis.begin(),dis.end(),r[i])-dis.begin()+1;
            upd[l[i]].push_back(P(i,1)); upd[r[i]+1].push_back(P(i,-1));
        }
        seg.build(1,1,sz);
        int ans=0;
        for(int i=1;i<=sz;i++){
            for(auto p:upd[i]){
                if(p.S==1) seg.update(1,1,sz,l[p.F],r[p.F],1); else seg.update(1,1,sz,l[p.F],r[p.F],-1);
            }
            ans=max(ans,seg.query(1,1,sz,i,i)-seg.query(1,1,sz,1,sz));
        }
        printf("%d\n",ans);
    }
    return 0;
}

