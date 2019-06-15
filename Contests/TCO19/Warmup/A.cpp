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
int w,h,x,y,r;
int main()
{
    scanf("%d%d%d%d",&w,&h,&x,&y);
    scanf("%d",&r);
    if(r%45!=0) {puts("No"); return 0;}
    if(r%90==0) {puts("No"); return 0;}
    int g=__gcd(w,h);
    int d;
    if(r==45||r==225) d=abs(y-x); else d=(x+y);
    if(d%g!=0) puts("No"); else puts("Yes");
    return 0;
}

