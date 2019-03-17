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
int n;
vector<int> G[MAXN];
int sz[MAXN];
bool dfs(int v,int p)
{
    sz[v]=1;
    int cnt=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(!dfs(to,v)) return false;
        if(sz[to]&1) cnt++;
        sz[v]+=sz[to];
    }
    if(cnt>1) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n%2==0&&dfs(1,0)) puts("Second"); else puts("First");
    return 0;
}

