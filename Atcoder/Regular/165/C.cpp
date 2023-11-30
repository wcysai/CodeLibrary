#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int p[MAXN],c[MAXN];
int val[MAXN];
struct edge{
    int u,v,cost;
};
bool cmp(edge &x,edge &y){
    return x.cost<y.cost;
}
vector<edge> E;
void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i;
        c[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else 
    {
        int y=find(p[x]);
        c[x]^=c[p[x]];
        p[x]=y;
        return p[x];
    }
}
void unite(int x,int y)
{
    int px=find(x);
    int py=find(y);
    p[px]=py;
    if(c[x]==c[y]) c[px]^=1;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        E.push_back((edge){u,v,w});
    }
    for(int i=1;i<=n;i++) val[i]=INF;
    sort(E.begin(),E.end(),cmp);
    init(n);
    int maxi=INF;
    for(int i=0;i<(int)E.size();i++){
        int u=E[i].u,v=E[i].v,cost=E[i].cost;
        if(cost+1>maxi) break;
        if(same(u,v)){
            if(c[u]==c[v]) {maxi=cost; break;}
            else{
                maxi=min(maxi,cost+val[u]);
                maxi=min(maxi,cost+val[v]);
                val[u]=min(val[u],cost);
                val[v]=min(val[v],cost);
            }
        }
        else{
            maxi=min(maxi,cost+val[u]);
            maxi=min(maxi,cost+val[v]);
            unite(u,v);
            val[u]=min(val[u],cost);
            val[v]=min(val[v],cost);
        }
    }
    printf("%lld\n",maxi);
    return 0;
}

