#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,p[MAXN];
vector<int> G[MAXN];
set<int> s[MAXN];
ll ans[MAXN];
void merge(int u,int v)
{
    if(s[u].size()<s[v].size())
    {
        swap(s[u],s[v]);
        ans[u]=ans[v];
    }
    for(auto x:s[v])
    {
        auto it=s[u].lower_bound(x);
        if(it!=s[u].end()&&it!=s[u].begin())
        {
            int r=*it,l=*(--it);
            it++;
            ans[u]-=1LL*(r-l)*(r-l);
        }
        if(it!=s[u].end())
        {
            int r=*it;
            ans[u]+=1LL*(r-x)*(r-x);
        }
        if(it!=s[u].begin())
        {
            int l=*(--it);
            it++;
            ans[u]+=1LL*(x-l)*(x-l);
        }
        s[u].insert(x);
    }
    s[v].clear();
}
void dfs(int v)
{
    for(auto to:G[v])
    {
        dfs(to);
        merge(v,to);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        G[x].push_back(i);
    }
    for(int i=1;i<=n;i++) s[i].insert(i);
    dfs(1);
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}