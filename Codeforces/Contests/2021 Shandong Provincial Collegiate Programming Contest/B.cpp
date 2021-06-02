#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
int n,L,R,a[MAXN];
ull seed;
ull xorshift64()
{
    ull x=seed;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    return seed=x;
}
int gen()
{
    return xorshift64()%(R-L+1)+L;
}
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[1005*1005];
int V,E;
int p[1005],r[1005];
void init(int n)
{
    for(int i=0;i<n;i++)
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
ll kruskal()
{
    sort(es,es+E,cmp);
    init(V);
    ll res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
int main()
{
    scanf("%d%d%d%llu",&n,&L,&R,&seed);
    for(int i=1;i<=n;i++) a[i]=gen();
    if(n<=1000)
    {
        V=n; E=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                es[E++]=(edge){i,j,__gcd(a[i],a[j])};
        printf("%lld\n",kruskal());
    }
    else if(L==R) printf("%lld\n",1LL*L*(n-1));
    else printf("%lld\n",n-1);
    return 0;
}