#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long ll;
ll n,k,query;
ll a[MAXN];
int main()
{
    scanf("%lld",&query);
    ll p=0;
    while(query--)
    {
        p++;
        scanf("%lld %lld",&n,&k);
        ll s=0;
        for(ll i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            s+=a[i];
        }
        if(s%k!=0)
        {
            printf("Case #%lld: -1\n",p);
            continue;
        }
        ll t=s/k;
        ll ans=0,cnt=0;
        s=0;
        for(ll i=0;i<n;i++)
        {
            s+=a[i];
            cnt++;
            if(s%t==0)
            {
                ans+=(cnt-1)+(s/t-1);
                s=0;
                cnt=0;
            }
        }
        printf("Case #%lld: %lld\n",p,ans);
    }
    return 0;
}
