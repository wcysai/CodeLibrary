#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
#define double long double
using namespace std;
typedef long long ll;
struct edge{int to; double cost;};
typedef pair<double,int> P;
int n,m,T;
vector<edge> G[MAXN];
double d[MAXN];
void add_edge(int u,int v,double cost)
{
    G[u].push_back((edge){v,cost});
    G[v].push_back((edge){u,cost});
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+n+1,1e13);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&T);
    for(int i=0;i<m;i++)
    {
        int u,v;
        double l,c;
        scanf("%d%d%Lf%Lf",&u,&v,&l,&c);
        add_edge(u,v,sqrt(l*c));
    }
    dijkstra(1);
    printf("%.15Lf\n",d[n]*d[n]/T);
    return 0;
}