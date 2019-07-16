#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,m,k;
ll a[MAXN];
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=m;i++) scanf("%lld",&a[i]);
    ll now=1,ans=0;
    while(now<=m)
    {
        ans++;
        ll last=now;
        ll pos=((a[now]-(now-1))%k+k)%k;
        if(pos==0) pos=k;
        while(now<m&&a[now+1]-a[last]+pos<=k) now++;
        now++;
    }
    printf("%lld\n",ans);
    return 0;
}

