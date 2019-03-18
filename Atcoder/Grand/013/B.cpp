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
int n,m;
vector<int> G[MAXN];
bool vis[MAXN];
deque<int> ans;
void dfs(int v)
{
    vis[v]=true; ans.push_back(v);
    for(auto to:G[v])
    {
        if(vis[to]) continue;
        dfs(to); break;
    }
}
void extend(int v)
{
    for(auto to:G[v])
    {
        if(!vis[to])
        {
            ans.push_front(to);vis[to]=true;
            extend(to);break;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans.clear();
            dfs(i);
            if(ans.size()>1)
            {
                extend(i);
                printf("%d\n",(int)ans.size());
                for(auto v:ans) printf("%d ",v);
                return 0;
            }
        }
    }
    return 0;
}

