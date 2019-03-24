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
int n,m,deg[MAXN],u[MAXN],v[MAXN];
vector<int> G[MAXN];
bool del[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(v[i]); G[v[i]].push_back(u[i]);
        deg[u[i]]++;deg[v[i]]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=deg[i]&1;
    if(cnt!=0) {puts("No"); return 0;}
    if(m<=n+1) {puts("No"); return 0;}
    if(m>=n+3) {puts("Yes"); return 0;}
    queue<int> que;
    memset(del,false,sizeof(del));
    cnt=n;
    for(int i=1;i<=n;i++) if(deg[i]==2) que.push(i);
    while(que.size())
    {
        int v=que.front();que.pop();
        del[v]=true; cnt--;
        vector<int> adj; adj.clear();
        for(auto to:G[v]) 
        {
            if(del[to]) continue;
            adj.push_back(to);
        }
        assert(adj.size()==2);
        G[adj[0]].push_back(adj[1]);G[adj[1]].push_back(adj[0]);
    }
    if(cnt==1)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            if(!del[i])
            {
                int res=0;
                for(auto to:G[i]) if(to==i) res++;
                if(res<=2) puts("No"); else puts("Yes");
                return 0;
            }
        }
    }
    else if(cnt==2) 
    {
        vector<int> vert;vert.clear();
        for(int i=1;i<=n;i++) if(!del[i]) vert.push_back(i);
        int u=vert[0],v=vert[1];
        int cnt1=0,cnt2=0;
        for(auto to:G[u]) if(to==v) cnt1++;
        for(auto to:G[v]) if(to==u) cnt2++;
        if(deg[u]==4&&deg[v]==4&&cnt1==4&&cnt2==4) puts("No"); else puts("Yes");
    }
    else puts("Yes");
    return 0;
}

