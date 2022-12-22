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
int n,q,a[MAXN];
int p10[10];
int c[10];
ll cons;
struct node{
    ll sum[10];
    int mp[10];
    node(){for(int i=0;i<=9;i++) {mp[i]=i; sum[i]=0;}}
    void merge(node x,node y)
    {
        for(int i=0;i<=9;i++) 
        {
            sum[i]=x.sum[i]+y.sum[i];
        }
    }
    void apply(int nmp[])
    {
        int tmp[10];
        ll tsum[10];
        for(int i=0;i<=9;i++) tsum[i]=0;
        for(int i=0;i<=9;i++) tsum[nmp[i]]+=sum[i];
        for(int i=0;i<=9;i++) tmp[i]=nmp[mp[i]];
        for(int i=0;i<=9;i++) {sum[i]=tsum[i]; mp[i]=tmp[i];}
    }
    void reset() {for(int i=0;i<=9;i++) mp[i]=i;}
};
struct segtree{
    node b[4*MAXN];
    void pushup(int k)
    {
        b[k].merge(b[k*2],b[k*2+1]);
    }
    void apply(int k,int a[])
    {
        b[k].apply(a);
    }
    void pushdown(int k)
    {
        for(int i=k*2;i<=k*2+1;i++) b[i].apply(b[k].mp);
        b[k].reset();
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            int cur=1;
            while(a[l])
            {
                b[k].sum[a[l]%10]+=cur;
                a[l]/=10; cur*=10;
            }
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {apply(k,c); return;}
        int mid=(l+r)/2;
        pushdown(k);
        update(k*2,l,mid,x,y); update(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    node query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) {node newnode; for(int i=0;i<=9;i++) newnode.sum[i]=0; return newnode;}
        if(l>=x&&r<=y) return b[k];
        int mid=(l+r)/2;
        pushdown(k);
        node newnode;
        for(int i=0;i<=9;i++) newnode.sum[i]=0;
        newnode.merge(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
        return newnode;
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int type,l,r,x,y;
        scanf("%d%d%d",&type,&l,&r);
        if(type==1)
        {
            scanf("%d%d",&x,&y);
            for(int i=0;i<=9;i++) c[i]=i;
            c[x]=y;
            seg.update(1,1,n,l,r);
        }
        else
        {
            node ret=seg.query(1,1,n,l,r);
            ll s=0;
            for(int i=0;i<=9;i++) s+=ret.sum[i]*i;
            printf("%lld\n",s);
        }
    }
    return 0;
}

