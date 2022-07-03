#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long 
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,x,w[2*MAXN];
ll sum[2*MAXN];
int num[MAXN],to[MAXN];
ll ans[MAXN];
int tot,vis[MAXN],period;
signed main()
{
    scanf("%lld%lld%lld",&n,&q,&x);
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(int i=n+1;i<=2*n;i++) w[i]=w[i-n];
    for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+w[i];
    for(int i=1;i<=n;i++)
    {
        int tmp=x/sum[n];
        int cnt=tmp*n;
        int rem=x%sum[n];
        int l=i-2,r=i+n-1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(sum[mid]-sum[i-1]>=rem) r=mid; else l=mid; 
        }
        cnt+=(r-i+1);
        to[i]=(r+1>n?r+1-n:r+1);
        num[i]=cnt;
    }
    int now=1;
    ll s=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;;i++)
    {
        vis[now]=i;
        ans[i]=num[now];
        now=to[now];
        if(vis[now])
        {
            period=i-vis[now]+1;
            tot=i;
            break;
        }
    }
    for(int i=0;i<q;i++)
    {
        ll x;
        scanf("%lld",&x);
        if(x>tot) 
        {
            ll num=(x-tot+period-1)/period;
            x-=num*period;
        }
        printf("%lld\n",ans[x]);
    }
    return 0;
}

