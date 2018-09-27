/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-27 17:42:49
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,mat[MAXN][MAXN];
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
int cmp[MAXN],cmpsize[MAXN],indeg[MAXN];
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
    for(int v=1;v<=n;v++) if(!used[v]) dfs(v);
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear(),rG[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&mat[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(mat[i][j]==1) add_edge(i,j); else add_edge(j,i);
        int p=scc();
        memset(cmpsize,0,sizeof(cmpsize));
        memset(indeg,0,sizeof(indeg));
        for(int i=1;i<=n;i++) cmpsize[cmp[i]]++;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(cmp[i]==cmp[j]) continue;
                if(mat[i][j]==1) indeg[cmp[j]]++; else indeg[cmp[i]]++;
            }
        for(int i=0;i<p;i++) if(indeg[i]==0) {printf("%d\n",cmpsize[i]); break;}
    }
    return 0;
}

