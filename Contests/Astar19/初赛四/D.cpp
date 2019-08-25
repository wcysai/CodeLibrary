#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int T,n,m,k;
vector<int> G[MAXN];
vector<int> dis;
struct edge{int u,v,id,cost;};
int cnt;
bool cmp1(edge x,edge y)
{
    return x.cost<y.cost;
}
bool cmp2(edge x,edge y)
{
    return x.cost>y.cost;
}
int p[MAXN],r[MAXN];
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
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    cnt++;
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
vector<edge> E;
void kruskal(bool can[])
{
    init(n); cnt=0;
    for(auto e:E)
    {
        if(!same(e.u,e.v)) unite(e.u,e.v);
        if(cnt>=k) can[e.id]=true;
    }
}
set<int> s;
bool can1[MAXM],can2[MAXM];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(can1,false,sizeof(can1));
        memset(can2,false,sizeof(can2));
        E.clear(); s.clear();
        scanf("%d%d",&n,&m);
        k=n/2;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            E.push_back((edge){u,v,i,w});
        }
        sort(E.begin(),E.end(),cmp1); kruskal(can1);
        sort(E.begin(),E.end(),cmp2); kruskal(can2);
        for(auto e:E) if(can1[e.id]&&can2[e.id]) s.insert(e.cost);
        string str="";
        for(int i=0;i<m;i++) str+='0';
        for(auto e:E) if(s.count(e.cost)) str[e.id]='1';
        cout<<str<<endl;
    }
    return 0;
}
