#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,z,a[MAXN],nxt[MAXN];
ll ans;
set<int> s[MAXN];
struct segtree
{
    int sz[4*MAXN],minx[4*MAXN];
    ll ls[4*MAXN];
    ll get(int k,int x)
    {
        if(sz[k]==1) return min(x,minx[k]);
        else if(minx[k*2+1]>=x) return 1LL*x*sz[k*2+1]+get(k*2,x);
        else return ls[k]+get(k*2+1,x);
    }
    void pushup(int k)
    {
        minx[k]=min(minx[k*2],minx[k*2+1]);
        ls[k]=get(k*2,minx[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        sz[k]=r-l+1;
        if(l==r)
        {
            minx[k]=nxt[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int p,int v)
    {
        if(l==r)
        {
            minx[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v); else update(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    void query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            ans+=get(k,z);
            z=min(z,minx[k]);
            return;
        }
        int mid=(l+r)/2;
        query(k*2+1,mid+1,r,x,y); query(k*2,l,mid,x,y);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]++;
        s[a[i]].insert(i);
    }
    for(int i=1;i<=n;i++)
    {
        auto it=s[a[i]].find(i); ++it;
        if(it!=s[a[i]].end()) nxt[i]=*it; else nxt[i]=n+1;
    }
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int type,x,y;
        scanf("%d%d%d",&type,&x,&y);
        x++; y++;
        if(type==1)
        {
            ans=0; y--;
            z=y+1;
            seg.query(1,1,n,x,y);
            ans-=1LL*(x+y)*(y-x+1)/2;
            printf("%lld\n",ans);
        }
        else
        {
            auto it=s[a[x]].find(x); assert(it!=s[a[x]].end());
            if(it!=s[a[x]].begin())
            {
                it--;
                int id=*it;
                it++; it++;
                if(it==s[a[x]].end()) seg.update(1,1,n,id,n+1); else seg.update(1,1,n,id,*it);
                it--;
            }
            s[a[x]].erase(it);
            a[x]=y; s[a[x]].insert(x);
            it=s[a[x]].find(x);
            if(it!=s[a[x]].begin())
            {
                it--;
                int id=*it;
                seg.update(1,1,n,id,x);
                it++;
            }
            it++;
            if(it!=s[a[x]].end()) seg.update(1,1,n,x,*it); else seg.update(1,1,n,x,n+1);
        }
    }
    return 0;
}
