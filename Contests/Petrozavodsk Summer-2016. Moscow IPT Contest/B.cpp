#include<bits/stdc++.h>
#define MAXN 500005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
#define ALL ((1<<30)-1)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
struct segtree
{
    int mini[4*MAXN],mask0[4*MAXN],mask1[4*MAXN],xr[4*MAXN];
    void pushup(int k)
    {
        mask0[k]=(mask0[k*2]&mask0[k*2+1]);
        mask1[k]=(mask1[k*2]&mask1[k*2+1]);
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void pushdown(int k)
    {
        if(xr[k])
        {
            for(int i=k*2;i<=k*2+1;i++)
            {
                xr[i]^=xr[k];
                int addmask=(mask0[i]&xr[k]),decmask=(mask1[i]&xr[k]);
                mini[i]+=addmask;
                mini[i]-=decmask;
                mask0[i]^=(addmask|decmask);
                mask1[i]^=(addmask|decmask);
            }
        }
        xr[k]=0;
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            mini[k]=mask1[k]=a[l];
            mask0[k]=ALL-mask1[k];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void and_update(int k,int l,int r,int x,int y,int mask)
    {
        if(l>y||x>r||((mask&mask0[k])==mask)) return;
        mask=mask&(~mask0[k]);
        if(l>=x&&r<=y&&((mask&mask1[k])==mask))
        {
            mini[k]-=mask;
            xr[k]^=mask; mask0[k]^=mask; mask1[k]^=mask;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        and_update(k*2,l,mid,x,y,mask); and_update(k*2+1,mid+1,r,x,y,mask);
        pushup(k);
    }
    void or_update(int k,int l,int r,int x,int y,int mask)
    {
        if(l>y||x>r||((mask&mask1[k])==mask)) return;
        mask=mask&(~mask1[k]);
        if(l>=x&&r<=y&&((mask&mask0[k])==mask))
        {
            mini[k]+=mask;
            xr[k]^=mask; mask0[k]^=mask; mask1[k]^=mask;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        or_update(k*2,l,mid,x,y,mask); or_update(k*2+1,mid+1,r,x,y,mask);
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
char ch[3];
int l,r,mask;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,1,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='&')
        {
            scanf("%d%d%d",&l,&r,&mask);
            seg.and_update(1,1,n,l,r,(ALL-mask));
        }
        else if(ch[0]=='|')
        {
            scanf("%d%d%d",&l,&r,&mask);
            seg.or_update(1,1,n,l,r,mask);
        }
        else
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",seg.query(1,1,n,l,r));
        }
    }
    return 0;
}
