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
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ll mod=(1LL<<x);
        ans+=(mod-ans%mod);
        if(ans%(2*mod)==0) ans+=mod;
    }
    printf("%lld\n",ans);
    return 0;
}

