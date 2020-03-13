#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,t,a[MAXN];
ll sum[MAXN],ssum[MAXN];
P st[MAXN];
int pre[MAXN],suf[MAXN];
ll presum[MAXN],sufsum[MAXN];
map<pair<int,int>,ll> mp;
ll solve(int l,int r)
{
    if(l==0&&r==n) return 0;
    if(mp.find(make_pair(l,r))!=mp.end()) return mp[make_pair(l,r)];
    int cur=r-l-1;
    int lpos=pre[l],rpos=suf[r];
    ll res=0;
    ll lsum=sum[l]-sum[lpos],rsum=sum[rpos]-sum[r];
    if(l!=0&&(r==n||lsum*(rpos-r)<rsum*(l-lpos)))
    {
        res+=presum[l];
        cur+=l-lpos;
        res+=(n-1-cur)*lsum; 
        return mp[make_pair(l,r)]=res+solve(lpos,r);
    }
    else
    {
        res+=sufsum[r];
        cur+=rpos-r;
        res+=(n-1-cur)*rsum;
        return mp[make_pair(l,r)]=res+solve(l,rpos);
    }
}
void add(ll u,ll v)
{
    P p=P(u,v);
    while(t>1&&(st[t-1].F-st[t-2].F)*(p.S-st[t-1].S)>=(st[t-1].F-p.F)*(st[t-2].S-st[t-1].S)) t--;
    st[t++]=p;
}
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    t=0;
    for(int i=1;i<=n;i++) 
    {
        sum[i]=sum[i-1]+a[i];
        ssum[i]=ssum[i-1]+1LL*a[i]*i;
    }
    add(0,0);
    for(int i=1;i<=n;i++)
    {
        add(i,sum[i]);
        pre[i]=st[t-2].F;
        presum[i]=ssum[i]-ssum[pre[i]]-(sum[i]-sum[pre[i]])*pre[i];
    }
    t=0;
    add(0,0);
    for(int i=n-1;i>=0;i--)
    {
        add(n-i,sum[n]-sum[i]);
        suf[i]=n-st[t-2].F;
        sufsum[i]=(suf[i]+1)*(sum[suf[i]]-sum[i])-(ssum[suf[i]]-ssum[i]);
    }
    for(int i=1;i<=n;i++) printf("%lld ",solve(i-1,i)+1LL*a[i]*(n-1));
    puts("");
    return 0;
}