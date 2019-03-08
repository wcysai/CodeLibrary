#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
ll a,b,c,d,n;
int main()
{
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&n);
    ll ans=INF;
    ans=min(ans,c*n);
    ans=min(ans,2*b*n);
    ans=min(ans,4*a*n);
    if(n&1)
    {
        ans=min(ans,n/2*d+min(c,min(2*b,4*a)));
    }
    else ans=min(ans,n/2*d);
    printf("%lld\n",ans);
    return 0;
}

