#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 500005
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
int n,k,m,s,a[MAXN],b[MAXN];
multiset<int> ms;
multiset<int> has;
vector<int> ans;
int main()
{
    scanf("%d%d%d%d",&m,&k,&n,&s);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=s;i++) scanf("%d",&b[i]);
    for(int i=1;i<=s;i++) ms.insert(b[i]);
    int l=1,r=0;
    while(l<n&&r<n)
    {
        while(ms.size()&&r<n)
        {
            r++;
            if(ms.count(a[r]))
            {
                ms.erase(ms.find(a[r]));
                has.insert(a[r]);
            }
        }
        int cnt=1;
        cnt+=(l-1)/k; cnt+=(m-r)/k;
        if(cnt>=n)
        {
            for(int i=l;i<=r;i++)
            {
                if(has.count(a[i]))
                {
                    ans.push_back(i);
                    has.erase(has.find(a[i]));
                }
            }
            cnt=n-1;
            for(int i=1;i<=min(cnt*))
        }
        if(isr[a[l]])
    }
    return 0;
}

