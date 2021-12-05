#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll x;
int main()
{
    scanf("%d",&n);
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    scanf("%lld",&x);
    ll t=x/s;
    ll ans=t*n;
    x-=t*s;
    ll ss=0;
    for(int i=1;i<=n;i++)
    {
        ss+=a[i];
        ans++;
        if(ss>x) break;
    }
    printf("%lld\n",ans);
    return 0;
}