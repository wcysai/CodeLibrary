#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int T,n;
int a[MAXN],b[MAXN];
ll s[MAXN];
struct segtree
{
    int mini[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void add(int k,int v)
    {
        mini[k]+=v;
        lazy[k]+=v;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            mini[k]=b[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r)
    {
        if(l==r) return l;
        int mid=(l+r)/2;
        pushdown(k);
        if(mini[k*2]<=0) return query(k*2,l,mid); else return query(k*2+1,mid+1,r);
    }
}seg;
priority_queue<P> pq;
__int128 ans;
void print(__int128 x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
int main()
{
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        b[n+1]=0;
        while(pq.size()) pq.pop();
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        seg.build(1,1,n+1);
        for(int i=1;i<=n;i++) pq.push(make_pair(s[i],i));
        ll ans=0;
        int cur=seg.query(1,1,n+1);
        for(int i=1;i<=b[1];i++)
        {
            while(pq.top().S>=cur) pq.pop();            
            int pos=pq.top().S;
            ans+=s[pos];
            seg.update(1,1,n+1,1,pos,-1);
            cur=seg.query(1,1,n+1);
        }
        printf("Case #%d: %d ",_,b[1]);
        print(ans);
        printf("\n");
    }
}