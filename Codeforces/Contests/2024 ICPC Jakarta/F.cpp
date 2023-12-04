#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,a[MAXN];
struct node{
    ll pre,suf,sum,ans;
    node(){pre=suf=sum=ans=0;} 
    void st(int v){
        pre=suf=sum=ans=v;
    }
    void merge(node &lhs,node &rhs){
        sum=lhs.sum+rhs.sum;
        pre=max(lhs.pre,lhs.sum+rhs.pre);
        suf=max(rhs.suf,rhs.sum+lhs.suf);
        ans=max(max(lhs.ans,rhs.ans),lhs.suf+rhs.pre);
    }
};
struct query{
    int id,l,r;
};
vector<P> upd[MAXN]; 
vector<query> qry[MAXN];
ll ans[MAXN];
struct segtree{
    node res[4*MAXN];
    void build(int k,int l,int r){
        res[k].ans=res[k].sum=res[k].pre=res[k].suf=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void pushup(int k){
        res[k].merge(res[k*2],res[k*2+1]);
    }
    void update(int k,int l,int r,int pos,int v){
        //if(l==1&&r==m) printf("update %d %d\n",pos,v);
        if(l==r){
            res[k].st(res[k].sum+v);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
        //printf("l=%d r=%d pre=%lld suf=%lld sum=%lld ans=%lld\n",l,r,res[k].pre,res[k].suf,res[k].sum,res[k].ans);
    }
    node query(int k,int l,int r,int x,int y){
        //if(k==1) printf("query %d %d\n",x,y);
        if(l>y||x>r){
            node newnode;  newnode.pre=newnode.suf=newnode.ans=-INF; return newnode;
        }
        if(l>=x&&r<=y) return res[k];
        int mid=(l+r)/2;
        node lhs=query(k*2,l,mid,x,y); node rhs=query(k*2+1,mid+1,r,x,y);
        node ret;
        ret.merge(lhs,rhs);
        return ret;
    }
}seg;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        upd[l].push_back(P(i,x)); upd[r+1].push_back(P(i,-x));
    }
    seg.build(1,1,m);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int k,s,t;
        scanf("%d%d%d",&k,&s,&t);
        qry[k].push_back((query){i,s,t});
    }
    for(int i=1;i<=n;i++){
        for(auto p:upd[i]) seg.update(1,1,m,p.F,p.S);
        for(auto p:qry[i]) ans[p.id]=seg.query(1,1,m,p.l,p.r).ans;
    }
    for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}

