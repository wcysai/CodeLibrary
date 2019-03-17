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
ll A,B,C,ans;
bool go()
{
    if(A&1||B&1||C&1) return false;
    ans++;
    ll sum=A+B+C;
    A=(sum-A)/2;
    B=(sum-B)/2;
    C=(sum-C)/2;
    return true;
}
int main()
{
    scanf("%lld%lld%lld",&A,&B,&C);
    if(A==B&&B==C&&(A%2==0)) {puts("-1"); return 0;}
    while(go());
    printf("%lld\n",ans);
    return 0;
}

