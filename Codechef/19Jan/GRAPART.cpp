#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,fa[MAXN],dep[MAXN],col[MAXN],cnt0,cnt1;
vector<int> G[MAXN];
vector<int> node[MAXN];
mt19937 wcy(time(NULL));
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
int dfs(int v,int p,int d)
{
    fa[v]=p; dep[v]=d; 
    if(d&1) cnt1++; else cnt0++;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(!dfs(to,v,d+1)) node[v].push_back(to);
    }
    while(node[v].size()>=2)
    {
        int u=node[v].back(); col[u]=1; node[v].pop_back();
        u=node[v].back(); col[u]=2; node[v].pop_back();
    }
    if(node[v].size()==0) return 0;
    else
    {
        col[node[v][0]]=1;col[v]=2;
        return 2;
    }
}
bool check(int v)
{
    if(!fa[v]||(!fa[fa[v]])) return true;
    if(col[v]==col[fa[v]]&&col[v]==col[fa[fa[v]]]) return false;
    return true;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cnt0=cnt1=0;
        scanf("%d",&N);
        for(int i=1;i<=N;i++) G[i].clear(),node[i].clear();
        for(int i=0;i<N-1;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        dfs(1,0,0);
        if(cnt0==cnt1)
        {
            puts("1");
            for(int i=1;i<=N;i++) if(dep[i]&1) printf("%d ",i);
            puts("");
            for(int i=1;i<=N;i++) if(!(dep[i]&1)) printf("%d ",i);
            puts("");continue;
        }
        puts("2");
        for(int i=1;i<=N;i++) if(col[i]==1) printf("%d ",i);
        puts("");
        for(int i=1;i<=N;i++) if(col[i]==2) printf("%d ",i);
        puts("");
    }
    return 0;
}
