#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
struct edge{int to,cost;};
typedef pair<ll,int> P;
int n,m,s,t,l;
ll k;
vector<edge> G[MAXN];
void add_edge(int u,int v,int w){
    G[u].push_back((edge){v,w});
    G[v].push_back((edge){u,w});
}
vector<ll> dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    vector<ll> d(n+1);
    fill(d.begin(),d.end(),INF);
    d[0]=0; d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    return d;
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%lld",&s,&t,&l,&k);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    auto ds=dijkstra(s);
    auto dt=dijkstra(t);
    if(ds[t]<=k) {printf("%lld\n",1LL*n*(n-1)/2); return 0;}
    ll ans=0;
    sort(ds.begin(),ds.end()); sort(dt.begin(),dt.end());
    int now=n;
    for(int i=1;i<=n;i++){
        while(now>0&&ds[i]+dt[now]+l>k) now--;
        ans+=now;
    }
    printf("%lld\n",ans);
    return 0;
}

