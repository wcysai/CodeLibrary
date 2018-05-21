#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXN 1505
#define MAXV 5005
#define MAXM 5005
#define F first
#define S second
using namespace std;
int V,n,m;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV];
pair<int,int> doors[MAXM];
pair<int,int> keys[MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++)
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
bool solve(int k)
{
    for(int i=0;i<V;i++)
    {
        G[i].clear();
        rG[i].clear();
    }
    for(int i=0;i<n/2;i++)
    {
        add_edge(keys[i].F,keys[i].S+n);
        add_edge(keys[i].S,keys[i].F+n);
        add_edge(keys[i].F+n,keys[i].S);
        add_edge(keys[i].S+n,keys[i].F);
    }
    for(int i=0;i<k;i++)
    {
        add_edge(doors[i].F+n,doors[i].S);
        add_edge(doors[i].S+n,doors[i].F);
    }
    scc();
    for(int i=0;i<n;i++)
        if(cmp[i]==cmp[n+i]) return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m) break;
        for(int i=0;i<n;i++)
            scanf("%d%d",&keys[i].F,&keys[i].S);
        n=n*2;
        V=2*n;
        for(int i=0;i<m;i++)
            scanf("%d%d",&doors[i].F,&doors[i].S);
        int left=0,right=m+1;
        while(right-left>1)
        {
            int mid=(left+right)/2;
            if(solve(mid)) left=mid; else right=mid;
        }
        printf("%d\n",left);
    }
    return 0;
}

