#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int pre[MAXN],suf[MAXN],pos[MAXN],col[MAXN];
struct segtree
{
    int mini[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            mini[k]=INF;
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
            mini[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return mini[k];
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&pos[i]);
    for(int i=1;i<=n;i++) scanf("%d",&col[i]);
    for(int i=1;i<=n;i++) if(i==1||col[i]!=col[i-1]) pre[i]=i; else pre[i]=pre[i-1]; 
    for(int i=n;i>=1;i--) if(i==n||col[i]!=col[i+1]) suf[i]=i; else suf[i]=suf[i+1];
    seg.build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int x=pre[i];
        if(x==1)
        {
            seg.update(1,1,n,i,1);
            continue;
        }
        int res=INF;
        res=min(res,seg.query(1,1,n,x,i-1)+1);
        if(x!=1)
        {
            int ub=2*pos[pre[i]]-pos[i];
            int lb=2*pos[pre[i]-1]-pos[i];
            int l=lower_bound(pos+1,pos+n+1,lb)-pos;
            int r=upper_bound(pos+1,pos+n+1,ub)-pos-1;
            r=min(r,x-1);
            l=max(l,pre[x-1]);
            res=min(res,seg.query(1,1,n,l,r)+1);
        }
        seg.update(1,1,n,i,res);
    }
    printf("%d\n",seg.query(1,1,n,pre[n],n));
    return 0;
}