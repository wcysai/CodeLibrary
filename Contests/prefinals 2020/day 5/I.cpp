#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define int long long
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
P a[MAXN];
bool check(int x)
{
    int cur=a[1].F;
    for(int i=2;i<=n;i++)
    {
        if(cur+x>a[i].F+a[i].S) return false;
        cur=max(cur+x,a[i].F);
    }
    return true;
}
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].F,&a[i].S);
    sort(a+1,a+n+1);
    int l=0,r=2*INF+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%lld\n",l);
    return 0;
}