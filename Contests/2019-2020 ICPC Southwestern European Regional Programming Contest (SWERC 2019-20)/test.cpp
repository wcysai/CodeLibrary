#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int main()
{
    scanf("%lld",&n);
    ll x=0x600DCAFE,ans=0;
    for(int i=0;i<=n-1;i++)
    {
        if(x%2==0) ans++;
        x=(x+(x>>20)+12345)%(1LL<<40);
    }
    printf("%lld\n",ans);
}