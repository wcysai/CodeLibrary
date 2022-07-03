#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],x;
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    ll ans=INF;
    int mini=1000000000;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(i>x) break;
        sum+=a[i]+b[i];
        mini=min(mini,b[i]);
        ans=min(ans,sum+1LL*mini*(x-i));
    }
    printf("%lld\n",ans);
    return 0;
}

