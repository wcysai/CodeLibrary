/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 00:55:16
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define left fdiafkdo
#define right adkjoaskdo
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev;};
int V;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front(); que.pop();
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v,int t,int f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
int n,m,a,b;
char mp[305][305];
int num[305][305],tot;
vector<int> left,right;
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='*') cnt++;
    if(2*b<=a) {printf("%d\n",cnt*b); return 0;}
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='*')
            {
                if((i+j)&1) left.push_back(tot); else right.push_back(tot);
                num[i][j]=tot;
                if(i>0&&mp[i-1][j]=='*') 
                {
                    if((i+j)&1) add_edge(tot,num[i-1][j],1);
                    else add_edge(num[i-1][j],tot,1);
                }
                if(j>0&&mp[i][j-1]=='*')
                {
                    if((i+j)&1) add_edge(tot,num[i][j-1],1);
                    else add_edge(num[i][j-1],tot,1);
                }
                tot++;
            }
        }
    for(auto it:left) add_edge(tot,it,1);
    for(auto it:right) add_edge(it,tot+1,1);
    int ans=max_flow(tot,tot+1);
    printf("%d\n",ans*a+(cnt-2*ans)*b);
    return 0;
}

