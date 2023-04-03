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
typedef pair<int,P> PP;
int t,n,m,p[MAXN],a[MAXN],sz[MAXN],cur;
vector<int> G[MAXN];
vector<P> edges[MAXN];
priority_queue<P,vector<P>,greater<P> > pque[MAXN];
void init(int n){
    for(int i=1;i<=n;i++) {
        p[i]=i;
        sz[i]=1;
        for(auto to:G[i]){
            pque[i].push(P(a[to],to));
        }
    }
}
int find(int x){
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y){
    //printf("x=%d y=%d\n",x,y);
    x=find(x); y=find(y);
    if(x==y) return; 
    if(pque[x].size()<pque[y].size()){
        sz[y]+=sz[x];
        p[x]=y;
        while(pque[x].size()){
            P p=pque[x].top(); pque[y].push(p); pque[x].pop();
        }
    }
    else{
        sz[x]+=sz[y];
        p[y]=x;
        while(pque[y].size()){
            P p=pque[y].top(); pque[x].push(p); pque[y].pop();
        }
    }
}
void solve(int x){
    x=find(x);
    while(pque[x].size()){
        P p=pque[x].top();
        if(sz[x]>=p.F){
            pque[x].pop();
            unite(x,p.S);
            x=find(x); continue;
        }
        else break;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++) edges[i].clear();
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        init(n);
        for(int i=1;i<=n;i++) if(a[i]==0) solve(i);
        if(sz[find(1)]==n) puts("YES"); else puts("NO");
        for(int i=1;i<=n;i++) while(pque[i].size()) pque[i].pop();
    }
    return 0;
}

