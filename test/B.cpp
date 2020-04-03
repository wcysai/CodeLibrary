#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<P> G[MAXN];
int d[MAXN];
void add_edge(int u,int v,int cost)
{
    G[u].push_back(P(v,cost));
    G[v].push_back(P(u,cost));
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+n+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            P e=G[v][i];
            if(d[e.F]>d[v]+e.S)
            {
                d[e.F]=d[v]+e.S;
                que.push(P(d[e.F],e.F));
            }
        }
    }
}
struct edge{int from;int to;int cost;int cap;};
bool cmp(edge x,edge y)
{
    return x.cap<y.cap;
}
vector<edge> v;
double ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        v.push_back((edge){a,b,c,d});
    }
    sort(v.begin(),v.end(),cmp);
    ans=INF;
    while(v.size())
    {
        int x=v.back().cap;
        while(v.size()&&v.back().cap==x)
        {
            int from=v.back().from;
            int to=v.back().to;
            int cost=v.back().cost;
            add_edge(from,to,cost);
            v.pop_back();
        }
        dijkstra(1);
        if(d[n]==INF) continue;
        ans=min(ans,(double)x/d[n]);
    }
    printf("%lld\n",(long long)(ans*1000000));
    return 0;
}