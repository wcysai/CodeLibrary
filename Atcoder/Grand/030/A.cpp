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
ll a,b,c;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    ll now=min(a,c),ans=0;
    a-=now;c-=now;ans+=now;
    now=min(b,c);
    b-=now;c-=now;ans+=2*now;
    if(c>0) ans++; else ans+=b;
    printf("%lld\n",ans);
    return 0;
}

