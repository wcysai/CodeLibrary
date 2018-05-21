#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<assert.h>
#define F first
#define S second
#define MAXV 1005
#define INF 1000000000
using namespace std;
typedef pair<int,int> P;
int V,n,a,b,dis;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV];
P A[MAXV],B[MAXV];
P crd[MAXV];
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
int manhattan(int x1,int x2,int y1,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
bool feasible(int k)
{
    for(int i=0;i<V;i++)
    {
        G[i].clear();
        rG[i].clear();
    }
    for(int i=0;i<a;i++)
    {
        add_edge(A[i].F,A[i].S+n);
        add_edge(A[i].S,A[i].F+n);
        add_edge(A[i].F+n,A[i].S);
        add_edge(A[i].S+n,A[i].F);
    }
    for(int i=0;i<b;i++)
    {
        add_edge(B[i].F,B[i].S);
        add_edge(B[i].S,B[i].F);
        add_edge(B[i].F+n,B[i].S+n);
        add_edge(B[i].S+n,B[i].F+n);
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            int dis1=manhattan(crd[i].F,crd[n].F,crd[i].S,crd[n].S);
            int dis2=manhattan(crd[i].F,crd[n+1].F,crd[i].S,crd[n+1].S);
            int dis3=manhattan(crd[j].F,crd[n].F,crd[j].S,crd[n].S);
            int dis4=manhattan(crd[j].F,crd[n+1].F,crd[j].S,crd[n+1].S);
            if(dis1+dis3>k)
            {
                add_edge(i,j+n);
                add_edge(j,i+n);
            }
            if(dis2+dis4>k)
            {
                add_edge(i+n,j);
                add_edge(j+n,i);
            }
            if(dis1+dis4+dis>k)
            {
                add_edge(i,j);
                add_edge(j+n,i+n);
            }
            if(dis2+dis3+dis>k)
            {
                add_edge(i+n,j+n);
                add_edge(j,i);
            }
        }
    scc();
    for(int i=0;i<n;i++)
        if(cmp[i]==cmp[i+n]) return false;
    return true;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    scanf("%d%d%d%d",&crd[n].F,&crd[n].S,&crd[n+1].F,&crd[n+1].S);
    dis=manhattan(crd[n].F,crd[n+1].F,crd[n].S,crd[n+1].S);
    for(int i=0;i<n;i++)
        scanf("%d%d",&crd[i].F,&crd[i].S);
    V=n*2;
    for(int i=0;i<a;i++)
    {
        scanf("%d%d",&A[i].F,&A[i].S);
        A[i].F--;A[i].S--;
    }
    for(int i=0;i<b;i++)
    {
        scanf("%d%d",&B[i].F,&B[i].S);
        B[i].F--;B[i].S--;
    }
    int left=0,right=INF;
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(feasible(mid)) right=mid; else left=mid;
    }
    if(right==INF) printf("-1\n"); else printf("%d\n",right);
    return 0;
}

