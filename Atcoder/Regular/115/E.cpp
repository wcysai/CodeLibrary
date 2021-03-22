#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
vector<int> v;
void madd(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
struct segtree
{
    int sum[4*MAXN],len[4*MAXN];
    int lazy1[4*MAXN],lazy2[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2];
        madd(sum[k],sum[k*2+1]);
    }
    void mult(int k,int v)
    {
        sum[k]=1LL*sum[k]*v%MOD;
        lazy1[k]=1LL*lazy1[k]*v%MOD; lazy2[k]=1LL*lazy2[k]*v%MOD; 
    }
    void add(int k,int v)
    {
        madd(sum[k],1LL*len[k]*v%MOD);
        madd(lazy2[k],v);
    }
    void pushdown(int k)
    {
        for(int i=k*2;i<=k*2+1;i++) mult(i,lazy1[k]);
        lazy1[k]=1;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy2[k]);
        lazy2[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy1[k]=1; lazy2[k]=0; sum[k]=0; len[k]=(l==1?v[r-1]:v[r-1]-v[l-2]);
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update_add(int k,int l,int r,int x,int y,int val)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            add(k,val);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update_add(k*2,l,mid,x,y,val); update_add(k*2+1,mid+1,r,x,y,val);
        pushup(k);
    }
    void update_mult(int k,int l,int r,int x,int y,int val)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            mult(k,val);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update_mult(k*2,l,mid,x,y,val); update_mult(k*2+1,mid+1,r,x,y,val);
        pushup(k);
    }
    int query_sum(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        int res=query_sum(k*2,l,mid,x,y);
        madd(res,query_sum(k*2+1,mid+1,r,x,y));
        return res;
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int sz=(int)v.size();
    seg.build(1,1,sz);
    int id=lower_bound(v.begin(),v.end(),a[1])-v.begin()+1;
    seg.update_add(1,1,sz,1,id,1);
    for(int i=2;i<=n;i++)
    {
        int id=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        int sum=seg.query_sum(1,1,sz,1,sz);
        seg.update_mult(1,1,sz,1,id,MOD-1);
        seg.update_add(1,1,sz,1,id,sum);
        seg.update_mult(1,1,sz,id+1,sz,0);
    }
    int sum=seg.query_sum(1,1,sz,1,sz);
    printf("%d\n",sum);
    return 0;
}