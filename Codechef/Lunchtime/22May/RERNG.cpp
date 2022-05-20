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
int n,q,a[MAXN],p[MAXN];
int l[MAXN],r[MAXN];
int bit[MAXN],ans[MAXN];
vector<P> vq[MAXN];
vector<pair<P,int> > v[MAXN];
struct segtree
{
    int maxi[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            maxi[k]=-INF;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int v)
    {
        if(l==r)
        {
            maxi[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return maxi[k];
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    seg.build(1,1,n);
    for(int i=1;i<=n-1;i++)
    {
        if(p[i]<p[i+1])
        {
            int pos=seg.query(1,1,n,p[i]+1,p[i+1]-1);
            if(pos==-INF) l[i]=1; else l[i]=pos+1;
        }
        seg.update(1,1,n,p[i],i);
    }
    seg.build(1,1,n);
    for(int i=n;i>=2;i--)
    {
        if(p[i]>p[i-1])
        {
            int pos=seg.query(1,1,n,p[i-1]+1,p[i]-1);
            if(pos==-INF) r[i-1]=n; else r[i-1]=-pos-1;
        }
        seg.update(1,1,n,p[i],-i);
    }
    for(int i=1;i<=n-1;i++)
        if(p[i]<p[i+1]) 
        {
            //a in [l[i],i], b in [i+1,r[i]]
            v[l[i]].push_back(make_pair(P(i+1,r[i]),1));
            v[i+1].push_back(make_pair(P(i+1,r[i]),-1));
        }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        vq[l].push_back(P(r,i));
    }
    for(int i=1;i<=n;i++)
    {
        for(auto p:v[i])
        {
            add(p.F.F,p.S);
            add(p.F.S+1,-p.S);
        }
        for(auto p:vq[i]) ans[p.S]=p.F-i+1-sum(p.F);
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}

