#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
int main()
{
    int x=0,y=0;
    ll ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        x=max(x,a[i]);
        y=max(y,b[i]);
        ans=max(ans,1LL*b[i]*x);
        printf("%lld\n",ans);
    }
    return 0;
}