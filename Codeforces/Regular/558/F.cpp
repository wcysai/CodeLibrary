#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,m,q;
ll L[MAXN],R[MAXN];
struct edge{
    int to,cost,id;
};
vector<edge> G[MAXN];
ll ans[MAXN];
void add_edge(int u,int v,int cost,int id){
    G[u].push_back((edge){v,cost,id});
    G[v].push_back((edge){u,cost,id});
}
vector<ll> dijkstra(int s){
    vector<ll> d(n+1,INF);
    priority_queue<P,vector<P>,greater<P> > que;
    for(int i=1;i<=n;i++) d[i]=INF;
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
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
int onpath[MAXN];
int u[MAXN],v[MAXN],w[MAXN];
vector<ll> d1,d2;
bool cmp1(int u,int v){
    return d1[u]<d1[v];
}
bool cmp2(int u,int v){
    return d2[u]<d2[v];
}
vector<P> upd[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        add_edge(u[i],v[i],w[i],i);
    }
    d1=dijkstra(1); d2=dijkstra(n);
    vector<int> path;
    int now=1,cnt=0;
    while(now!=n){
        for(auto e:G[now]){
            if(d2[e.to]+e.cost==d2[now]){
                path.push_back(e.id); onpath[e.id]=++cnt;
                now=e.to;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) L[i]=R[i]=INF;
    int sz=(int)path.size();
    vector<int> vpath; vpath.push_back(1);
    now=1; cnt=0;
    for(auto id:path){
        L[now]=cnt; R[now]=++cnt;
        now=(u[id]==now?v[id]:u[id]); vpath.push_back(now);
        //printf("now=%d\n",now);
    }
    L[now]=cnt; R[now]=++cnt;
    for(int i=0;i<(int)vpath.size();i++){
        int x=vpath[i];
        queue<int> que;
        que.push(x);
        while(que.size()){
            int v=que.front(); que.pop();
            for(auto e:G[v]){
                if(d1[v]+e.cost==d1[e.to]&&L[e.to]==INF){
                    L[e.to]=L[v];
                    que.push(e.to);
                }
            }
        }
    }
    for(int i=(int)vpath.size()-1;i>=0;i--){
        int x=vpath[i];
        queue<int> que;
        que.push(x);
        while(que.size()){
            int v=que.front(); que.pop();
            for(auto e:G[v]){
                if(d2[v]+e.cost==d2[e.to]&&R[e.to]==INF){
                    R[e.to]=R[v];
                    que.push(e.to);
                }
            }
        }
    }
    for(int i=1;i<=n;i++) ans[i]=INF;
    for(int i=1;i<=m;i++){
        if(onpath[i]) continue;
        if(L[u[i]]+1<R[v[i]]){
            ll dist=d1[u[i]]+d2[v[i]]+w[i];
            upd[L[u[i]]+1].push_back(P(dist,1));
            upd[R[v[i]]].push_back(P(dist,-1));
        }
        if(L[v[i]]+1<R[u[i]]){
            ll dist=d1[v[i]]+d2[u[i]]+w[i];
            upd[L[v[i]]+1].push_back(P(dist,1));
            upd[R[u[i]]].push_back(P(dist,-1));
        }
    }
    multiset<ll> ms;
    for(int i=1;i<=sz;i++){
        for(auto p:upd[i]){
            if(p.S==-1) ms.erase(ms.find(p.F));
            else ms.insert(p.F);
        }
        if(ms.size()) ans[i]=*ms.begin();
    }
    for(int i=0;i<q;i++){
        int id,x;
        scanf("%d%d",&id,&x);
        if(x<w[id]){
            printf("%lld\n",min(d1[n],min(d1[u[id]]+d2[v[id]]+x,d1[v[id]]+d2[u[id]]+x)));
        }
        else{
            if(!onpath[id]) printf("%lld\n",d1[n]);
            else{
                ll res=d1[n]+x-w[id];
                printf("%lld\n",min(res,ans[onpath[id]]));
            }
        }
    }
    return 0;
}

