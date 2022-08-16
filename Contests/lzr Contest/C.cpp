#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int tot,n,m,a[MAXN];
ll sx[MAXN],sy[MAXN],sz[MAXN];
int color[MAXN],acc[MAXN],fa[MAXN],faid[MAXN],depth[MAXN],tmpx,tmpy;
bool bad;
set<P> badc;
set<pair<P,int> > s;
struct edge
{
    int to,x,y,z,id;
};
vector<edge> G[MAXN];
vector<int> edges;
void add_edge(int u,int v,int x,int y,int z,int id)
{
    G[u].push_back((edge){v,x,y,z,id});
    G[v].push_back((edge){u,-x,-y,-z,id});
}
void dfs(int v,int p,int d)
{
    color[v]=1; fa[v]=p; depth[v]=d;
    if(bad) return;
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        if(!color[e.to])
        {
            sx[e.to]=sx[v]+e.x;
            sy[e.to]=sy[v]+e.y;
            sz[e.to]=sz[v]+e.z;
            faid[e.to]=e.id;
            dfs(e.to,v,d+1);
        }
        else if(color[e.to]==1)
        {
            ll ssx=sx[v]-sx[e.to]+e.x;
            ll ssy=sy[v]-sy[e.to]+e.y;
            ll ssz=sz[v]-sz[e.to]+e.z;
            if(ssx!=0||ssy!=0||ssz!=0)
            {
                tot++;
                acc[v]++; acc[e.to]--;
                tmpx=v; tmpy=e.to;
                s.insert(make_pair(P(ssx,ssy),ssz));
                if(s.size()==2) bad=true;
            }
            else
            {
                badc.insert(P(v,e.to));
                acc[v]--; acc[e.to]++;
            }
        }
    }
    color[v]=2;
}
void dfs2(int v)
{
    for(auto e:G[v])
    {
        if(fa[e.to]!=v) continue;
        dfs2(e.to);
        acc[v]+=acc[e.to];
    }
    if(v!=1&&acc[v]==tot) edges.push_back(faid[v]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) 
    {
        int u,v,x,y,z;
        scanf("%d%d%d%d%d",&u,&v,&x,&y,&z);
        add_edge(u,v,x,y,z,i+1);
    }
    bad=false;
    dfs(1,0,0);
    if(bad) {puts("0"); return 0;}
    else if(tot==0)
    {
        dfs2(1);
        for(int i=1;i<=n;i++)
            for(auto e:G[i])
                if(fa[i]!=e.to&&depth[e.to]<depth[i]&&!badc.count(P(i,e.to))) edges.push_back(e.id);
        printf("%d\n",(int)edges.size());
        for(auto x:edges) printf("%d ",x);
        puts("");
    }
    else if(tot==1)
    {
        for(auto e:G[tmpx])
            if(e.to==tmpy) edges.push_back(e.id);
        dfs2(1);
        sort(edges.begin(),edges.end());
        printf("%d\n",(int)edges.size());
        for(auto x:edges) printf("%d ",x);
        puts("");
    }
    else
    {
        dfs2(1);
        sort(edges.begin(),edges.end());
        printf("%d\n",(int)edges.size());
        for(auto x:edges) printf("%d ",x);
        puts("");
    }
    return 0;
}

