#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
map<P,ll> mp;
ll solve(int n,int m)
{
    if((n+m)&1) return 0;
    if(n==0||m==0) return 1;
    if(mp[P(n,m)]) return mp[P(n,m)];
    if(n%2==1) return mp[P(n,m)]=4*solve(n/2,m/2);
    return mp[P(n,m)]=solve(n/2,m/2)+solve(n/2-1,m/2-1)+solve(n/2-1,m/2)+solve(n/2,m/2-1);
}
int main()
{
    freopen("chocolate.in","r",stdin);
    freopen("chocolate.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        printf("%lld\n",solve(n-1,m-1));
    }
    return 0;
}
