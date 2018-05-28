#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXV 100050
#define MAXE 100050
using namespace std;
typedef long long ll;
ll V,E,T;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV];
ll ind[MAXV];
ll outd[MAXV];
ll sz[MAXV];
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
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
    scanf("%I64d",&T);
    int cnt=0;
    ll ans;
    while(T--)
    {
        cnt++;
        scanf("%I64d %I64d",&V,&E);
        memset(sz,0,sizeof(sz));
        memset(ind,0,sizeof(ind));
        memset(outd,0,sizeof(outd));
        memset(cmp,0,sizeof(cmp));
        for(int i=0;i<V;i++)
        {
            G[i].clear();
            rG[i].clear();
        }
        for(int i=0;i<E;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            add_edge(x-1,y-1);
        }
        int n=scc();
        if(n==1)
        {
            printf("Case %d: -1\n",cnt);
            continue;
        }
        for(int i=0;i<V;i++)
        {
            sz[cmp[i]]++;
            for(int j=0;j<G[i].size();j++)
                if(cmp[i]!=cmp[G[i][j]])
                {
                    outd[cmp[i]]++;
                    ind[cmp[G[i][j]]]++;
                }
        }
        ans=0;
        for(int i=0;i<n;i++)
            if(ind[i]==0||outd[i]==0)
                ans=max(ans,(V-sz[i])*(V-sz[i]-1)+sz[i]*(sz[i]-1)+sz[i]*(V-sz[i])-E);
        printf("Case %d: %I64d\n",cnt,ans);
    }
    return 0;
}
