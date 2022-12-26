#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 10000000000000000LL
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[3][MAXN];
ll sum[3][MAXN];
ll S[MAXN],T[MAXN];
int l[MAXN],r[MAXN],k[MAXN];
vector<int> v[MAXN];
ll dp[MAXN];
//max (1<=i<=j<=n) sum[0][i]+sum[2][n]-sum[2][j-1]+sum[1][j]-sum[1][i-1]-cost to cover (i,j)
//max (1<=i<=j<=n) s[i]+t[j]-cost to cover (i,j)
//dp[i]: maximum prefix cost for all segments ending at pos i
//need to find either max (l<=i<=j<=r) s[i]+t[j]-k
//or max (l-1<=i<=j<=r-1) dp[i]+t[j]-k
struct node{
    ll dp,s,t,ans1,ans2;
    node(){dp=s=t=ans1=ans2=-INF;}
    void init(int pos){s=S[pos]; t=T[pos]; ans1=s+t; dp=-INF; ans2=-INF;} 
    void merge(node &lhs,node &rhs){
        dp=max(lhs.dp,rhs.dp); s=max(lhs.s,rhs.s); t=max(lhs.t,rhs.t);
        ans1=max(max(lhs.ans1,rhs.ans1),lhs.s+rhs.t);
        ans2=max(max(lhs.ans2,rhs.ans2),lhs.dp+rhs.t);
    }
}tmp;
struct segtree{
    node a[4*MAXN];
    void build(int k,int l,int r){
        if(l==r) {a[k].init(l); return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        a[k].merge(a[k*2],a[k*2+1]);
    }
    void update(int k,int l,int r,int pos,ll v)
    {
        if(l==r) {a[k].dp=v; a[k].ans2=a[k].dp+a[k].t; return;}
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        a[k].merge(a[k*2],a[k*2+1]);
    }
    node query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return tmp;
        if(l>=x&&r<=y) return a[k];
        int mid=(l+r)/2;
        node lhs=query(k*2,l,mid,x,y),rhs=query(k*2+1,mid+1,r,x,y);
        node ret;
        ret.merge(lhs,rhs);
        return ret;
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]=sum[i][j-1]+a[i][j];
    for(int i=1;i<=n;i++) S[i]=sum[0][i]+sum[2][n]-sum[1][i-1];
    for(int i=1;i<=n;i++) T[i]=sum[1][i]-sum[2][i-1];
    ll ans=-INF;
    for(int i=1;i<=q;i++) 
    {
        scanf("%d%d%d",&l[i],&r[i],&k[i]);
        v[r[i]].push_back(i);
    }
    tmp.ans1=tmp.ans2=tmp.s=tmp.t=tmp.dp=-INF;
    seg.build(1,0,n);
    dp[0]=-INF;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-INF;
        for(auto x:v[i])
        {
            node ret=seg.query(1,0,n,l[x],r[x]);
            dp[i]=max(dp[i],ret.s-k[x]);
           // printf("dp=%lld\n",dp[i]);
            ret=seg.query(1,0,n,l[x]-1,r[x]-1);
            dp[i]=max(dp[i],ret.dp-k[x]);
           // printf("dp=%lld\n",dp[i]);
        }
        // printf("i=%d dp=%lld\n",i,dp[i]);
        seg.update(1,0,n,i,dp[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(auto x:v[i])
        {
            node ret=seg.query(1,0,n,l[x],r[x]);
            ans=max(ans,ret.ans1-k[x]);
            ret=seg.query(1,0,n,l[x]-1,r[x]);
            ans=max(ans,ret.ans2-k[x]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

