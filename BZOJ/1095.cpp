/*************************************************************************
    > File Name: 1095.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-22 17:49:52
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 180055
#define MAXLOGN 22
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
bool centroid[MAXN];
int N,Q,root,sz[MAXN],fa[MAXN],st[MAXLOGN][MAXN],vs[MAXN*2-1],depth[MAXN*2-1],id[MAXN],state[MAXN];
struct heap
{
    priority_queue<int> q1,q2;
    void push(int x) {q1.push(x);}
    void erase(int x) {q2.push(x);}
    int top()
    {
        while(q2.size()&&q1.top()==q2.top()) q1.pop(),q2.pop();
        return q1.top();
    }
    int top2()
    {
        int x=top();pop();
        int y=top();push(x);
        return y;
    }
    void pop()
    {
        while(q2.size()&&q1.top()==q2.top()) q1.pop(),q2.pop();
        q1.pop();
    }
    int size(){return q1.size()-q2.size();}
}h1[MAXN],h2[MAXN],H;
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++)
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
    for(int i=1;i<=n;++i) st[0][i]=i;
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(1,-1,0,k);
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
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void getdeep(int v,int p,int rt,int prt)//enumerate path
{
    h1[rt].push(dis(v,prt));
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||centroid[to]) continue;
        getdeep(to,v,rt,prt);
    }
}
void solve(int v,int p)
{
    fa[v]=p;
    centroid[v]=true; 
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(centroid[to]) continue;
        root=getroot(to,v,sz[to]).S;
        getdeep(to,v,root,v);
        solve(root,v);
        //printf("%d %d\n",v,root);
        if(h1[root].size()>=1) h2[v].push(h1[root].top());
        //printf("dis:%d %d %d\n",root,v,dis(root,v));
    }
    //if(h2[v].size()>=2) printf("%d %d %d\n",v,h2[v].top(),h2[v].top2());
    h2[v].push(0);
    if(h2[v].size()>=2) H.push(h2[v].top()+h2[v].top2());
    root=v;
}
void pre()
{
    init(N);
    root=getroot(1,0,N).S;
    solve(root,0);
}
int query2()
{
    if(H.size()<1) return -1;
    return H.top();
}
void toggle(int v)
{
    int t=v;
    if(state[v]==0)
    {
        state[v]=1;
        if(h2[v].size()>=2) H.erase(h2[v].top()+h2[v].top2());
        h2[v].erase(0);
        if(h2[v].size()>=2) H.push(h2[v].top()+h2[v].top2());
        while(fa[v]>0)
        {            
            //printf("%d %d\n",h2[fa[v]].top(),h2[fa[v]].top2());
            if(h2[fa[v]].size()>=2) H.erase(h2[fa[v]].top()+h2[fa[v]].top2());
            //printf("%d\n",h1[v].size());
            if(h1[v].size()) h2[fa[v]].erase(h1[v].top());
            h1[v].erase(dis(t,fa[v]));
            //printf("%d\n",h1[v].size());
            if(h1[v].size()) h2[fa[v]].push(h1[v].top());
            //printf("%d %d\n",h2[fa[v]].top(),h2[fa[v]].top2());
            if(h2[fa[v]].size()>=2) H.push(h2[fa[v]].top()+h2[fa[v]].top2());
            v=fa[v];
        }
    }
    else
    {
        state[v]=0;
        if(h2[v].size()>=2) H.erase(h2[v].top()+h2[v].top2());
        h2[v].push(0);
        if(h2[v].size()>=2) H.push(h2[v].top()+h2[v].top2());
        while(fa[v]>0)
        {
            if(h2[fa[v]].size()>=2) H.erase(h2[fa[v]].top()+h2[fa[v]].top2());
            if(h1[v].size()) h2[fa[v]].erase(h1[v].top());
            h1[v].push(dis(t,fa[v]));
            if(h1[v].size()) h2[fa[v]].push(h1[v].top());
            if(h2[fa[v]].size()>=2) H.push(h2[fa[v]].top()+h2[fa[v]].top2());
            v=fa[v];
        }
    }
    return;
}
char str[10];
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);G[y].push_back(x);
    }
    memset(centroid,false,sizeof(centroid));
    pre();
    //for(int i=1;i<=N;i++) printf("%d %d\n",i,fa[i]);
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
    {
        scanf("%s",str);
        if(str[0]=='G') printf("%d\n",query2());
        else
        {
            int x;scanf("%d",&x);
            toggle(x);
        }
    }
    return 0;
}
