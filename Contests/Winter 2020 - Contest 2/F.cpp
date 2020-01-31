#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 1000005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
int p[MAXN],r[MAXN];
int ww[MAXM];
bool mark[MAXM];
int dep[MAXN],faid[MAXN],fa[MAXN];
int ans[MAXM];
namespace fastIO {
  #define BUF_SIZE 10000000
  //fread -> read
  bool IOerror = 0;
  inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if(p1 == pend) {
      p1 = buf;
      pend = buf + fread(buf, 1, BUF_SIZE, stdin);
      if(pend == p1){
        IOerror = 1;
        return -1;
      }
    }
    return *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template<typename T>
  inline void scan_d(T &x) {
    char ch;
    while(blank(ch = nc()));
    if(IOerror)
      return;
    for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
  }
  #undef BUF_SIZE
};

using namespace fastIO;
struct edge
{
    int to,cost,id;
};
struct edge2
{
    int from,to,cost,id;
};
bool cmp(edge2 x,edge2 y)
{
    return x.cost<y.cost;
}
vector<edge2> E;
vector<edge> G[MAXN];
void add_edge(int from,int to,int cost,int id)
{
    G[from].push_back((edge){to,cost,id});
    G[to].push_back((edge){from,cost,id});
}
void dfs(int v,int p,int d)
{
    dep[v]=d; fa[v]=p; 
    for(auto e:G[v])
    {
        int to=e.to;
        if(to==p) continue;
        faid[to]=e.id;
        dfs(to,v,d+1);
    }
}
void init(int n)
{
    for(int i=1;i<=n;i++) p[i]=i;
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
bool same(int x,int y)
{
    return find(x)==find(y);
}
ll kruskal()
{
    sort(E.begin(),E.end(),cmp);
    init(n);
    int cnt=0;
    ll res=0;
    for(int i=0;i<m;i++)
    {
        edge2 e=E[i];
        if(!same(e.from,e.to))
        {
            unite(e.from,e.to);
            add_edge(e.from,e.to,e.cost,e.id);
            mark[e.id]=true;
            res+=e.cost;
            cnt++;
        }
    }
    if(cnt==n-1) return res; else return -1;
}
void update(int u,int v,int w)
{
    u=find(u); v=find(v);
    while(u!=v)
    {
        if(dep[u]>dep[v])
        {
            ans[faid[u]]=min(ans[faid[u]],w);
            p[u]=find(fa[u]);
            u=p[u];
        }
        else
        {
            ans[faid[v]]=min(ans[faid[v]],w);
            p[v]=find(fa[v]);
            v=p[v];
        }
    }
}
int main()
{
    scan_d(n); scan_d(m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scan_d(u); scan_d(v); scan_d(w);
        ww[i]=w;
        E.push_back((edge2){u,v,w,i});
    }
    ll res=kruskal();
    if(res==-1)
    {
        scan_d(q);
        for(int i=0;i<q;i++)
        {
            int x;
            scan_d(x);
            puts("Not connected");
        }
        return 0;
    }
    init(n);
    dfs(1,0,0);
    for(int i=1;i<=m;i++) ans[i]=INF;
    for(int i=0;i<m;i++)
    {
        if(!mark[E[i].id])  update(E[i].from,E[i].to,E[i].cost);
    }
    scan_d(q);
    for(int i=0;i<q;i++)
    {
        int x;
        scan_d(x);
        if(!mark[x]) printf("%lld\n",res);
        else if(ans[x]==INF) puts("Not connected");
        else printf("%lld\n",res-ww[x]+ans[x]);
    }
    return 0;
}