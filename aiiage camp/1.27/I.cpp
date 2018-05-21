#include<bits/stdc++.h>
#define MAXV 200005
#define MAXE 300005
using namespace std;
int V,E;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV],deg[MAXV],sccnum[MAXV];
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
    scanf("%d%d",&V,&E);
    memset(deg,0,sizeof(deg));
    memset(sccnum,0,sizeof(sccnum));
    for(int i=0;i<E;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x-1,y-1);
        add_edge(y-1,x-1);
        deg[x-1]++;
        deg[y-1]++;
    }
    if(V==2&&E==1)
    {
        puts("0");
        return 0;
    }
    int p=scc();
    for(int i=0;i<V;i++)
        if(deg[i]&1) sccnum[cmp[i]]++;
    int s=0,num0=0;
    for(int i=0;i<p;i++)
    {
        if(sccnum[i]==0) num0++;
        s+=sccnum[i];
    }
    if(p==1)
    {
        printf("%d\n",s/2);
        return 0;
    }
    printf("%d\n",s/2+num0);
    return 0;
}
