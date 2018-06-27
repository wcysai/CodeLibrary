#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXV 3000
using namespace std;
int V,n,m;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV];
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
int main()
{
    scanf("%d%d",&n,&m);
    V=2*n;
    char str[5];
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d%s",&x,&y,&z,str);
        if(str[0]=='A')
        {
            if(z==1)
            {
                add_edge(x+n,x);
                add_edge(y+n,y);
            }
            else
            {
                add_edge(x,y+n);
                add_edge(y,x+n);
            }
        }
        else if(str[0]=='O')
        {
            if(z==1)
            {
                add_edge(x+n,y);
                add_edge(y+n,x);
            }
            else
            {
                add_edge(x,x+n);
                add_edge(y,y+n);
            }
        }
        else
        {
            if(z==1)
            {
                add_edge(x,y+n);
                add_edge(y,x+n);
                add_edge(x+n,y);
                add_edge(y+n,x);
            }
            else
            {
                add_edge(x,y);
                add_edge(y,x);
                add_edge(x+n,y+n);
                add_edge(y+n,x+n);
            }
        }
    }
    int p=scc();
    bool f=true;
    for(int i=0;i<n;i++)
        if(cmp[i]==cmp[i+n])
        {
            f=false;
            break;
        }
    if(f) puts("YES"); else puts("NO");
    return 0;
}
