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
int u[MAXM],v[MAXM];
int cmp[MAXN];
ll ans[MAXM],delta;
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
void scc()
{
    vs.clear();
    for(auto v:nodes) if(!used[v]) dfs(v);
    for(auto v:nodes) used[v]=false;
    for(int i=vs.size()-1;i>=0;i--) 
    {
        if(!used[vs[i]]) rdfs(vs[i],vs[i]);
    }
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
    delta+=1LL*sz[x]*sz[y];
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
vector<int> E;
vector<int> cont[MAXM];
int col[MAXN],tot;
void solve(vector<int> &E,int l,int r)
{
    /*printf("%d %d:",l,r);
    for(auto it:E) printf("%d ",it.t);
    puts("");*/
    tot++;
    int mid=(l+r)/2;
    nodes.clear();
    vector<int> lhs,rhs;lhs.clear();rhs.clear();
    for(auto it:E) 
    {
        if(it<=mid) 
        {
            int x=find(u[it]),y=find(v[it]);
            if(col[x]!=tot)
            {
                col[x]=tot;
                G[x].clear();rG[x].clear();
                used[x]=false; 
                nodes.push_back(x);
            }
            if(col[y]!=tot)
            {
                col[y]=tot;
                G[y].clear();rG[y].clear();
                used[y]=false; 
                nodes.push_back(y);
            }
            add_edge(x,y);
        }
    }
    scc();
    if(l==r)
    {
        delta=0;
        for(auto it:nodes) unite(find(it),find(cmp[it]));
        ans[l]=ans[l-1]+delta;
    }
    else
    {
        for(auto it:E)
        {
            int x=find(u[it]),y=find(v[it]);
            if(col[x]==tot&&col[y]==tot&&cmp[x]==cmp[y]) lhs.push_back(it); else rhs.push_back(it);
        }
        solve(lhs,l,mid);solve(rhs,mid+1,r);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        E.push_back(i);
    }
    init(n);
    tot=0;
    solve(E,1,m); 
    for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
    return 0;
}

