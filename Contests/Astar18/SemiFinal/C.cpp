/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 14:09:15
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,a[MAXN],b[MAXN];
bool vis[MAXN];
int p[MAXN],r[MAXN],cnt[32];
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
vector<int> save[MAXN];
int cmp[MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<(int)rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=n;v++)
    {
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
bool Cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear(),rG[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        int p=scc();
        int ans=0;
        for(int i=0;i<p;i++) save[i].clear();
        for(int i=1;i<=n;i++) save[cmp[i]].push_back(i);
        for(int i=0;i<p;i++)
        {
            memset(cnt,0,sizeof(cnt));
            sort(save[i].begin(),save[i].end(),Cmp);
            for(int j=0;j<(int)save[i].size();j++)
            {
                int v=save[i][j];
                for(int k=0;k<32;k++)
                {
                    if(!((a[v]>>k)&1)) continue;
                    ans=(ans+1LL*a[v]*cnt[k]%MOD*(1LL<<k))%MOD;
                    cnt[k]++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

