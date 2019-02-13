#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
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
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) a[i]-=i;
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=n/2+1;i<=n;i++) ans+=a[i]-a[n+1-i];
    printf("%lld\n",ans);
    return 0;
}

