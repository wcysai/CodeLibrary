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
int n,B,C,x[MAXN],q[MAXN];
struct segtree
{
    int mini[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void add(int k,int v)
    {
        mini[k]+=v; lazy[k]+=v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r) {mini[k]=x[l]+C; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return mini[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
set<P> s;
int main()
{
    scanf("%d%d%d",&n,&B,&C);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&q[i]);
    seg.build(1,1,n);
    int dist=0;
    s.insert(P(q[1],1));
    for(int i=2;i<=n+1;i++)
    {
        int need=(i==n+1?INF:x[i]-dist);
        bool f=true;
        while(need)
        {
            if(!s.size())
            {
                f=false;
                break;
            }
            P p=*s.begin();
            //printf("F=%d S=%d\n",p.F,p.S);
            if(B<p.F)
            {
                f=false;
                break;
            }
            int x=seg.query(1,1,n,p.S,n);
            if(x==0) {s.erase(s.begin()); continue;}
            int quota=min(min(need,B/p.F),x);
            //printf("need=%d amou=%d x=%d\n",need,B/p.F,x);
            dist+=quota; B-=quota*p.F; need-=quota;
            //printf("pos=%d x=%d quota=%d dist=%d B=%d need=%d\n",p.S,x,quota,dist,B,need);
            seg.update(1,1,n,p.S,n,-quota);
        }
        if(!f) break;
        if(i<=n) s.insert(P(q[i],i));
    }
    printf("%d\n",dist);
    return 0;
}

