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
ll n;
deque<int> v;
int main()
{
    scanf("%lld",&n);
    v.push_back(1);
    int cnt=1; n--;
    while(n)
    {
        if(n&1) {n--; v.push_front(++cnt);}
        else
        {
            n>>=1;
            v.push_back(++cnt);
        }
    }
    printf("%d\n",2*cnt);
    for(auto x:v) printf("%d ",x);
    for(int i=1;i<=cnt;i++) printf("%d ",i);
    puts("");
    return 0;
}

