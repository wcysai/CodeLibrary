#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 2005
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
int n,s,a[MAXN];
bitset<2000*1001> bs[MAXN];
int main()
{
    scanf("%d",&n);
    s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    bs[0].set(0);
    for(int i=1;i<=n;i++) bs[i]=bs[i-1]|(bs[i-1]<<a[i]);
    for(int i=(s+1)/2;i<=s;i++)
    {
        if(bs[n][i])
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}

