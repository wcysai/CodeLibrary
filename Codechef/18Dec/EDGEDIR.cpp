/*************************************************************************
    > File Name: EDGEDIR.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-14 21:10:44
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
struct edge
{
    int to,id,pri;
};
vector<edge> G[MAXN];
int p[MAXN],r[MAXN],deg[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void add_edge(int u,int v,int id)
{
    G[u].push_back((edge){v,id,0});
    G[v].push_back((edge){u,id,1});
    deg[u]++;deg[v]++;
}
bool used[MAXN];
int ans[MAXN],st[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        init(200001);
        memset(deg,0,sizeof(deg));
        scanf("%d%d",&n,&m);
        int tot=n;
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(!same(u,v)) {add_edge(u,v,i); unite(u,v);}
            else {++tot; add_edge(u,tot,i); unite(u,tot);}
        }
        if(m&1) {puts("-1"); for(int i=1;i<=tot;i++) G[i].clear(); continue;}
        memset(used,false,sizeof(used));
        memset(st,0,sizeof(st));
        queue<int> que;
        for(int i=1;i<=tot;i++) if(deg[i]==1) que.push(i);
        while(que.size())
        {
            int v=que.front();que.pop();
            if(deg[v]!=1) continue;
            for(auto e:G[v])
            {
                if(used[e.id]) continue;
                else
                {
                    if(st[v]) 
                    {
                        ans[e.id]=1-e.pri;
                        deg[v]--;deg[e.to]--;
                        if(!(ans[e.id]^e.pri)) st[e.to]=1-st[e.to];
                        if(deg[e.to]==1) que.push(e.to);
                    }
                    else
                    {
                        ans[e.id]=e.pri;
                        deg[v]--;deg[e.to]--;
                        if(!(ans[e.id]^e.pri)) st[e.to]=1-st[e.to];
                        if(deg[e.to]==1) que.push(e.to);
                    }
                    used[e.id]=true;
                }
            }
        }
        for(int i=0;i<m;i++) printf("%d%c",ans[i],i==m-1?'\n':' ');
        for(int i=1;i<=tot;i++) G[i].clear();
    }
    return 0;
}

