#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000000000LL
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
ll check(ll x)
{
    for(int i=1;i<=n;i++) x-=x%a[i];
    return x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll l=0,r=INF;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(check(mid)<=2) l=mid; else r=mid;
    }
    if(check(l)!=2) {puts("-1"); return 0;}
    ll lb=0,rb=INF;
    while(rb-lb>1)
    {
        ll mid=(lb+rb)/2;
        if(check(mid)>=2) rb=mid; else lb=mid;
    }
    printf("%lld %lld\n",lb+1,l);
    return 0;
}

