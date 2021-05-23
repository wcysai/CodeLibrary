#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,m,x;
ll a[MAXN];
int p[MAXN],r[MAXN],deg[MAXN];
vector<P> G[MAXN];
bool vis[MAXN];
void add_edge(int u,int v,int id) 
{
    G[u].push_back(P(v,id));
    G[v].push_back(P(u,id));
}
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
void unite(int x,int y,int id)
{
    int tmpx=x,tmpy=y;
    x=find(x);
    y=find(y);
    if(x==y) return;
    add_edge(tmpx,tmpy,id);
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
vector<int> v1,v2;
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    ll s=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        s+=a[i];
    }
    init(n);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        unite(u,v,i);
    }
    if(s<1LL*(n-1)*x) {puts("NO"); return 0;}
    puts("YES");
    queue<int> que;
    for(int i=1;i<=n;i++) deg[i]=(int)G[i].size();
    for(int i=1;i<=n;i++) if(deg[i]==1) que.push(i);
    memset(vis,false,sizeof(vis));
    while(que.size())
    {
        int v=que.front(); que.pop();
        if(vis[v]) continue;
        vis[v]=true;
        int to=-1,id=-1;
        for(auto p:G[v])
        {
            if(vis[p.F]) continue;
            to=p.F;
            id=p.S;
            break;
        }
        if(to==-1) break;
        if(a[v]>=x)//delete edge now
        {
            a[to]=a[v]+a[to]-x;
            v1.push_back(id);
        }
        else//delete edge last
        {
            v2.push_back(id);
        }
        deg[to]--;
        if(deg[to]==1) que.push(to);
    }
    reverse(v2.begin(),v2.end());
    for(auto x:v1) printf("%d\n",x);
    for(auto x:v2) printf("%d\n" ,x);
    return 0;
}