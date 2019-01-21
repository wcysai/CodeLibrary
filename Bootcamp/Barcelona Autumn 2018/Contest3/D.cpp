#include <bits/stdc++.h>
#define MAXN 300005
#define MAXM 200005
#define INF 1000000000000000LL
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
struct meow{ll ch[2], fa, rev, mx, mxp, w;} t[MAXN];
inline ll wh(ll x) {return t[pa].ch[1] == x;}
inline ll isr(ll x) {return t[pa].ch[0] != x && t[pa].ch[1] != x;}
inline void update(ll x) 
{
    t[x].mx=t[x].w;t[x].mxp=x;
    if(t[lc].mx>t[x].mx) t[x].mx=t[lc].mx,t[x].mxp=t[lc].mxp;
    if(t[rc].mx>t[x].mx) t[x].mx=t[rc].mx,t[x].mxp=t[rc].mxp;
}
inline void rever(ll x) {t[x].rev ^= 1; swap(lc, rc);}
inline void pushdown(ll x) 
{
    if(t[x].rev) 
    {
        if(lc) rever(lc);
        if(rc) rever(rc);
        t[x].rev = 0;
    }
}
void pd(ll x) {if(!isr(x)) pd(pa); pushdown(x);}
inline void rotate(ll x) 
{
    ll f=t[x].fa, g=t[f].fa, c=wh(x);
    if(!isr(f)) t[g].ch[wh(f)]=x; t[x].fa=g;
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
    while(lc) pushdown(x), x=lc; return x;
}
inline void link(ll x, ll y) 
{
    maker(x); t[x].fa=y;
}
inline void cut(ll x, ll y) 
{
    maker(x); access(y); splay(y);
    t[x].fa = t[y].ch[0] = 0; update(y);
}
inline void split(ll x, ll y) 
{
    maker(x); access(y); splay(y);
}
ll p[MAXN],r[MAXN];
void init(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
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
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
struct edge{ll u,v,w;};
edge e[MAXM];
ll n,m;
int main() 
{
    scanf("%lld%lld",&n,&m);
    init(n);
    ll ans=0;
    for(ll i=1;i<=m;i++) scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    for(ll i=1;i<=m;i++)
    {
        t[n+i].w=t[n+i].mx=e[i].w;
        t[n+i].mxp=n+i;
    }
    for(ll i=1;i<=m;i++)
    {
        ll x=find(e[i].u),y=find(e[i].v);
        if(x!=y) {link(e[i].u,i+n);link(e[i].v,i+n);unite(x,y);ans+=e[i].w;}
        else
        {
            x=e[i].u;y=e[i].v;
            split(x,y);
            if(e[i].w<t[y].mx)
            {
                ans-=t[y].mx;ans+=e[i].w;
                ll p=t[y].mxp;//printf("replace %lld %lld\n",p-n,k);
                cut(x,p);cut(y,p);
                link(x,n+i);link(y,n+i);
            }
        }
        printf("%lld\n",ans);
    }
}
