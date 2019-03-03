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
struct lct 
{
    struct meow{int ch[2], fa, rev, sum, w;} t[2*MAXN];
    inline int wh(int x) {return t[pa].ch[1] == x;}
    inline int isr(int x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
    inline void update(int x) {t[x].sum =  max(max(t[lc].sum,t[rc].sum),t[x].w); }
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
}LCT[10];
int N,M,C,K;
int v[MAXN];
int cnt[10][MAXN];
map<P,int> col;
int main() 
{
    scanf("%d%d%d%d",&N,&M,&C,&K);
    for(int i=1;i<=N;i++) scanf("%d",&v[i]);
    for(int i=0;i<C;i++)
        for(int j=1;j<=N;j++)
            LCT[i].t[j].w=v[j];
    for(int i=0;i<M;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u>v) swap(u,v);
        col[P(u,v)]=w;
        LCT[w].link(u,v);
        cnt[w][u]++;cnt[w][v]++;
    }
    for(int i=0;i<K;i++)
    {
        int type,u,v,w,x,y;
        scanf("%d",&type);
        if(type==0)
        {
            scanf("%d%d",&x,&y);
            for(int j=0;j<C;j++)
            {
                LCT[j].splay(x);
                LCT[j].t[x].w=y;
            }
        }
        else if(type==1)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(u>v) swap(u,v);
            if(col.find(P(u,v))==col.end())
            {
                puts("No such edge.");
                continue;
            }
            int c=col[P(u,v)];
            if(c==w)
            {
                puts("Success.");
                continue;
            }
            if(cnt[w][u]>=2||cnt[w][v]>=2)
            {
                puts("Error 1.");
                continue;
            }
            if(LCT[w].findr(u)==LCT[w].findr(v))
            {
                puts("Error 2.");
                continue;
            }
            puts("Success.");
            LCT[c].cut(u,v);cnt[c][u]--;cnt[c][v]--;
            LCT[w].link(u,v);cnt[w][u]++;cnt[w][v]++;
            col[P(u,v)]=w;
        }
        else
        {
            scanf("%d%d%d",&w,&u,&v);
            if(LCT[w].findr(u)!=LCT[w].findr(v)) puts("-1");
            else
            {
                LCT[w].split(u,v);
                printf("%d\n",LCT[w].t[v].sum);
            }
        }
    }
}
