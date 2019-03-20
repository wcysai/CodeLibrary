#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1000005
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
int n,m[MAXN],l[MAXN];
vector<int> G[MAXN];
vector<int> root;
int sum[MAXN];
ll ans=0;
void dfs(int v)
{
    sum[v]=m[v];
    vector<int> costs;
    for(auto to:G[v])
    {
        dfs(to);costs.push_back(sum[to]);
        sum[v]+=sum[to];
    }
    sort(costs.begin(),costs.end());
    int sz=(int)costs.size();
    for(int i=0;i<sz;i++) ans+=1LL*(sz-1-i)*costs[i];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&m[i],&l[i]);
        if(l[i]==-1) root.push_back(i);
        else G[l[i]+1].push_back(i);
    }
    for(auto v:root) dfs(v);
    printf("%lld\n",ans);
    return 0;
}

