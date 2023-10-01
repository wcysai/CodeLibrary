#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
char str[MAXN];
struct node{
    int len,pre0,suf0,pre1,suf1,ans1,ans0;
    node() {len=pre0=suf0=pre1=suf1=ans1=ans0=0;}
    void merge(node &lhs,node &rhs){
        len=lhs.len+rhs.len;
        ans0=max(lhs.suf0+rhs.pre0,max(lhs.ans0,rhs.ans0));
        ans1=max(lhs.suf1+rhs.pre1,max(lhs.ans1,rhs.ans1));
        pre0=(lhs.pre0==lhs.len?lhs.len+rhs.pre0:lhs.pre0);
        pre1=(lhs.pre1==lhs.len?lhs.len+rhs.pre1:lhs.pre1);
        suf0=(rhs.suf0==rhs.len?rhs.len+lhs.suf0:rhs.suf0);
        suf1=(rhs.suf1==rhs.len?rhs.len+lhs.suf1:rhs.suf1);
    }
};
struct segtree{
    node res[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k){
        res[k].merge(res[k*2],res[k*2+1]);
    }
    void flip(int k){
        lazy[k]^=1;
        swap(res[k].pre0,res[k].pre1);
        swap(res[k].suf0,res[k].suf1);
        swap(res[k].ans0,res[k].ans1);
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) flip(i); 
        lazy[k]=0;
    }
    void build(int k,int l,int r){
        lazy[k]=0;
        if(l==r){
            res[k].len=1;
            res[k].pre0=res[k].suf0=res[k].ans0=(str[l]=='1'?0:1);
            res[k].pre1=res[k].suf1=res[k].ans1=(str[l]=='1'?1:0);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            flip(k);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y); update(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    node query(int k,int l,int r,int x,int y){
        if(l>y||x>r){
            node newnode;
            return newnode;
        }
        if(l>=x&&r<=y){
            return res[k];
        }
        pushdown(k);
        int mid=(l+r)/2;
        node lhs=query(k*2,l,mid,x,y);
        node rhs=query(k*2+1,mid+1,r,x,y);
        node ret;
        ret.merge(lhs,rhs);
        return ret;
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",str+1);
    seg.build(1,1,n);
    for(int i=0;i<q;i++){
        int c,l,r;
        scanf("%d%d%d",&c,&l,&r);
        if(c==1){
            seg.update(1,1,n,l,r);
        }
        else{
            node ret=seg.query(1,1,n,l,r);
            printf("%d\n",ret.ans1);
        }
    }
    return 0;
}

