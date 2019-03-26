#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 25
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
int main()
{
    scanf("%d",&n);
    int s=0;
    for(int i=0;i<n;i++) {scanf("%d",&a[i]); s+=a[i];}
    double ans=0;
    for(int mask=1;mask<(1<<n);mask++)
    {
        double ss=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
                cnt++;
                ss+=a[i];
            }
        }
        if(cnt&1) ans+=(double)s/ss; else ans-=(double)s/ss;
    }
    printf("%.15f\n",ans);
    return 0;
}

