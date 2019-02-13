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
int n,a[MAXN];
ll sum[MAXN];
ll find_max(ll a,ll b,ll c,ll d)
{
    return max(max(a,b),max(c,d));
}
ll find_min(ll a,ll b,ll c,ll d)
{
    return min(min(a,b),min(c,d));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    ll ans=INF;
    for(int i=2;i<=n-2;i++)
    {
        ll s=sum[i];
        int id=lower_bound(sum+1,sum+i,s/2)-sum;
        ll s2=sum[n]-sum[i];
        int id2=lower_bound(sum+i+2,sum+n,s+s2/2)-sum;
        for(int j=id-1;j<=id+1;j++)
        {
            if(j>=i||j<1) continue;
            for(int k=id2-1;k<=id2+1;k++)
            {
                if(k<=i||k>=n) continue;
                ll sum1=sum[j],sum2=s-sum1,sum3=sum[k]-s,sum4=s2-sum3;
                ans=min(ans,find_max(sum1,sum2,sum3,sum4)-find_min(sum1,sum2,sum3,sum4));
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

