#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 5005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,a,b,p[MAXN];
ll dp[MAXN];
int main()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    for(ll i=1;i<=n;i++) scanf("%lld",&p[i]);
    fill(dp+1,dp+n+1,INF);
    dp[0]=0;
    for(ll i=1;i<=n;i++)
    {
        ll cntx=0,cnty=0;
        for(ll j=i-1;j>=0;j--)        
        {
            if(p[j]<p[i]) dp[i]=min(dp[i],dp[j]+cntx*b+cnty*a);
            if(p[j]<p[i]) cntx++; else cnty++;
        }
    }
    ll ans=INF;
    for(ll i=1;i<=n;i++) ans=min(ans,dp[i]+(n-i)*b);
    printf("%lld\n",ans);
    return 0;
}

