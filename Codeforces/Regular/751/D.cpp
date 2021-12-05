#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,d,s[MAXN],a[MAXN],rk[MAXN];
bool cmp(int x,int y)
{
    return s[x]<s[y];
}
struct segtree
{
    int maxi[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void st(int k,int v)
    {
        maxi[k]=v;
        lazy[k]=v;
    }
    void pushdown(int k)
    {
        if(lazy[k]==-1) return;
        for(int i=k*2;i<=k*2+1;i++) st(i,lazy[k]);
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1;
        if(l==r)
        {
            if(l==0) maxi[k]=d;
            else maxi[k]=INF;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            st(k,v);
            return;
        }
        pushdown(k);
        assert(maxi[k*2+1]>=maxi[k*2]);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k); 
    }
    int find_pos(int k,int l,int r,int v)
    {
        if(l==r) return l;
        pushdown(k);
        assert(maxi[k*2+1]>=maxi[k*2]);
        int mid=(l+r)/2;
        if(maxi[k*2]>v) return find_pos(k*2,l,mid,v); else return find_pos(k*2+1,mid+1,r,v); 
    }
}seg;
int main()
{
    scanf("%d%d",&n,&d);
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<d) continue;
        if(y<=x) {ans++; continue;}
        s[++tot]=x; a[tot]=y;
    }
    n=tot;
    for(int i=1;i<=n;i++) rk[i]=i;
    sort(rk+1,rk+n+1,cmp);
    seg.build(1,0,n+1);
    for(int i=1;i<=n;i++)
    {
        int r=seg.find_pos(1,0,n+1,s[rk[i]]);
        int l=seg.find_pos(1,0,n+1,a[rk[i]]);
        l=min(l,n); r=min(r,n); l=max(l,1);
        if(l>r) continue;
        seg.update(1,0,n+1,l,r,a[rk[i]]);
    } 
    printf("%d\n",ans+seg.find_pos(1,0,n+1,INF-1)-1);
    return 0;
}