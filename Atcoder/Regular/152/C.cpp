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
    int g=a[2]-a[1];
    for(int i=3;i<=n;i++) g=__gcd(g,a[i]-a[i-1]);
    int ans=a[1]%(2*g)+(a[n]-a[1]);
    ans=min(ans,a[n]%(2*g)+(a[n]-a[1]));
    printf("%d\n",ans);
    return 0;
}

