#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define MAXM 200005
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
int color[MAXN];
int iso,bip,nbip;
bool dfs(int v,int c)
{
    color[v]=c; bool f=true;
    for(auto to:G[v])
    {
        if(color[to]==c) f=false;
        if(!color[to]&&!dfs(to,-c)) f=false;
    }
    return f;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            if((int)G[i].size()==0) iso++;
            else if(dfs(i,1)) bip++; else nbip++;
        }
    }
    ll ans=1LL*iso*(2*n-iso)+2LL*bip*nbip+2LL*bip*bip+1LL*nbip*nbip;
    printf("%lld\n",ans);
    return 0;
}

