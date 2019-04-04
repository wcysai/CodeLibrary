#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1505
#define MAXM 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define pa t[x].fa
#define dec sakdioas
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap;};
int n,m,l,s,t;
int a[MAXN];
vector<edge> G[MAXN];
map<P,int> mp,capa;
int nxt[MAXN];
int pt[MAXN];
int now;
bool valid[MAXN];
int ans[MAXM];
int cnt=0;
vector<int> incoming[MAXN];
//a: level array
//G: graph
//mp: no. of edges
//capa: capacity of each edge
//pt: current pointer position while traversing
//now: current vertex
//nxt: the next vertex pointing in the aborescence(0 if no such vetex)
//valid: if some vertex is deleted
clock_t tStart;
inline bool scan_d(int &num)  
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
namespace lct //link-cut tree
{
    struct meow{int ch[2], fa, rev, mini,minpos, dec, w;} t[2*MAXN];
    inline int wh(int x) {return t[pa].ch[1] == x;}
    inline int isr(int x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
    inline void update(int x) //edges deleted should be ordered by layers
    {
        t[x].mini=t[x].w; t[x].minpos=x;
        if(lc&&(t[lc].mini<t[x].mini||(t[lc].mini==t[x].mini&&a[t[lc].minpos]>a[t[x].minpos])))
        {
            t[x].mini=t[lc].mini;
            t[x].minpos=t[lc].minpos;
        }
        if(rc&&(t[rc].mini<t[x].mini||(t[rc].mini==t[x].mini&&a[t[rc].minpos]>a[t[x].minpos])))
        {
            t[x].mini=t[rc].mini;
            t[x].minpos=t[rc].minpos;
        }
        
    }
    inline void rever(int x) {t[x].rev ^= 1; swap(lc, rc);}
    inline void decr(int x,int v) {t[x].dec+=v; t[x].mini-=v; t[x].w-=v;}
    inline void pushdown(int x) 
    {
        if(t[x].rev) 
        {
            if(lc) rever(lc);
            if(rc) rever(rc);
            t[x].rev = 0;
        }
        if(t[x].dec)
        {
            if(lc) decr(lc,t[x].dec);
            if(rc) decr(rc,t[x].dec);
            t[x].dec=0;
        }
    }
    void pd(int x) {if(!isr(x)) pd(pa); pushdown(x);}
    inline void rotate(int x) 
    {
        int f=t[x].fa, g=t[f].fa, c=wh(x);
        if(!isr(f)) t[g].ch[wh(f)]=x; 
        t[x].fa=g;
        t[f].ch[c] = t[x].ch[c^1]; t[t[f].ch[c]].fa=f;
        t[x].ch[c^1] = f; t[f].fa=x;
        update(f); update(x);
    }
    inline void splay(int x) 
    {
        pd(x);
        for(; !isr(x); rotate(x))
        {
            if(!isr(pa)) rotate( wh(pa)==wh(x) ? pa : x );
        }
    }

    inline void access(int x) 
    {
        for(int y=0; x; y=x, x=pa) splay(x), rc=y, update(x);
    }
    inline void maker(int x) 
    {
        access(x); splay(x); rever(x);
    }
    inline int findr(int x) 
    {
        access(x); splay(x);
        while(lc) pushdown(x), x=lc; 
        return x;
    }
    inline void link(int x, int y) 
    {
        maker(x); 
        if(findr(y)!=x) t[x].fa=y;
    }
    inline void cut(int x, int y) 
    {
        maker(x);
        if(findr(y)==x&&t[x].fa==y&&t[y].ch[0]==x&&!t[y].ch[1])
        {
            t[x].fa=t[y].ch[0]=0; 
            update(y);
        }
    }
    inline void split(int x, int y) 
    {
        maker(x); access(y); splay(y);
    }
};
void add_edge(int u,int v,int c)
{
    G[u].push_back((edge){v,c});
}
void del(int v)//delete some vertex
{
    valid[v]=false;
    lct::maker(v);
    for(auto u:incoming[v])
    {
        if(ans[mp[P(u,v)]]) continue;
        ans[mp[P(u,v)]]=capa[P(u,v)]-lct::t[u].w;
        lct::cut(u,v);
        lct::maker(u);
    }
    nxt[v]=0;
    lct::maker(v);
    if(incoming[v].size()>0) now=incoming[v].back(); else now=0;
    incoming[v].clear();
}
bool go(int v)//dfs traversal
{
    if(!valid[v]) 
    {
        now=s;
        return false;
    }
    now=v;
    if(v==t) return true;
    while(pt[v]<(int)G[v].size())
    {
        int to=G[v][pt[v]].to,w=G[v][pt[v]].cap;
        if(!valid[to]) {pt[v]++; continue;}
        int r=lct::findr(to);
        lct::t[v].w=w; lct::splay(v);
        nxt[v]=to;
        lct::link(v,to);
        incoming[to].push_back(v);
        pt[v]++;
        lct::maker(r);
        if(go(r)) return true; else return false;
    }
    if(valid[v]) del(v);
    return false;
}
void process()//found a path consisting of admissable edges from s to t, delete the edges of minimum weight
{
    lct::t[now].w=INF;
    lct::split(s,now);
    lct::maker(now);
    int val=lct::t[now].mini;
    lct::decr(now,val);
    while(lct::t[now].mini==0)
    {
        int pos=lct::t[now].minpos;
        lct::cut(pos,nxt[pos]);
        lct::maker(now); lct::maker(pos);
        ans[mp[P(pos,nxt[pos])]]=capa[P(pos,nxt[pos])];
        nxt[pos]=0;
        now=pos; lct::t[now].w=INF; lct::splay(now);
        lct::split(s,now);
    }
}
void addall()//add all remaining flows in the grap
{
    for(int i=1;i<=n;i++)
    {
        if(nxt[i])
        {
            int v=lct::t[i].mini;
            ans[mp[P(i,nxt[i])]]=capa[P(i,nxt[i])]-v;
        }
    }
}
int main()
{ 
    tStart = clock();
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scan_d(n);scan_d(m);scan_d(l);
    for(int i=1;i<=n;i++) scan_d(a[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scan_d(u);scan_d(v);scan_d(c);
        add_edge(u,v,c);
        mp[P(u,v)]=i;
        capa[P(u,v)]=c;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) s=i;
        if(a[i]==l) t=i;
    }
    memset(valid,true,sizeof(valid));
    now=s;
    lct::t[t].w=INF;
    while(true)
    {
        while(now&&(!go(now)))
        {
            if(valid[s]) now=lct::findr(s);
            else now=0;
        }
        if(!now) break;
        process();
    }
    addall();
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}
