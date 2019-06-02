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
string str;
int n,k,a[MAXN];
int main()
{
    cin>>str;
    n=(int)str.size();
    int now=0,cnt=0;
    ll ans=0;
    while(now<n)
    {
        if(str[now]=='A') {cnt++; now++;}
        else if(str[now]=='B'&&now!=n-1&&str[now+1]=='C') {ans+=cnt; now+=2;}
        else {cnt=0; now++;}
    }
    printf("%lld\n",ans);
    return 0;
}

