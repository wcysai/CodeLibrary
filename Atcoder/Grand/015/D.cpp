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
ll a,b;
int main()
{
    scanf("%lld%lld",&a,&b);
    int r=63-__builtin_clzll(a^b);
    ll T=(1LL<<r);
    a=a%T;b=T+b%T;
    int k=63-__builtin_clzll(b-T);
    ll ans=T-a+1;
    if(a<=(1LL<<(k+1))+1) ans+=T-1;
    else 
    {
        ans+=(1LL<<(k+1))-1;
        ans+=T-a;
    }
    printf("%lld\n",ans);
    return 0;
}

