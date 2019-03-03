#include <bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 51061
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define pa t[x].fa
typedef long long ll;
void ad(ll &a,ll b) {a+=b; if(a>=MOD) a-=MOD;}
namespace lct 
{
    struct meow{ll ch[2], fa, rev, add, mult, sz, sum, w;} t[2*MAXN];
    inline ll wh(ll x) {return t[pa].ch[1] == x;}
    inline ll isr(ll x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
    inline void update(ll x) {t[x].sz=t[lc].sz+t[rc].sz+1; t[x].sum = t[lc].sum+t[rc].sum+t[x].w; t[x].sum%=MOD;}
    inline void rever(ll x) {t[x].rev ^= 1; swap(lc, rc);}
    inline void Mult(ll x,ll v) {t[x].add*=v; t[x].add%=MOD; t[x].mult*=v; t[x].mult%=MOD; t[x].sum*=v; t[x].sum%=MOD; t[x].w*=v; t[x].w%=MOD;}
    inline void Add(ll x,ll v) {ad(t[x].add,v); ad(t[x].sum,1LL*t[x].sz*v%MOD); ad(t[x].w,v);}
    inline void pushdown(ll x) 
    {
        if(t[x].rev) 
        {
            if(lc) rever(lc);
            if(rc) rever(rc);
            t[x].rev = 0;
        }
        if(t[x].mult!=1)
        {
            if(lc) Mult(lc,t[x].mult);
            if(rc) Mult(rc,t[x].mult);
            t[x].mult=1;
        }
        if(t[x].add!=0)
        {
            if(lc) Add(lc,t[x].add);
            if(rc) Add(rc,t[x].add);
            t[x].add=0;
        }
    }
    void pd(ll x) {if(!isr(x)) pd(pa); pushdown(x);}
    inline void rotate(ll x) 
    {
        ll f=t[x].fa, g=t[f].fa, c=wh(x);
        if(!isr(f)) t[g].ch[wh(f)]=x; 
        t[x].fa=g;
        t[f].ch[c] = t[x].ch[c^1]; t[t[f].ch[c]].fa=f;
        t[x].ch[c^1] = f; t[f].fa=x;
        update(f); update(x);
    }
    inline void splay(ll x) 
    {
        pd(x);
        for(; !isr(x); rotate(x))
            if(!isr(pa)) rotate( wh(pa)==wh(x) ? pa : x );
    }

    inline void access(ll x) 
    {
        for(ll y=0; x; y=x, x=pa) splay(x), rc=y, update(x);
    }
    inline void maker(ll x) 
    {
        access(x); splay(x); rever(x);
    }
    inline ll findr(ll x) 
    {
        access(x); splay(x);
        while(lc) pushdown(x), x=lc; 
        return x;
    }
    inline void link(ll x, ll y) 
    {
        maker(x); 
        if(findr(y)!=x) t[x].fa=y;
    }
    inline void cut(ll x, ll y) 
    {
        maker(x);
        if(findr(y)==x&&t[x].fa==y&&t[y].ch[0]==x&&!t[y].ch[1])
        {
            t[x].fa=t[y].ch[0]=0; 
            update(y);
        }
    }
    inline void split(ll x, ll y) 
    {
        maker(x); access(y); splay(y);
    }
};

ll n,q;
char str[2];
int main() 
{
    scanf("%lld%lld",&n,&q);
    for(ll i=1;i<=n;i++) lct::t[i].w=lct::t[i].mult=lct::t[i].sz=1;
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        lct::link(u,v);
    }
    for(ll i=0;i<q;i++)
    {
        ll u1,v1,u2,v2,c;
        scanf("%s",str);
        if(str[0]=='+')
        {
            scanf("%lld%lld%lld",&u1,&v1,&c);
            lct::split(u1,v1);lct::Add(v1,c);
        }
        else if(str[0]=='-')
        {
            scanf("%lld%lld%lld%lld",&u1,&v1,&u2,&v2);
            lct::cut(u1,v1);lct::link(u2,v2);
        }
        else if(str[0]=='*')
        {
            scanf("%lld%lld%lld",&u1,&v1,&c);
            lct::split(u1,v1);lct::Mult(v1,c);
        }
        else
        {
            scanf("%lld%lld",&u1,&v1);
            lct::split(u1,v1); printf("%lld\n",lct::t[v1].sum);
        }
    }
}
