#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int t,n,m,p2[MAXN],a[MAXN];
int lowbit(int x) {return x&-x;}
struct segtree
{
    int cnt[4*MAXN],sum[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2];
        add(sum[k],sum[k*2+1]);
        cnt[k]=max(cnt[k*2],cnt[k*2+1]);
    }
    void addlow(int k,int l,int r)
    {
        if(cnt[k]<=1)
        {
            lazy[k]++;
            sum[k]=2LL*sum[k]%MOD;
        }
        else if(l==r)
        {
            sum[k]+=lowbit(sum[k]);
            cnt[k]=__builtin_popcount(sum[k]);
            if(cnt[k]<=1) sum[k]%=MOD;
        }
        else
        {
            int mid=(l+r)/2;
            addlow(k*2,l,mid); addlow(k*2+1,mid+1,r);
            pushup(k);
        }
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) 
        {
            sum[i]=1LL*sum[i]*p2[lazy[k]]%MOD;
            lazy[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            sum[k]=a[l];
            cnt[k]=__builtin_popcount(a[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {addlow(k,l,r); return;}
        int mid=(l+r)/2;
        pushdown(k);
        update(k*2,l,mid,x,y); update(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        pushdown(k);
        int res=query(k*2,l,mid,x,y); add(res,query(k*2+1,mid+1,r,x,y));
        return res;
    }
}seg;
int main()
{
    p2[0]=1;
    for(int i=1;i<=100000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        seg.build(1,1,n);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if(op==1) seg.update(1,1,n,l,r); else printf("%d\n",seg.query(1,1,n,l,r));
        }
    }
    return 0;
}