#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int u,v,cost,id;};
int n,m;
int fa[MAXN];
ll s;
vector<edge> E;
vector<P> ans;
vector<int> num;
bool cmp(edge p,edge q)
{
    return p.cost>q.cost;
}
void init()
{
    for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
bool unite(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y) return false;
    fa[x]=y; return true;
}
int main()
{
    freopen("oil.in","r",stdin);
    freopen("oil.out","w",stdout);
    scanf("%d%d%lld",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        E.push_back((edge){u,v,c,i});
    }
    sort(E.begin(),E.end(),cmp);
    init();
    for(int i=0;i<m;i++)
    {
        if(unite(E[i].u,E[i].v)) continue;
        ans.push_back(P(E[i].cost,E[i].id));
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();i++)
    {
        if(ans[i].F<=s) {num.push_back(ans[i].S); s-=ans[i].F;}
        else break;
    }
    printf("%d\n",(int)num.size());
    sort(num.begin(),num.end());
    for(auto x:num) printf("%d ",x);
    return 0;
}

