/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-02 06:11:50
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 200005
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
char str[MAXV];
int cnt[26];
char s[MAXV][2];
//s:0 t:1 'a'-'z':2-27 
vector<int> ans[26];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    scanf("%s",str);
    for(int i=0;i<n;i++) cnt[str[i]-'a']++;
    V=28+n;
    for(int i=28;i<28+n;i++)
    {
        add_edge(0,i,1);
        add_edge(i,s[i-28][0]-'a'+2,1);
        add_edge(i,s[i-28][1]-'a'+2,1);
    }
    for(int i=0;i<26;i++) add_edge(i+2,1,cnt[i]);
    if(max_flow(0,1)!=n) {puts("IMPOSSIBLE"); return 0;}
    for(int i=28;i<28+n;i++)
        for(int j=0;j<(int)G[i].size();j++)
        {
            edge &e=G[i][j];
            if(e.to==0) continue;
            if(e.cap==0) 
            {
                if(s[i-28][0]-'a'==e.to-2)ans[e.to-2].push_back(i-27); else ans[e.to-2].push_back(27-i);
                break;
            }
        }
    for(int i=0;i<n;i++)
    {
        printf("%d",ans[str[i]-'a'].back());
        ans[str[i]-'a'].pop_back();
        printf("%c",i==n-1?'\n':' ');
    }
    return 0;
}

