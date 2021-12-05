#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
ll p10[20];
int main()
{
    p10[0]=1;
    for(int i=1;i<=16;i++) p10[i]=10LL*p10[i-1];
    scanf("%lld",&n);
    ll now=1;
    ll ans=0;
    for(int digits=1;digits<=16;digits++)
    {
        ll now=0;
        for(int lead=1;lead<=digits;lead++)
        {
            now+=p10[digits-lead];
            ll l=now,r=min(now+p10[digits-lead]-1,n);
            //range [l,r-1]
            if(r>=l) ans+=(r-l+1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}