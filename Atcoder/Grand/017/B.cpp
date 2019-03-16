#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 500005
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
int n;
ll a,b,c,d;
int main()
{
    scanf("%d",&n);
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    for(int i=0;i<=n-1;i++)
    {
        ll l=a+i*c-(n-1-i)*d,r=a+i*d-(n-1-i)*c;
        if(b>=l&&b<=r) {puts("YES"); return 0;}
    }
    puts("NO");
    return 0;
}

