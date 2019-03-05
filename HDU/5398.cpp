#include <bits/stdc++.h>
#define MAXN 2200005
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
    struct meow{int ch[2], fa, rev, mini, id, sum, w;} t[2*MAXN];
    inline int wh(int x) {return t[pa].ch[1] == x;}
    inline int isr(int x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
    inline void update(int x) 
    {
        t[x].id=x; t[x].mini=(x<=100000?INF:t[x].w);
        if(lc&&t[lc].mini<t[x].mini) t[x].mini=t[lc].mini,t[x].id=t[lc].id;
        if(rc&&t[rc].mini<t[x].mini) t[x].mini=t[rc].mini,t[x].id=t[rc].id;
        t[x].sum=t[x].w+t[lc].sum+t[rc].sum;
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

int n;

P E[MAXN];
int tot,cur;
void add_edge(int u,int v,int w)
{
    //printf("%d %d %d\n",u,v,w);
    if(lct::findr(u)!=lct::findr(v)) 
    {
        tot++;
        lct::link(u,tot);lct::link(v,tot);
        lct::t[tot].w=w;lct::splay(tot);
        cur+=w;
        //printf("added %dth edge from %d to %d with weight %d\n",tot-n,u,v,w);
        E[tot]=P(u,v);
    }
    else
    {
        //printf("%d %d %d\n",u,v,w);
        lct::split(u,v);
        int id=lct::t[v].id,ww=lct::t[v].mini;
        //printf("%d %d\n",id,ww);
        if(ww<w)
        {
            cur-=ww;cur+=w;
            lct::cut(id,E[id].F);lct::cut(id,E[id].S);
            //printf("cut %dth edge from %d to %d with weight %d\n",tot-n,u,v,ww);
            tot++;
            lct::link(u,tot);lct::link(v,tot);
            //printf("added %dth edge from %d to %d with weight %d\n",tot-n,u,v,w);
            lct::t[tot].w=w;lct::splay(tot);
            E[tot]=P(u,v);
        }
    }
}
int ans[MAXN];
int main() 
{
    tot=100000;
    for(int i=2;i<=100000;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(i%j) continue;
            add_edge(j,i,j);
            if(j*j!=i&&j!=1) add_edge(i/j,i,i/j);
        }
        lct::split(1,i);
        ans[i]=cur;
    }
    while(scanf("%d",&n)==1) printf("%d\n",ans[n]);
    return 0;
}
