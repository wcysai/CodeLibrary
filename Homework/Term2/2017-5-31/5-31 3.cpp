#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAXN 1000
#define INF 100000000
using namespace std;
int graph[MAXN][MAXN];
int d[MAXN],pi[MAXN],f[MAXN],visited[MAXN];
int n,s,cnt=0;
void bfs(int s)
{
    queue<int> que;
    for(int i=0;i<n;i++)
    {
        d[i]=INF;
        pi[i]=INF;
    }
    d[s]=0;
    que.push(s);
    while(que.size())
    {
        int x=que.front();
        que.pop();
        for(int i=0;i<n;i++)
        {
            if(graph[x][i]>0&&d[i]==INF)
            {
                d[i]=d[x]+1;
                pi[i]=x;
                que.push(i);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",i);
        if(d[i]==INF) printf("9999 "); else printf("%d ",d[i]);
        if(pi[i]==INF) printf("-1\n"); else printf("%d\n",pi[i]);
    }
    return;
}
void dfs(int s)
{
    visited[s]=1;
    d[s]=++cnt;
    for(int i=0;i<n;i++)
        if(graph[s][i]>0&&visited[i]==0)
            dfs(i);
    f[s]=++cnt;
    return;
}
int main()
{
    while(scanf("%d %d",&n,&s)==2)
    {
        cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }
    bfs(s);
     for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
      if(visited[i]==0) dfs(i);
      for(int i=0;i<n;i++)
    {
        printf("%d %d %d\n",i,d[i],f[i]);
    }
    }
    return 0;
}
