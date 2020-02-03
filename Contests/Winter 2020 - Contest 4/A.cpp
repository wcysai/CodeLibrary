#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
vector<P> v;
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
            maxi[k]=max(maxi[k],v);
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
vector<P> save;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;j++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(P(x,i));
        }
    }
    sort(v.begin(),v.end());
    seg.build(1,1,n);
    for(int i=0;i<(int)v.size();i++)
    {
        int pos=v[i].S;
        int l=pos-k-1,r=pos-1,val;
        if(l<0) l+=n;
        if(r<0) r+=n;
        if(l>r) 
        {
            val=max(seg.query(1,1,n,1,r),seg.query(1,1,n,l,n))+1;
        }
        else val=seg.query(1,1,n,l,r)+1;
        if(pos<=k+1) val=max(val,1);
        save.push_back(P(pos,val));
        if(i==v.size()-1||v[i].F!=v[i+1].F)
        {
            for(auto p:save) seg.update(1,1,n,p.F,p.S);
            save.clear();
        }
    }
    printf("%d\n",max(0,seg.query(1,1,n,1,n)));
    return 0;
}