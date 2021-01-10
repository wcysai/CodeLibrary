#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
bool vis[MAXN];
set<int> s;
vector<P> G[MAXN];
int cnt,ans;
void dfs(int v)
{
    vis[v]=true; cnt++;
    for(auto p:G[v])
    {
        int to=p.F,e=p.S;
        s.insert(e);
        if(!vis[to]) dfs(to);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(P(v,i));
        G[v].push_back(P(u,i));
    }
    memset(vis,false,sizeof(false));
    for(int i=1;i<=400000;i++)
    {
        if(!vis[i])
        {
            s.clear();
            cnt=0;
            dfs(i);
            if(s.size()==cnt-1) ans+=cnt-1; else ans+=cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}