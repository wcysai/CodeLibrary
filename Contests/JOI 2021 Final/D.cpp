#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m;
struct edge{int to,cost;};
map<int,vector<edge> > G[MAXN];
map<int,ll> mp[MAXN];
bool done[MAXN];
void add_edge(int u,int v,int col,int cost){
    G[u][col].push_back((edge){v,cost});
    G[v][col].push_back((edge){u,cost});
    mp[u][col]+=cost; mp[v][col]+=cost;
}
map<int,ll> d[MAXN];
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    d[s][0]=0;
    que.push(P(0,1LL*s*(m+1)));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.S/(m+1),c=p.S%(m+1);
        if(d[v][c]<p.F) continue;
        if(c){
            for(auto e:G[v][c]){
                ll cost=mp[v][c]-e.cost;
                if(d[e.to].find(0)==d[e.to].end()||d[e.to][0]>d[v][c]+cost){
                    d[e.to][0]=d[v][c]+cost;
                    que.push(P(d[e.to][0],1LL*e.to*(m+1)));
                }
            }
        }
        else{
            for(auto x:G[v]){
                int col=x.F;
                for(auto e:x.S){
                    if(d[e.to].find(col)==d[e.to].end()||d[e.to][col]>d[v][c]){
                        d[e.to][col]=d[v][c];
                        que.push(P(d[e.to][col],1LL*e.to*(m+1)+col));
                    }
                    ll cost=min(1LL*e.cost,mp[v][col]-e.cost);
                    if(d[e.to].find(0)==d[e.to].end()||d[e.to][0]>d[v][c]+cost){
                        d[e.to][0]=d[v][c]+cost;
                        que.push(P(d[e.to][0],1LL*e.to*(m+1)));
                    }
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c,p;
        scanf("%d%d%d%d",&a,&b,&c,&p);
        add_edge(a,b,c,p);
    }
    dijkstra(1);
    if(d[n].find(0)==d[n].end()) printf("-1\n"); else printf("%lld\n",d[n][0]);
    return 0;
}

