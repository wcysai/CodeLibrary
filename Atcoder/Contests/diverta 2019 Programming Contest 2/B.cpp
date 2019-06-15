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
int n,k,a[MAXN],x[MAXN],y[MAXN];
set<P> s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&x[i],&y[i]);
        s.insert(P(x[i],y[i]));
    }
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int p=x[j]-x[i],q=y[j]-y[i];
            int cnt=0;
            for(int k=1;k<=n;k++)
                if(!s.count(P(x[k]+p,y[k]+q))) cnt++;
            ans=min(ans,cnt);
        }
    }
    printf("%d\n",ans);
    return 0;
}

