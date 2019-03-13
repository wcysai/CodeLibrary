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
int n,m,cnt[MAXN],num[MAXN],a[MAXN];
int ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j>=max(1,i+1-cnt[i]);j--) 
            num[j]++;
    for(int i=1;i<=n;i++) if(!num[i]) ans++;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int pl=a[x]-cnt[a[x]]+1;
        cnt[a[x]]--;
        if(pl>0) {num[pl]--; if(!num[pl]) ans++;}
        a[x]=y;
        cnt[a[x]]++;
        pl=a[x]-cnt[a[x]]+1;
        if(pl>0) {num[pl]++; if(num[pl]==1) ans--;}
        printf("%d\n",ans);
    }
    return 0;
}

