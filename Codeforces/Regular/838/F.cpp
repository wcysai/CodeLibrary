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
int t,n,k,a[MAXN];
map<int,int> mp;
int up[MAXN],down[MAXN];
struct segtree{
    P mini[4*MAXN];
    int sum[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(int k,int l,int r)
    {
        if(l==r) {mini[k]=P(INF,l); sum[k]=0; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int v)
    {
        if(l==r) {mini[k]=P(v,l); sum[k]++; return;}
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    void rev_update(int k,int l,int r,int pos,int v)
    {
        if(l==r) {mini[k]=P(INF,l); sum[k]--; return;}
        int mid=(l+r)/2;
        if(pos<=mid) rev_update(k*2,l,mid,pos,v); else rev_update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(INF,0);
        if(l>=x&&r<=y) return mini[k];
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
    int query_sum(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        return query_sum(k*2,l,mid,x,y)+query_sum(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    seg.build(1,1,100000);
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }
        ll ans=0;
        for(auto p:mp)
            ans+=1LL*p.S*(p.S+1)/2;
        for(int i=n;i>=1;i--)
        {
            up[i]=down[i]=0;
            int lb=a[i]+1,rb=min(100000,a[i]+k);
            P p=seg.query(1,1,100000,lb,rb);
            if(p.F==INF) up[i]=0; else up[i]=up[p.F]+seg.query_sum(1,1,100000,a[i]+1,p.S);
            lb=max(1,a[i]-k),rb=a[i]-1;
            if(lb<=rb)
            {
                p=seg.query(1,1,100000,lb,rb);
                if(p.F==INF) down[i]=0; else down[i]=down[p.F]+seg.query_sum(1,1,100000,p.S,a[i]-1);
            }
            ans+=up[i]; ans+=down[i];
            seg.update(1,1,100000,a[i],i);
        }
        for(int i=n;i>=1;i--) seg.rev_update(1,1,100000,a[i],i);
        printf("%lld\n",ans);
    }
    return 0;
}

