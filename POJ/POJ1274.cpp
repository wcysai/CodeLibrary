#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAX_V 400
int n,m;
using namespace std;
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
    for(int v=0;v<n;v++)
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
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++) G[i].clear();
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            for(int j=0;j<x;j++)
            {
                scanf("%d",&y);
                y--;
                add_edge(i,n+y);
            }
        }
        printf("%d\n",bipartite_matching());
    }
    return 0;
}
