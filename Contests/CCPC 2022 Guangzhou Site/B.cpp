#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ull,ull> P;
int n,q,a[MAXN];
ull ans[MAXN];
struct segtree
{
    P lazy1[4*MAXN],lazy2[4*MAXN];
    //lazy1: (color,add)
    //lazy2: (sum to cont,cont)
    ull sum[4*MAXN];
    int len[4*MAXN],mini[4*MAXN],maxi[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void add_mult(int k,ull v)
    {
        if(mini[k]==maxi[k])
        {
            ans[mini[k]]+=v*sum[k];
        }
        else lazy2[k].F+=v;
    }
    void add_val(int k,ull v)
    {
        if(lazy2[k].F||lazy2[k].S)
        {
            if(len[k]>1)
            {
                for(int i=k*2;i<=k*2+1;i++) 
                {
                    add_mult(i,lazy2[k].F);
                    add_cont(i,lazy2[k].S);
                }
            }
            lazy2[k]=P(0,0);
        }
        sum[k]+=1LL*len[k]*v;
        lazy1[k].S+=v;
    }
    void add_cont(int k,ull cont)
    {
        if(mini[k]==maxi[k])
        {
            ans[mini[k]]+=cont*len[k];
        }
        else lazy2[k].S+=cont;
    }
    void color(int k,int v)
    {
        if(lazy2[k].F||lazy2[k].S)
        {
            if(len[k]>1)
            {
                for(int i=k*2;i<=k*2+1;i++) 
                {
                    add_mult(i,lazy2[k].F);
                    add_cont(i,lazy2[k].S);
                }
            }
            lazy2[k]=P(0,0);
        }
        lazy1[k].F=v; mini[k]=maxi[k]=v; 
    }
    void pushdown(int k)
    {
        if(len[k]==1) return;
        if(lazy1[k].S)
        {
            for(int i=k*2;i<=k*2+1;i++) add_val(i,lazy1[k].S);
            lazy1[k].S=0;
        }
        if(lazy2[k].F||lazy2[k].S)
        {
            for(int i=k*2;i<=k*2+1;i++) 
            {
                add_mult(i,lazy2[k].F);
                add_cont(i,lazy2[k].S);
            }
            lazy2[k]=P(0,0);
        }
       
        if(lazy1[k].F)
        {
            for(int i=k*2;i<=k*2+1;i++) color(i,lazy1[k].F);
            lazy1[k].F=0;
        }
    }
    void build(int k,int l,int r)
    {
        lazy1[k]=lazy2[k]=P(0,0);
        len[k]=r-l+1;
        if(l==r) {mini[k]=maxi[k]=a[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k); 
    }
    void update_col(int k,int l,int r,int x,int y,ull v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y&&maxi[k]==mini[k]) 
        {
            color(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update_col(k*2,l,mid,x,y,v); update_col(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void update_val(int k,int l,int r,int x,int y,ull v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            add_val(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update_val(k*2,l,mid,x,y,v); update_val(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void update_cont(int k,int l,int r,int x,int y,ull v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            add_cont(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update_cont(k*2,l,mid,x,y,v); update_cont(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void update_mult(int k,int l,int r,int x,int y,ull v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            add_mult(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update_mult(k*2,l,mid,x,y,v); update_mult(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void pushy(int k,int l,int r)
    {
        if(l==r) return;
        pushdown(k);
        int mid=(l+r)/2;
        pushy(k*2,l,mid); pushy(k*2+1,mid+1,r);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int t,l,r,w;
        scanf("%d%d%d%d",&t,&l,&r,&w);
        if(t==1)
        {
            seg.update_mult(1,1,n,l,r,-1LL*(q-i));
            seg.update_col(1,1,n,l,r,w);
            seg.update_mult(1,1,n,l,r,1LL*(q-i));
        }
        else 
        {
            seg.update_cont(1,1,n,l,r,1LL*(q-i)*w);
            seg.update_val(1,1,n,l,r,w);
        }
    }
    seg.pushy(1,1,n);
    for(int i=1;i<=n;i++) printf("%llu ",ans[i]);
    return 0;
}