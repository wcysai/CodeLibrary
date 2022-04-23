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
int a[7];
int main()
{
    for(int i=0;i<7;i++) scanf("%d",&a[i]);
    swap(a[0],a[1]); swap(a[3],a[4]);
    int x=a[6]/(a[1]+a[2])*a[1]*a[0]+min(a[6]%(a[1]+a[2]),a[1])*a[0];
    int y=a[6]/(a[4]+a[5])*a[4]*a[3]+min(a[6]%(a[4]+a[5]),a[4])*a[3];
    if(x==y) puts("Draw"); else if(x>y) puts("Takahashi"); else puts("Aoki");
    return 0;
}

