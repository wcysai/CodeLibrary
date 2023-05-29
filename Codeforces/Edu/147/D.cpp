#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],l[MAXN],r[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&l[i]);
        for(int i=1;i<=n;i++) scanf("%d",&r[i]);
        ll ans=INF;
        ll cnt=0,num=0;
        for(int i=1;i<=n;i++){
            ll len=r[i]-l[i]+1;
            if(cnt+len>=k){
                ll need=max(1LL,k-cnt);
                ll canskip=min(num,cnt+len-k);
                ll rem=cnt+need-k;
                ll cost=1LL*(l[i]+need-1)+2*i-2*min(canskip,rem)-(canskip-min(canskip,rem));
                ans=min(ans,cost);
            }
            if(len==1) num++;
            cnt+=len;
        }
        if(cnt>=k) printf("%lld\n",ans); else puts("-1");
    }
    return 0;
}

