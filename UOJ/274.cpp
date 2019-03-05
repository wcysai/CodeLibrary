#include <bits/stdc++.h>
#define MAXN 400005
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
int n,m;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
namespace lct 
{
    struct meow{int ch[2], fa, rev, mini, id, sum, w,l ;} t[2*MAXN];
    inline int wh(int x) {return t[pa].ch[1] == x;}
    inline int isr(int x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
    inline void update(int x) 
    {
        t[x].id=x; t[x].mini=(x<=n?INF:t[x].w);
        if(lc&&t[lc].mini<t[x].mini) t[x].mini=t[lc].mini,t[x].id=t[lc].id;
        if(rc&&t[rc].mini<t[x].mini) t[x].mini=t[rc].mini,t[x].id=t[rc].id;
        t[x].sum=t[x].l+t[lc].sum+t[rc].sum;
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
int p[MAXN],r[MAXN];
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
bool same(int x,int y)
{
    return find(x)==find(y);
}
struct edge
{
    int u,v,t,l;
};
edge ed[MAXN];
P E[MAXN];
int tot;
void add_edge(int u,int v,int t,int l)
{
    if(!same(u,v)) 
    {
        tot++;
        lct::link(u,tot);lct::link(v,tot);
        lct::t[tot].w=t;lct::t[tot].l=l;lct::splay(tot);
        unite(u,v);
        //printf("added %dth edge from %d to %d with temp %d and length %d\n",tot-n,u,v,t,l);
        //printf("added %dth edge from %d to %d with weight %d\n",tot-n,u,v,w);
        E[tot]=P(u,v);
    }
    else
    {
        //printf("%d %d %d\n",u,v,w);
        lct::split(u,v);
        int id=lct::t[v].id,ww=lct::t[v].mini;
        //printf("%d %d\n",id,ww);
        if(ww<=t)
        {
            lct::cut(id,E[id].F);lct::cut(id,E[id].S);
            //printf("cut %dth edge from %d to %d with temp %d and length %d\n",tot-n,u,v,t,l);
            tot++;
            lct::link(u,tot);lct::link(v,tot);
            //printf("added %dth edge from %d to %d with temp %d and length %d\n",tot-n,u,v,t,l);
            lct::t[tot].w=t;lct::t[tot].l=l;lct::splay(tot);
            E[tot]=P(u,v);
        }
    }
}
int id;
int ans[MAXN];
char str[7];
int main() 
{
    n=read();m=read();
    init(n);
    tot=n;
    for(int i=0;i<m;i++)
    {
        scanf("%s",str);
        if(str[0]=='f')
        {
            int id,u,v,t,l;id=read();u=read();v=read();t=read();l=read();
            u++;v++;
            ed[id].u=u;ed[id].v=v;ed[id].t=t;ed[id].l=l;
            add_edge(u,v,t,l);
        }
        else if(str[0]=='m')
        {
            int u,v;u=read();v=read();
            u++;v++;
            if(!same(u,v)) puts("-1");
            else
            {
                lct::split(u,v);
                printf("%d\n",lct::t[v].sum);
            }
        }
        else
        {
            int id,l;
            id=read();l=read();
            ed[id].l=l;
            add_edge(ed[id].u,ed[id].v,ed[id].t,ed[id].l);
        }
    }
    return 0;
}
