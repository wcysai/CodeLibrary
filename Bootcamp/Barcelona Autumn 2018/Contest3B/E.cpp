/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-03 15:40:03
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
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
int n;
vector<P> vec;
P s,t;
P u[MAXV],v[MAXV];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&u[i].F,&u[i].S,&v[i].F,&v[i].S);
        vec.push_back(u[i]);vec.push_back(v[i]);
    }
    scanf("%d%d%d%d",&s.F,&s.S,&t.F,&t.S);
    vec.push_back(s);vec.push_back(t);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    V=(int)vec.size();
    int ss=lower_bound(vec.begin(),vec.end(),s)-vec.begin();
    int tt=lower_bound(vec.begin(),vec.end(),t)-vec.begin();
    for(auto it:vec)
    {
        if(it==s||it==t) continue;
        int id=lower_bound(vec.begin(),vec.end(),it)-vec.begin();
        add_edge(id,id+V,1);
    }
    for(int i=0;i<n;i++)
    {
        int uu=lower_bound(vec.begin(),vec.end(),u[i])-vec.begin();
        int vv=lower_bound(vec.begin(),vec.end(),v[i])-vec.begin();
        if(u[i]==s) add_edge(uu,vv,INF);
        else if(v[i]==s) add_edge(vv,uu,INF);
        else if(u[i]==t) add_edge(vv+V,uu,INF);
        else if(v[i]==t) add_edge(uu+V,vv,INF);
        else{add_edge(uu+V,vv,INF); add_edge(vv+V,uu,INF);}
    }
    printf("%d\n",max_flow(ss,tt));
    return 0;
}

