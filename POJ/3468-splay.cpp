#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll ch[MAXN][2],f[MAXN],tot,size[MAXN],key[MAXN],lazy[MAXN],ans[MAXN],sum[MAXN],a[MAXN];
ll n,q,sz,root;
    template <class T>
bool scan_d(T &ret)
{
    char c;
    int sgn;
    T bit=0.1;
    if(c=getchar(), c==EOF)
        return 0;
    while(c!='-' && c!='.' && (c<'0' || c>'9'))
        c=getchar();
    sgn=(c=='-')? -1:1;
    ret=(c=='-')? 0:(c-'0');
    while(c=getchar(), c>='0' && c<='9')
        ret=ret*10+(c-'0');
    if(c==' ' || c=='\n')
    {
        ret*=sgn;
        return 1;
    }
    while(c=getchar(), c>='0' && c<='9')
        ret+=(c-'0')*bit, bit/=10;
    ret*=sgn;
    return 1;
}
inline bool get(ll x)
{
    return ch[f[x]][1]==x;
}
inline void pushup(ll x)
{
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
    sum[x]=key[x]+sum[ch[x][0]]+sum[ch[x][1]];
}
inline void modify(ll x,ll v)
{
    if(!x) return;
    lazy[x]+=v;key[x]+=v;
    sum[x]+=v*size[x];
}
inline void pushdown(ll x)
{
    if(!lazy[x]) return;
    modify(ch[x][0],lazy[x]);modify(ch[x][1],lazy[x]);
    lazy[x]=0;
}
inline void rotate(ll x)
{
    ll old=f[x],oldf=f[old],whichx=get(x);
    pushdown(old);pushdown(x);
    ch[old][whichx]=ch[x][whichx^1]; f[ch[old][whichx]]=old;
    ch[x][whichx^1]=old; f[old]=x;
    f[x]=oldf;
    if (oldf) ch[oldf][ch[oldf][1]==old]=x;
    pushup(old); pushup(x);
}
inline void splay(ll x,ll goal)
{
    pushdown(x);
    for(ll fa;(fa=f[x])!=goal;rotate(x))
        if(f[fa]!=goal) rotate((get(x)==get(fa))?fa:x);
    if(goal==0) root=x;
}
inline ll findx(ll now,ll k)
{
    while(now)
    {
        if(k<=size[ch[now][0]]) now=ch[now][0];
        else if(k<=size[ch[now][0]]+1) return now;
        else k-=size[ch[now][0]]+1,now=ch[now][1];
    }
}
void build(ll &k,ll l,ll r,ll fa)
{
    if(l>r) return;
    ll mid=(l+r)/2;
    k=++tot;f[k]=fa;
    key[k]=sum[k]=a[mid];lazy[k]=0;size[k]=1;
    build(ch[k][0],l,mid-1,k);build(ch[k][1],mid+1,r,k);
    pushup(k);
    //printf("%lld %lld\n",k,sum[k]);
}
char c[2];
int main()
{
    scan_d(n);scan_d(q);
    for(ll i=1;i<=n;i++) scan_d(a[i]);
    key[0]=key[n+1]=0;
    build(root,0,n+1,0);
    ll l,r,v;
    for(ll i=0;i<q;i++)
    {
        scanf("%s",c);
        if(c[0]=='Q')
        {
            scan_d(l);scan_d(r);
            l++;r++;
            ll x=findx(root,l-1);splay(x,0);
            ll y=findx(root,r+1);splay(y,root);
            printf("%lld\n",sum[ch[ch[root][1]][0]]);
        }
        else
        {
            scan_d(l);scan_d(r);scan_d(v);
            l++;r++;
            ll x=findx(root,l-1);splay(x,0);
            ll y=findx(root,r+1);splay(y,root);
            modify(ch[ch[root][1]][0],v);pushup(ch[root][1]);pushup(root);
        }
    }
}
