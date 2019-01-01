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
ll n,r1,r2,a[MAXN],b[MAXN],dis2;
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&r1);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%lld",&r2);
    for(ll i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(ll i=1;i<=n;i++) dis2+=(b[i]-a[i])*(b[i]-a[i]);
    if((r1+r2)*(r1+r2)==dis2) puts("1");
    else if(dis2<(r2-r1)*(r2-r1)) puts("0");
    else if(dis2>(r2+r1)*(r2+r1)) puts("0");
    else if((r2-r1)*(r2-r1)==dis2&&r1!=r2) puts("1");
    else if((r2-r1)*(r2-r1)==dis2&&r1==r2) puts("-1");
    else if(n==2) puts("2"); else puts("-1");
    return 0;
}

