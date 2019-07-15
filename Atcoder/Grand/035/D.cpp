#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 19
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
int n,a[MAXN];
map<P,ll> mp[MAXN][MAXN];
void update(ll &a,ll b) {a=min(a,b);} 
ll solve(int l,int r,int xl,int xr)
{
    if(l+1==r) return 0;
    if(mp[l][r].find(P(xl,xr))!=mp[l][r].end()) return mp[l][r][P(xl,xr)];
    mp[l][r][P(xl,xr)]=INF;
    for(int mid=l+1;mid<r;mid++) update(mp[l][r][P(xl,xr)],solve(l,mid,xl,xl+xr)+solve(mid,r,xl+xr,xr)+1LL*(xl+xr)*a[mid]);
    return mp[l][r][P(xl,xr)];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    printf("%lld\n",solve(1,n,1,1)+a[1]+a[n]);
    return 0;
}

