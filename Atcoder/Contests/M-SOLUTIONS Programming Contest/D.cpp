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
vector<int> G[MAXN];
int deg[MAXN];
vector<int> leaf;
int res[MAXN];
vector<int> v;
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    memset(used,false,sizeof(used));
    for(int i=1;i<=n;i++) if(deg[i]==1) leaf.push_back(i);
    for(int i=1;i<=n;i++)
    {
        int x; scanf("%d",&x);
        v.push_back(x);
    }
    int ans=0;
    sort(v.begin(),v.end(),greater<int>());
    for(int i=1;i<=n;i++)
    {
        assert(leaf.size());
        int u=leaf.back();
        if(i!=n) ans+=v.back();
        res[leaf.back()]=v.back();
        leaf.pop_back(); v.pop_back();
        used[u]=true;
        for(auto to:G[u])
        {
            deg[to]--;
            if(deg[to]==1) leaf.push_back(to);
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",res[i]);
    return 0;
}

