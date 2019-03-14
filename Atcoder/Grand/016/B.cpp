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
int n,k,a[MAXN];
void die()
{
    puts("No");
    exit(0);
}
int main()
{
    scanf("%d",&n);
    int mini=INF,maxi=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mini=min(mini,a[i]);maxi=max(maxi,a[i]);
    }
    if(maxi-mini>1) die();
    else if(maxi==mini)
    {
        if(maxi*2>n&&maxi!=n-1) die();
    }
    else
    {
        int cnt=0;
        for(int i=1;i<=n;i++) if(a[i]==mini) cnt++;
        if(cnt+(n-cnt)/2<maxi||cnt+1>maxi) die();
    }
    puts("Yes");
    return 0;
}

