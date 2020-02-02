#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int main()
{
    scanf("%d",&n);
    ll ans=1LL*n*((n-1)/2);
    if(n%3==0) ans-=2LL*(n/3);
    printf("%lld\n",ans);
    return 0;
}