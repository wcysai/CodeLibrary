#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
int now,n,m;
db a[MAXN],b[MAXN],c[MAXN],res,mid;
int ans[MAXN];
vector<int> G[MAXN];
struct state
{
    vector<db> *a;//reversed depth array
    db tag;
    int sz()
    {
        return a->size();
    }
    void update(int i,db val)
    {
        if(m-2-i<=(int)a->size()-1&&m-2-i>=0)
        {
            res=min(res,tag+(*a)[a->size()-1-(m-2-i)]+val+c[now]);
        }
    }
    void add(int i,db val)
    {
        (*a)[i]=min((*a)[i],val-tag);
    }
}s[MAXN];
state pull(state z,db val)  
{
    if(z.sz()==0)
    {
        state c;
        c.a=new vector<db> (1,val);c.tag=0;
        if(m==0) res=min(res,val);
        return c;
    }
    else
    {
        state c;
        c.a=z.a;c.tag=z.tag;
        c.a->push_back(-c.tag);
        c.tag+=val;
        if(c.sz()-1>=m) res=min(res,c.tag+(*(c.a))[c.sz()-1-m]);
        return c;
    }
}
state merge(state a,state b)
{
    if(a.sz()<b.sz()) swap(a,b); 
    int bs=b.sz();
    int as=a.sz();
    for(int i=0;i<bs;i++) a.update(i,(*(b.a))[bs-i-1]+b.tag);
    for(int i=0;i<bs;i++) a.add(as-i-1,(*(b.a))[bs-i-1]+b.tag);
    return a;
}
void dfs(int v,int p)
{
    now=v;c[v]=a[v]-mid*b[v];
    s[v].a=new vector<db>(0);s[v].tag=0;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs(to,v);
        now=v;
        s[v]=merge(s[v],s[to]);
    }
    s[v]=pull(s[v],c[v]);
}
bool check()
{
    res=1e18;
    dfs(1,0);
    if(res>=0) return false; else return true;
}
int main()
{
    freopen("cdcq_b.in","r",stdin);
    freopen("cdcq_b.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lf",&b[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    if(m==-1)
    {
        db ans=1e18;
        for(int i=1;i<=n;i++) ans=min(ans,a[i]/b[i]);
        printf("%.2f\n",ans);
        return 0;
    }
    m--;
    db l=0,r=5e10;
    for(int i=0;i<100;i++)
    {
        mid=(l+r)/2;
        if(check()) r=mid; else l=mid;
    }
    if(l==5e10) puts("-1"); else printf("%.2f\n",r);
    return 0;
}

