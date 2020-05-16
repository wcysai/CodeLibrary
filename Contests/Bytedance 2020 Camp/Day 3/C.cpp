#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll lcm(int a,int b) {return 1LL*a*b/__gcd(a,b);}
int n,a[MAXN];
ll ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++) scanf("%d",&a[i]);
    ans[1]=a[1]; ans[n]=a[n-1];
    for(int i=2;i<=n-1;i++) ans[i]=lcm(a[i-1],a[i]);
    bool f=true;
    for(int i=2;i<=n;i++) if(__gcd(ans[i-1],ans[i])!=a[i-1]) f=false;
    if(!f) puts("-1");
    else
    {
        for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    }
    return 0;
}