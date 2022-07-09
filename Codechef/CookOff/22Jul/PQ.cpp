#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,a[MAXN];
int qry[MAXN];
ll ans[MAXN],sum[MAXN];
vector<int> dis;
struct segtree
{
    P maxi[4*MAXN];
    ll sum[MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            maxi[k]=P(a[l],l);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(-INF,0);
        if(l>=x&&r<=y) return maxi[k];
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
pair<P,int> query(int l,int r)
{
    P maxi=seg.query(1,1,n,l,r);
    int pos=maxi.S,maxi2=-INF;
    if(pos>l) maxi2=max(maxi2,seg.query(1,1,n,l,pos-1).F);
    if(pos<r) maxi2=max(maxi2,seg.query(1,1,n,pos+1,r).F);
    return make_pair(maxi,maxi2);
}
void solve(int l,int r,int xl,int xr)
{
    if(l>r) return;
    //printf("l=%d r=%d xl=%d xr=%d\n",l,r,xl,xr);
    if(xl>xr) return;
    ll s=sum[r]-sum[l-1];
    if(l==r)
    {
        ans[xl]-=s; ans[xr+1]+=s;
        return;
    }
    auto p=query(l,r);
    int maxi=p.F.F,maxi2=p.S,pos=p.F.S,gap=maxi-maxi2;
    //printf("maxi=%d maxi2=%d pos=%d gap=%d\n",maxi,maxi2,pos,gap);
    if(gap>=dis[xr-1])
    {
        ans[xl]-=maxi; ans[xr+1]+=maxi;
        solve(l,pos-1,xl,xr); solve(pos+1,r,xl,xr);
        return;
    }
    if(gap<dis[xl-1])
    {
        ans[xl]+=s; ans[xr+1]-=s;
        return;
    }
    int npos=upper_bound(dis.begin()+xl-1,dis.begin()+xr,gap)-dis.begin();
    npos++;
    ans[npos]+=s; ans[xr+1]-=s;
    ans[xl]-=maxi; ans[npos]+=maxi;
    solve(l,pos-1,xl,npos-1); solve(pos+1,r,xl,npos-1);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        seg.build(1,1,n);
        dis.clear();
        for(int i=1;i<=q;i++) 
        {
            scanf("%d",&qry[i]);
            dis.push_back(qry[i]);
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=q;i++) qry[i]=lower_bound(dis.begin(),dis.end(),qry[i])-dis.begin()+1;
        int sz=(int)dis.size();
        for(int i=1;i<=sz;i++) ans[i]=0;
        solve(1,n,1,sz);
        for(int i=1;i<=sz;i++) ans[i]+=ans[i-1];
        for(int i=1;i<=q;i++) printf("%lld%c",ans[qry[i]],i==q?'\n':' ');
    }
    return 0;
}

