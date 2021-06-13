#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[MAXN],b[MAXN];
struct edge
{
    int u,v,cost;
};
bool cmp(edge x,edge y)
{
    return x.cost<y.cost;
}
vector<edge> E;
int n,m,p[MAXN],r[MAXN],val[MAXN],cnt[MAXN];
ll res[MAXN];
ll ans;
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        cnt[i]=a[i];
        val[i]=b[i];
        res[i]=1LL*a[i]*b[i];
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y,int w)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    ll last=res[x]+res[y];
    ll newcost=1LL*min(val[x],val[y])*max(max(cnt[x],cnt[y]),w);
    newcost=min(newcost,last);
    if(r[x]<r[y]) 
    {
        p[x]=y;
        res[y]=newcost;
        cnt[y]=max(max(cnt[x],cnt[y]),w);
        val[y]=min(val[x],val[y]);
    }
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        res[x]=newcost;
        cnt[x]=max(max(cnt[x],cnt[y]),w);
        val[x]=min(val[x],val[y]);
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        E.push_back((edge){u,v,w});
    }
    sort(E.begin(),E.end(),cmp);
    init(n);
    for(auto e:E) unite(e.u,e.v,e.cost);
    ans=0;
    for(int i=1;i<=n;i++) if(find(i)==i) ans+=res[i];
    printf("%lld\n",ans);
    return 0;
}