#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
vector<int> divi[MAXN];
vector<int> pos[MAXN];
vector<P> upd[MAXN];
struct segtree{
    ll sum[4*MAXN];
    int len[4*MAXN],maxi[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void modify(int k,int v)
    {
        sum[k]=1LL*len[k]*v; maxi[k]=lazy[k]=v;
    }
    void pushdown(int k)
    {
        if(lazy[k]==-1) return;
        for(int i=k*2;i<=k*2+1;i++) modify(i,lazy[k]);
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1; len[k]=r-l+1;
        if(l==r) {sum[k]=maxi[k]=b[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {modify(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
    int find_gt(int k,int l,int r,int v)
    {
        if(maxi[k]<=v) return -1;
        if(l==r) return l;
        pushdown(k);
        int mid=(l+r)/2;
        if(maxi[k*2+1]>v) return find_gt(k*2+1,mid+1,r,v); else return find_gt(k*2,l,mid,v);
    }
}seg;
int main()
{
    for(int i=1;i<=200000;i++)
        for(int j=i;j<=200000;j+=i)
            divi[j].push_back(i);
    scanf("%d",&n);
    if(n==1) {puts("0"); return 0;}
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        for(auto x:divi[a[i]]) pos[x].push_back(i);
    }
    for(int i=1;i<=200000;i++){
        if(pos[i].size()>=2)
        {
            int sz=(int)pos[i].size();
            upd[pos[i][0]].push_back(P(pos[i][sz-1],i));
            upd[pos[i][1]].push_back(P(n+1,i));
            b[pos[i][sz-2]]=i;
        }
    }
    for(int i=n;i>=1;i--) b[i]=max(b[i],b[i+1]);
    seg.build(1,1,n+1);
    ll ans=seg.query(1,1,n+1,2,n-1);
    for(int i=1;i<=n-1;i++)
    {
        for(auto p:upd[i])
        {
            int pos=seg.find_gt(1,1,n+1,p.S);
            int l=pos+1,r=p.F;
            seg.update(1,1,n+1,l,r,p.S);
        }
        ans+=seg.query(1,1,n+1,i+2,i==1?n:n+1);
    }
    printf("%lld\n",ans);
    return 0;
}

