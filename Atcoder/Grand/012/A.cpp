#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
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
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3*n;i++) scanf("%d",&a[i]);
    sort(a,a+3*n);
    ll ans=0;
    for(int i=3*n-2;i>=n;i-=2) ans+=a[i];
    printf("%lld\n",ans);
    return 0;
}

