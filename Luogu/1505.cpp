#include <bits/stdc++.h>
#define MAXN 300005
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
int n,m,tot;
namespace lct 
{
    struct meow{int ch[2], fa, rev, sum, maxi,mini, w,neg;} t[2*MAXN];
    inline int wh(int x) {return t[pa].ch[1] == x;}
    inline int isr(int x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
    inline void update(int x) 
    {
        if(x>n) t[x].sum=t[x].maxi=t[x].mini=t[x].w;
        else
        {
            t[x].sum=0;t[x].maxi=-INF;t[x].mini=INF;
        }
        if(lc)
        {
            t[x].sum+=t[lc].sum;
            t[x].maxi=max(t[x].maxi,t[lc].maxi);
            t[x].mini=min(t[x].mini,t[lc].mini);
        }
        if(rc)
        {
            t[x].sum+=t[rc].sum;
            t[x].maxi=max(t[x].maxi,t[rc].maxi);
            t[x].mini=min(t[x].mini,t[rc].mini);
        }
    }
    inline void rever(int x) {t[x].rev ^= 1; swap(lc, rc);}
    inline void negate(int x) 
    {
        int tmp=t[x].maxi;
        t[x].maxi=-t[x].mini;
        t[x].mini=-tmp;
        t[x].w=-t[x].w;t[x].sum=-t[x].sum;
        t[x].neg^=1;
    }
    inline void pushdown(int x) 
    {
        if(t[x].rev) 
        {
            if(lc) rever(lc);
            if(rc) rever(rc);
            t[x].rev = 0;
        }
        if(t[x].neg)
        {
            if(lc) negate(lc);
            if(rc) negate(rc);
            t[x].neg=0;
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
char str[4];
int main() 
{
    scanf("%d",&n);
    tot=n;
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w); u++;v++;
        tot++;
        lct::link(tot,u);lct::link(tot,v);
        lct::t[tot].w=w;
        lct::splay(tot);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int u,v,id,w;
        scanf("%s",str);
        if(str[0]=='C')
        {
            scanf("%d%d",&id,&w);
            lct::splay(n+id);
            lct::t[n+id].w=w;
        }
        else if(str[0]=='N')
        {
            scanf("%d%d",&u,&v);u++;v++;
            lct::split(u,v);lct::negate(v);
        }
        else if(str[0]=='S')
        {
            scanf("%d%d",&u,&v);u++;v++;
            lct::split(u,v);printf("%d\n",lct::t[v].sum);
        }
        else if(str[1]=='A')
        {
            scanf("%d%d",&u,&v);u++;v++;
            lct::split(u,v);printf("%d\n",lct::t[v].maxi);
        }
        else
        {
            scanf("%d%d",&u,&v);u++;v++;
            lct::split(u,v);printf("%d\n",lct::t[v].mini);
        }
    }
    return 0;
}
