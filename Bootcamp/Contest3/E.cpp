/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-28 22:52:57
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 250005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
struct edge
{
    int u,v,t;
};
vector<int> nodes;
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
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
    for(auto v:nodes) used[v]=false;
    vs.clear();
    for(auto v:nodes) if(!used[v]) dfs(v);
    int k=0;
    for(auto v:nodes) used[v]=false;
    for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}
vector<edge> E;
vector<edge> cont[MAXM];
void solve(vector<edge> &E,int l,int r)
{
    if(!E.size()) return;
    if(l==r)
    {
        for(auto it:E) cont[l].push_back(it);
        return;
    }
    int mid=(l+r)/2;
    nodes.clear();
    vector<edge> used;used.clear();
    vector<edge> lhs,rhs;lhs.clear();rhs.clear();
    for(auto it:E) if(it.t<=mid) used.push_back(it); else rhs.push_back(it);
    for(auto it:used) {nodes.push_back(it.u); nodes.push_back(it.v);}
    sort(nodes.begin(),nodes.end());nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());
    for(auto it:nodes) {G[it].clear(); rG[it].clear();}
    for(auto it:used) add_edge(it.u,it.v);
    scc(); 
    for(auto it:used) {if(cmp[it.u]==cmp[it.v]) lhs.push_back(it); else rhs.push_back(it);}
    solve(lhs,l,mid);solve(rhs,mid+1,r);
}
int p[MAXN],r[MAXN],sz[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        sz[i]=1;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; sz[y]+=sz[x];}
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        sz[x]+=sz[y];
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        edge e;e.t=i;
        scanf("%d%d",&e.u,&e.v);E.push_back(e);
    }
    solve(E,1,m+1);
    init(n);
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        for(auto it:cont[i]) 
            if(!same(it.u,it.v)) {ans+=1LL*sz[find(it.u)]*sz[find(it.v)]; unite(it.u,it.v);}
        printf("%lld\n",ans);
    }
    return 0;
}

