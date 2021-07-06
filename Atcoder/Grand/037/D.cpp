#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
bool valid[MAXN][MAXN];
int get_id(int x)
{
    return (x-1)/m+1;
}
int V;
vector<int> G[2*MAXN];
int match[2*MAXN];
bool used[2*MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=1;v<=V;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    memset(valid,true,sizeof(valid));
    V=2*n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=2*n;j++) G[j].clear();
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
            {
                if(!valid[j][k]) continue;
                add_edge(j,n+get_id(a[j][k]));
            }
        assert(bipartite_matching()==n);
        for(int j=1;j<=n;j++)
        {
            int x=match[j]-n;
            for(int k=1;k<=m;k++) 
            {
                if(!valid[j][k]) continue;
                if(get_id(a[j][k])==x)
                {
                    valid[j][k]=false;
                    b[j][i]=a[j][k];
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[get_id(b[i][j])][j]=b[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) printf("%d ",b[i][j]);
        puts("");
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) printf("%d ",c[i][j]);
        puts("");
    }
    return 0;
}