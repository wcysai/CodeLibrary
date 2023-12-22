#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int t,n,m,K;
vector<int> l[MAXN];
struct segtree{
    int maxi[4*MAXN][11],shift[4*MAXN];
    void pushup(int k){
        for(int i=0;i<=K;i++) maxi[k][i]=max(maxi[k*2][i],maxi[k*2+1][i]);
    }
    void shft(int k,int id){
        for(int i=K;i>=0;i--){
            if(i>=id) maxi[k][i]=maxi[k][i-id]; else maxi[k][i]=-INF;
        }
        shift[k]+=id;
    }
    void pushdown(int k){
        if(!shift[k]) return;
        for(int i=k*2;i<=k*2+1;i++) shft(i,shift[k]);
        shift[k]=0;
    }
    void build(int k,int l,int r){
        shift[k]=0;
        if(l==r){
            for(int i=0;i<=K;i++) maxi[k][i]=(l==0?0:-INF);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void apply_shift(int k,int l,int r,int x,int y){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            shft(k,1); return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        apply_shift(k*2,l,mid,x,y); apply_shift(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int id,int v){
        if(l==r){
            maxi[k][id]=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,id,v); else update(k*2+1,mid+1,r,pos,id,v);
        pushup(k);
    }
    int get_maxi(int k,int l,int r,int x,int y,int id){
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return maxi[k][id];
        pushdown(k);
        int mid=(l+r)/2;
        return max(get_maxi(k*2,l,mid,x,y,id),get_maxi(k*2+1,mid+1,r,x,y,id));
    }
}seg;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&K);
        for(int i=1;i<=n;i++) l[i].clear();
        for(int i=1;i<=m;i++) {
            int lb,rb;
            scanf("%d%d",&lb,&rb);
            l[rb].push_back(lb);
        }
        seg.build(1,0,n);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=K;j++){
                int res=seg.get_maxi(1,0,n,0,i-1,j);
                seg.update(1,0,n,i,j,res+1);
            }
            for(auto p:l[i]) seg.apply_shift(1,0,n,p,i);
        }
        printf("%d\n",seg.get_maxi(1,0,n,0,n,K));
    }
    return 0;
}
