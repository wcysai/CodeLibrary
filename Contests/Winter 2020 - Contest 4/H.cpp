#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
ll n;
int ans[MAXN];
ll solve(ll x)
{
    if(x<=1000000) return ans[x];
    ll ret=x;
    ll dummy=x,rem=0,base=1;
    while(dummy)
    {
        rem+=(dummy%10)*base;
        dummy/=10;
        if(!dummy) break;
        if(rem!=dummy) ret=min(ret,solve(max(dummy-rem,rem-dummy)));
        base*=10;
    }
    return ret;
}
int main()
{
    for(int i=1;i<=9;i++) ans[i]=i;
    for(int i=10;i<=1000000;i++)
    {
        ans[i]=i;
        int dummy=i,rem=0,base=1;
        while(dummy)
        {
            rem+=(dummy%10)*base;
            dummy/=10;
            if(!dummy) break;
            if(rem!=dummy) ans[i]=min(ans[i],ans[max(dummy-rem,rem-dummy)]);
            base*=10;
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",solve(n));
    }
    return 0;
}