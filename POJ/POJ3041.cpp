#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#define MAX_V 1000
#define MAX_K 10000
using namespace std;
int N,K;
int R[MAX_K],C[MAX_K];
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
void solve()
{
    V=N*2;
    for(int i=0;i<K;i++)
    {
        add_edge(R[i]-1,N+C[i]-1);
    }
    printf("%d\n",bipartite_matching());
}
int main()
{
    scanf("%d %d",&N,&K);
    for(int i=0;i<K;i++)
        scanf("%d %d",&R[i],&C[i]);
    solve();
    return 0;
}

