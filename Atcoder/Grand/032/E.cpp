#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
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
int n,m,a[MAXN];
bool check(int x)
{
    int sum=2*n+2*x+1;
    for(int i=2*x+1;i<=sum-i;i++)
        if(a[i]+a[sum-i]<m) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    int l=-1,r=n;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid; else l=mid;
    }
    int ans=0;
    int sum1=2*r+1,sum2=2*n+2*r+1;
    for(int i=1;i<=sum1-i;i++) ans=max(ans,(a[i]+a[sum1-i])%m);
    for(int i=2*r+1;i<=sum2-i;i++) ans=max(ans,(a[i]+a[sum2-i])%m);
    printf("%d\n",ans);
    return 0;
}

