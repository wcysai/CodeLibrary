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
int n,m,q;
mt19937 wcy(time(NULL));
int main()
{
    n=500000; m=500000; q=500000;
    printf("%d %d %d\n",n,m,q);
    for(int i=1;i<=n;i++)
    {
        int x=wcy()%m+1;
        printf("%d\n",x);
    }
    for(int i=0;i<q;i++)
    {
        printf("%lld\n",1000000000000000000LL);
    }
    return 0;
}

