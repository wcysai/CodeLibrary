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
int n,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        ans+=a[i];a[i]+=b[i];
    }
    sort(a,a+n,greater<int>());
    for(int i=1;i<n;i+=2) ans-=a[i];
    printf("%lld\n",ans);
    return 0;
}

