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
int n;
mt19937 wcy(time(NULL));
int ask()
{
    int pos=wcy()%n+1;
    printf("? %d\n",pos); fflush(stdout);
    int ret; scanf("%d",&ret);
    return ret;
}
void go(int x)
{
    printf("+ %d\n",x); fflush(stdout);
    exit(0);
}
map<int,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=99;i++) mp[ask()]++;
    int maxi=0,id=-1;
    for(auto p:mp)
    {
        if(p.S>maxi)
        {
            maxi=p.S;
            id=p.F;
        }
    }
    go(id);
    return 0;
}

