#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
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
    ll ans=INF;
    for(int i=0;i<=60;i++) 
        ans=min(ans,n/(1LL<<i)+i+n%(1LL<<i));
    printf("%lld\n",ans);
}