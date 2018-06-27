#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAX_V 402
using namespace std;
int V,g,B,M,cnt;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
bool relate[MAX_V][MAX_V];
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
    cnt=0;
    while(scanf("%d%d%d",&g,&B,&M)==3)
    {
        if(g==0&&B==0&&M==0) break;
        cnt++;
        V=g+B;
        memset(relate,false,sizeof(relate));
        for(int i=0;i<g;i++)
            for(int j=0;j<g;j++)
              relate[i][j]=true;
        for(int i=g;i<V;i++)
            for(int j=g;j<V;j++)
              relate[i][j]=true;
       for(int i=0;i<V;i++)
            G[i].clear();
       for(int i=0;i<M;i++)
       {
           int x,y;
           scanf("%d%d",&x,&y);
           x--;
           y+=g-1;
           relate[x][y]=true;
           relate[y][x]=true;
       }
       for(int i=0;i<V;i++)
        for(int j=0;j<i;j++)
          if(!relate[i][j]) add_edge(i,j);
    printf("Case %d: %d\n",cnt,V-bipartite_matching());
    }
    return 0;
}
