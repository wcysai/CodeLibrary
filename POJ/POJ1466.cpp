#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAX_V 502
using namespace std;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
void add_edge(int u,int v)
{
    G[v].push_back(u);
    G[u].push_back(v);
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
int main()
{
    while(scanf("%d",&V)!=EOF)
    {
       for(int i=0;i<V;i++)
            G[i].clear();
       for(int i=0;i<V;i++)
       {
           int v,m,u;
           scanf("%d: (%d)",&v,&m);
           for(int j=0;j<m;j++)
           {
               scanf("%d",&u);
               G[v].push_back(u);
           }
       }
    printf("%d\n",V-bipartite_matching());
    }
    return 0;
}
