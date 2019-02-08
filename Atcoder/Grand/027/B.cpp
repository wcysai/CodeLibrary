#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,a[MAXN];
ll sum[MAXN];
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    ll ans=LONG_LONG_MAX;
    for(int k=1;k<=n;k++)
    {
        ll res=1LL*(n+k)*x;
        int cur=n,now=5;
        int len=min(k*2,cur);
        res+=1LL*now*(sum[cur]-sum[cur-len]);
        cur-=len;
        if(res>=ans) continue;
        while(cur>0)
        {
            now+=2;
            int len=min(k,cur);
            res+=1LL*now*(sum[cur]-sum[cur-len]);
            cur-=len;
            if(res>=ans) break;
        }
        ans=min(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}

