#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 10005
#define MAXN 10005
using namespace std;
int n,m,k,V;
bitset<5005> a[MAXN],b[MAXN];
set<int> unused;
vector<int> G[MAXV];
int match[MAXV],res[MAXN];
int id[505][10005];
bool valid[MAXN];
bool used[MAXV];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||(!used[w]&&dfs(w)))
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
set<int> s;
int main()
{
    scanf("%d%d%d",&n,&m,&k);V=500;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        for(int j=0;j<t;j++)
        {
            int x;
            scanf("%d",&x);
            s.insert(x);a[i].set(x-1);
        }
    }
    memset(valid,false,sizeof(valid));
    for(int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        int cnt=0;
        for(int j=0;j<t;j++)
        {
            int x;
            scanf("%d",&x);
            if(!s.count(x)) {cnt++; res[i]=x;}
            b[i].set(x-1);
        }
        if(cnt==1)
        {
            valid[i]=true;
            unused.insert(res[i]);
        }
    }
    int all=(int)s.size()+(int)unused.size();
    if(all<k)
    {
        puts("2");
        return 0;
    }
    if((int)s.size()==k)
    {
        puts("1");
        for(int i=1;i<=n;i++) printf("%d%c",1,i==n?'\n':' ');
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!valid[j]) continue;
            bitset<5005> inter;
            inter=b[j]^(b[j]&a[i]);
            if(inter.count()==1) 
            {
                if(!id[i][n+res[j]])
                {
                    add_edge(i,n+res[j]);
                    id[i][n+res[j]]=j;
                }
            }
        }
    }
    if(bipartite_matching()+(int)s.size()<k)
    {
        puts("2");
        return 0;
    }
    puts("1");
    for(int i=1;i<=n;i++)
    {
        if(match[i]==-1) printf("1 ");
        else printf("%d ",id[i][match[i]]);
    }
    puts("");
    return 0;
}
