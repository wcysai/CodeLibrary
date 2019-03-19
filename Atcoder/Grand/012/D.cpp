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
int n,x,y,c[MAXN],w[MAXN];
int fact[MAXN],invf[MAXN];
vector<P> col[MAXN];
vector<int> G[MAXN];
vector<P> cross;
bool vis[MAXN];
map<int,int> cnt;
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int v)
{
    vis[v]=true;cnt[c[v]]++;
    for(auto to:G[v]) if(!vis[to]) dfs(to);
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&c[i],&w[i]);
        col[c[i]].push_back(P(w[i],i));
    }
    for(int i=1;i<=n;i++) sort(col[i].begin(),col[i].end());
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<(int)col[i].size();j++)
        {
            if(col[i][0].F+col[i][j].F<=x) add_edge(col[i][0].S,col[i][j].S);
            else break;
        }
    }
    for(int i=1;i<=n;i++) if(col[i].size()) cross.push_back(col[i][0]);
    if(cross.size()>1)
    {
        sort(cross.begin(),cross.end());
        for(int i=1;i<=n;i++)
        {
            if(c[i]!=c[cross[0].S]&&cross[0].F+w[i]<=y) add_edge(i,cross[0].S);
            if(c[i]!=c[cross[1].S]&&cross[1].F+w[i]<=y) add_edge(i,cross[1].S);
        }
    }
    int ans=1;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cnt.clear();
            dfs(i);
            int tot=0;
            for(auto x:cnt) ans=1LL*ans*invf[x.S]%MOD,tot+=x.S;
            ans=1LL*ans*fact[tot]%MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}

