#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll a,b,c,d,e,f,g;
int main()
{
    scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g);
    ll ans=0;
    int cnt=(a&1?1:0)+(d&1?1:0)+(e&1?1:0);
    if(a&&d&&e&&cnt>=2)
    {
        ans+=3;
        a--; d--; e--;
    }
    ans+=a-(a&1)+d-(d&1)+e-(e&1)+b;
    printf("%lld\n",ans);
    return 0;
}