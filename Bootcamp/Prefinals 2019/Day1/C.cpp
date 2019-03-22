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
int n;
ll a[MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        ll l=0,r=INF;
        for(int i=1;i<=n;i++)
        {
            ll ll=
        }
    }
    return 0;
}

