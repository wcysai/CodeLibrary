#include <bits/stdc++.h>
#define MAXN 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define pa t[x].fa
typedef long long ll;
namespace lct 
{
    struct meow{int ch[2], fa, rev, maxi, id, w;} t[2*MAXN];
    inline int wh(int x) {return t[pa].ch[1] == x;}
    inline int isr(int x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
    inline void update(int x) 
    {
        t[x].id=x; t[x].maxi=t[x].w;
        if(t[lc].maxi>t[x].maxi) t[x].maxi=t[lc].maxi,t[x].id=t[lc].id;
        if(t[rc].maxi>t[x].maxi) t[x].maxi=t[rc].maxi,t[x].id=t[rc].id;
    }
    inline void rever(int x) {t[x].rev ^= 1; swap(lc, rc);}
    inline void pushdown(int x) 
    {
        if(t[x].rev) 
        {
            if(lc) rever(lc);
            if(rc) rever(rc);
            t[x].rev = 0;
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
            if(!isr(pa)) rotate( wh(pa)==wh(x) ? pa : x );
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

int n,m,tot;
struct edge
{
    int u,v,a,b;
}E[MAXN];
bool cmp(edge p,edge q)
{
    return p.a<q.a;
}
P e[MAXN];
vector<int> vec;
void add_edge(int u,int v,int w)
{
    if(lct::findr(u)!=lct::findr(v)) 
    {
        tot++;
        lct::link(u,tot);lct::link(v,tot);
        lct::t[tot].w=w;lct::splay(tot);
        //printf("added %dth edge from %d to %d with weight %d\n",tot-n,u,v,w);
        e[tot]=P(u,v);
    }
    else
    {
        lct::split(u,v);
        int id=lct::t[v].id,ww=lct::t[v].maxi;
        if(ww>w)
        {
            lct::cut(id,e[id].F);lct::cut(id,e[id].S);
            //printf("cut %dth edge from %d to %d with weight %d\n",tot-n,u,v,ww);
            tot++;
            lct::link(u,tot);lct::link(v,tot);
            //printf("added %dth edge from %d to %d with weight %d\n",tot-n,u,v,w);
            lct::t[tot].w=w;lct::splay(tot);
            e[tot]=P(u,v);
        }
    }
}

int main() 
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&E[i].u,&E[i].v,&E[i].a,&E[i].b);
        vec.push_back(E[i].a);
    }
    tot=n;
    sort(E,E+m,cmp);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int now=0,ans=INF;
    for(auto x:vec)
    {
        while(now<m&&E[now].a<=x) {add_edge(E[now].u,E[now].v,E[now].b); now++;}
        if(lct::findr(1)==lct::findr(n))
        {
            lct::split(1,n);
            ans=min(ans,x+lct::t[n].maxi);
        }
    }
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}
