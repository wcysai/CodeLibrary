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
int n,m,k,a[MAXN],b[MAXN];
vector<int> G[MAXN];
int d[MAXN];
int go(int v,int to)
{
    if(d[v]==k) return k;
    if(b[d[v]+1]==a[to]) return d[v]+1;
    return d[v];
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+n+1,k);
    d[s]=(a[s]==b[1]?1:0);
    que.push(P(d[s],s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(auto to:G[v])
        {
            if(d[to]>go(v,to))
            {
                d[to]=go(v,to);
                que.push(P(d[to],to));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=k;i++) scanf("%d",&b[i]);
    dijkstra(1);
    if(d[n]==k) puts("Yes"); else puts("No");
    return 0;
}

