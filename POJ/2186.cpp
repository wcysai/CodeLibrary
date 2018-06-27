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
#define MAXV 20005
#define MAXM 50005
using namespace std;
int V,N,M;
int A[MAXM],B[MAXM];
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV];
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
void solve()
{
    V=N;
    for(int i=0;i<M;i++)
        add_edge(A[i]-1,B[i]-1);
    int n=scc();
    int u=0,num=0;
    for(int v=0;v<V;v++)
    {
        if(cmp[v]==n-1)
        {
            u=v;
            num++;
        }
    }
    memset(used,0,sizeof(used));
    rdfs(u,0);
    for(int v=0;v<V;v++)
    {
        if(!used[v])
        {
            num=0;
            break;
        }
    }
    printf("%d\n",num);
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
        scanf("%d%d",&A[i],&B[i]);
    solve();
    return 0;
}

