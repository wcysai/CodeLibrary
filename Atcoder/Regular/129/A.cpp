#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,l,r;
int main()
{
    scanf("%lld%lld%lld",&n,&l,&r);
    ll ans=0;
    for(int i=60;i>=0;i--)
    {
        if(n&(1LL<<i))
        {
            ll lb=(1LL<<i),rb=(1LL<<(i+1))-1;
            lb=max(lb,l); rb=min(rb,r);
            if(lb<=rb) ans+=rb-lb+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}