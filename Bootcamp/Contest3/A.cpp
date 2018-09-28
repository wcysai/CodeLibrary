#include <bits/stdc++.h>
#define MAXN 100005
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
    struct meow{int ch[2], fa, rev, sum, w;} t[MAXN];
    inline int wh(int x) {return t[pa].ch[1] == x;}
    inline int isr(int x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
    inline void update(int x) {t[x].sum=t[lc].sum^t[rc].sum^t[x].w;}
    inline void rever(int x) {t[x].rev^= 1; swap(lc, rc);}
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
        if(!isr(f)) t[g].ch[wh(f)]=x; t[x].fa=g;
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
        while(lc) pushdown(x), x=lc; return x;
    }
    inline void link(int x, int y) 
    {
        maker(x); t[x].fa=y;
    }
    inline void cut(int x, int y) 
    {
        maker(x); access(y); splay(y);
        t[x].fa = t[y].ch[0] = 0; update(y);
    }
    inline void split(int x, int y) 
    {
        maker(x); access(y); splay(y);
    }
} using lct::findr;

int n, Q, op, x, y;
char str[5];
int main() 
{
    scanf("%d",&n);
    while(true)
    {
        scanf("%s",str);
        if(str[0]=='E') return 0;
        scanf("%d%d",&x,&y);
        if(str[0]=='C') lct::link(x,y);
        else if(str[0]=='D') lct::cut(x,y);
        else {if(lct::findr(x)==lct::findr(y)) puts("YES"); else puts("NO"); fflush(stdout);}
    }
    return 0;
}
