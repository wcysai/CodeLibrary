#include<bits/stdc++.h>
#define MAXN 100035
#define MAXV 200050
using namespace std;
int n,m,V;
int a[MAXN];
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
    V=2*m;
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    bool flag=true;
    for(int j=0;j<n-1;j++)
    {
        int x;
        bool f=true;
        scanf("%d",&x);
        for(int i=0;i<x;i++)
        {
            int q;
            scanf("%d",&q);
            if(i<k)
            {
                if (!f) {a[i]=q; continue;}
                if(q==a[i]) continue;
                if(q>a[i])
                {
                    add_edge(q+m-1,a[i]+m-1);
                    add_edge(a[i]-1,q-1);
                    a[i]=q;
                    f=false;
                }
                else
                {
                    add_edge(a[i]-1,q-1);
                    add_edge(a[i]+m-1,q-1);
                    add_edge(q-1,a[i]+m-1);
                    add_edge(q+m-1,a[i]+m-1);
                    a[i]=q;
                    f=false;
                }
            }
            else
            {
                a[i]=q; continue;
            }
        }
        if(f&&x<k) flag=false;
        k=x;
    }
    if(!flag)
    {
        printf("No\n");
        return 0;
    }
    scc();
    for(int i=0;i<m;i++)
    {
        if(cmp[i]==cmp[m+i])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    vector<int> ans;
    for(int i=0;i<m;i++)
        if(cmp[i]<cmp[m+i]) ans.push_back(i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]+1);
    return 0;
}
