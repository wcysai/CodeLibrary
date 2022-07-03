#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll n;
ll p10[MAXN];
ll construct(ll x,int times)
{
    int d=0;
    for(int i=1;;i++)
    {
        if(p10[i]>x)
        {
            d=i;
            break;
        }
    }
    ll now=0;
    for(int i=1;i<=times;i++)
    {
        now=now*p10[d];
        now+=x;
    }
    return now;
}
int main()
{
    p10[0]=1;
    for(int i=1;i<=18;i++) p10[i]=10LL*p10[i-1];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll ans=0;
        for(int i=2;i<=18;i++)
        {
            int digit=18/i;
            ll r=p10[digit];
            ll l=0;
            while(r-l>1)
            {
                ll mid=(l+r)/2;
                if(construct(mid,i)<=n) l=mid; else r=mid;
            }
            ans=max(ans,construct(l,i));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

