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
int n,k;;
ll a[MAXN],bas[62];
int main()
{
    int cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        ll x=a[i];
        for(int j=61;j>=0;j--)
        {
            if(x&(1LL<<j))
            {
                if(!bas[j])
                {
                    bas[j]=x;
                    cnt++;
                    break;
                }
                x^=bas[j];
            }
        }
    }
    ll ans=1;
    for(int i=0;i<cnt;i++) ans=2LL*ans;
    printf("%lld\n",ans-n);
    return 0;
}

