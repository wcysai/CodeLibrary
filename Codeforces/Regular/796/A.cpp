#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
ll sum[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        if(k<n)
        {
            ll ans=0;
            for(int i=k;i<=n;i++) ans=max(ans,sum[i]-sum[i-k]+1LL*k*(k-1)/2);
            printf("%lld\n",ans);
        }
        else
        {
            ll ans=sum[n]+1LL*k*n;
            ans-=1LL*(n+1)*n/2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}

