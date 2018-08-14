#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    scanf("%lld%lld",&n,&k);
    ll ans=INF;
    for(ll i=1;i<=k-1;i++)
    {
        ll num=i;
        ll cnt=0;
        while(num*3<=n)
        {
            num<<=1;
            cnt++;
        }
        num=n-num;
        while(num>k-i)
        {
            cnt++;
            num=(num+1)>>1;
        }
        ans=min(ans,cnt+1);
    }
    printf("%lld\n",ans);
    return 0;
}
