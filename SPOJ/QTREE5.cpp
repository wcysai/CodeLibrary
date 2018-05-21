#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int N,Q;
vector<int> G[MAXN];
int centroid[MAXN];
int subtree_size[MAXN];
int st[MAXLOGN][MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
bool color[MAXN];
priority_queue<P, vector<P>, greater<P> >pque[MAXN];
void add_edge(int u,int v)
{
    G[u-1].push_back(v-1);
    G[v-1].push_back(u-1);
}
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
int getMin(int x, int y)
{
    return depth[x]<depth[y]?x:y;
}

void rmq_init(int n)
{
    for(int i=0;i<n;++i) st[0][i]=i;
    for(int i=1;(1<<i)<n;++i)
        for(int j=0;j+(1<<i)-1<n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(0,-1,0,k);
    rmq_init(V*2-1);
}
int query(int l, int r)
{
    int k=31-__builtin_clz(r-l+1);
    return getMin(st[k][l],st[k][r-(1<<k)+1]);
}
int lca(int u,int v)
{
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
int dis(int u,int v)
{
    return depth[id[u]]+depth[id[v]]-2*depth[id[lca(u,v)]];
}
int compute_subtree_size(int v,int p)
{
    int c=1;
    for(int i=0;i<G[v].size();i++)
    {
        int w=G[v][i];
        if(w==p||centroid[w]!=-1) continue;
        c+=compute_subtree_size(G[v][i],v);
    }
    subtree_size[v]=c;
    return c;
}
P search_centroid(int v,int p,int t)
{
    P res=make_pair(INT_MAX,-1);
    int s=1,m=0;
    for(int i=0;i<G[v].size();i++)
    {
        int w=G[v][i];
        if(w==p||centroid[w]!=-1) continue;
        res=min(res,search_centroid(w,v,t));
        m=max(m,subtree_size[w]);
        s+=subtree_size[w];
    }
    m=max(m,t-s);
    res=min(res,make_pair(m,v));
    return res;
}
void construct_node(int v,int p)
{
    compute_subtree_size(v,-1);
    int s=search_centroid(v,-1,subtree_size[v]).S;
    //printf("%d %d %d %d\n",v,p,subtree_size[v],s);
    centroid[s]=p;
    for(int i=0;i<G[s].size();i++)
    {
        if(centroid[G[s][i]]!=-1) continue;
        construct_node(G[s][i],s);
    }
}
void convert_color(int x)
{
    color[x]=!color[x];
    if(!color[x]) return;
    int t=x;
    while(t!=-2) 
    {
        pque[t].push(P(dis(t,x),x));
        t=centroid[t];
    }
    return;
}
int find_ans(int x)
{
    int ans=INF;
    int t=x;
    while(t!=-2)
    {
        while(pque[t].size()&&!color[pque[t].top().S]) pque[t].pop();
        if(pque[t].empty()) {t=centroid[t]; continue;}
        ans=min(ans,dis(x,t)+pque[t].top().F);
        t=centroid[t];
    }
    return ans==INF?-1:ans;
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        G[i].clear();
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    init(N);
    memset(centroid,-1,sizeof(centroid));
    memset(color,false,sizeof(color));
    construct_node(0,-2);
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==0) convert_color(y-1); else printf("%d\n",find_ans(y-1));
    }
    return 0;
}
