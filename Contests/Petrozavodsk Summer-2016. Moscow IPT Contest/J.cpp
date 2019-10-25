#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d,len[MAXN],son[MAXN],st[MAXN],ed[MAXN];
vector<int> G[MAXN];
int p[MAXN],r[MAXN];
vector<int> pool[MAXN];
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
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        if(len[to]>len[son[v]]) son[v]=to;
    }
    len[v]=len[son[v]]+1;
}
void dfs2(int v,int p)
{
    if(son[v])
    {
        st[son[v]]=st[v]+1;
        dfs2(son[v],v);
        ed[v]=ed[son[v]];
    }
    else ed[v]=st[v];
    pool[st[v]].clear();
    pool[st[v]].push_back(v);
    if(ed[v]-st[v]>=d)
    {
        while(pool[ed[v]].size())
        {
            int u=pool[ed[v]].back();
            unite(u,v);
            pool[ed[v]].pop_back();
        }
        ed[v]--;
    }
    for(auto to:G[v])
    {
        if(to==p||to==son[v]) continue;
        st[to]=ed[v]+1;
        dfs2(to,v);
        for(int i=st[to];i<=ed[to];i++)
        {
            if(!pool[i].size()) continue;
            int dep=i-st[to];
            if(st[v]+d-dep-1>=st[v]&&st[v]+d-dep-1<=ed[v])
            {
                int x=st[v]+d-dep-1,y=i;
                for(int j=1;j<(int)pool[x].size();j++) unite(pool[x][0],pool[x][j]);
                while(pool[x].size()>1) pool[x].pop_back();
                for(int j=1;j<(int)pool[y].size();j++) unite(pool[y][0],pool[y][j]);
                while(pool[y].size()>1) pool[y].pop_back();
                if(pool[x].size()&&pool[y].size()) unite(pool[x].back(),pool[y].back());
            }
        }
        for(int i=st[to];i<=ed[to];i++)
        {
            if(!pool[i].size()) continue;
            int dep=i-st[to];
            for(auto x:pool[i]) pool[st[v]+dep+1].push_back(x);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    init(n);
    dfs(1,0); st[1]=1; dfs2(1,0);
    int ans=0;
    for(int i=1;i<=n;i++) if(i==find(i)) ans++;
    printf("%d\n",ans);
    return 0;
}
