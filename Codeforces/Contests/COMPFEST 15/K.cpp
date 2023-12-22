#include<bits/stdc++.h>
#define int long long 
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,q,fa[MAXN];
ll diam;
vector<P> G[MAXN];
P f1[MAXN],f2[MAXN];
ll g[MAXN];
vector<P> qry[MAXN];
ll ans[MAXN];
void add_edge(int u,int v,int w){
    G[u].push_back(P(v,w));
    G[v].push_back(P(u,w));
}
void dfs(int v,int p){
    fa[v]=p;
    for(auto e:G[v]){
        int to=e.F,cost=e.S;
        if(to==p) continue;
        dfs(to,v);
        P pp=make_pair(f1[to].F+cost,to);
        if(pp>f1[v]){
            f2[v]=f1[v];
            f1[v]=pp;
        }
        else if(pp>f2[v]) f2[v]=pp;
    }
   // printf("v=%d (%lld %lld) (%lld %lld\n)",v,f1[v].F,f1[v].S,f2[v].F,f2[v].S);
    diam=max(diam,f1[v].F+f2[v].F);
}
void dfs2(int v,int p){
    for(auto e:G[v]){
        int to=e.F,cost=e.S;
        if(to==p) continue;
        g[to]=cost+g[v];
        if(f1[v].S!=to) g[to]=max(g[to],cost+f1[v].F); else g[to]=max(g[to],cost+f2[v].F);
        dfs2(to,v);
    }
    //printf("v=%d g=%lld\n",v,g[v]);
}
vector<pair<ll,ll> > st[MAXN];
void add(int id,ll u,ll v){
    //printf("add %d %lld %lld\n",id,u,v);
    P p=P(u,v);
    int t=(int)st[id].size();
    auto &s=st[id];
    while(t>1&&(__int128)(s[t-1].F-s[t-2].F)*(p.S-s[t-1].S)>=(__int128)(s[t-1].F-p.F)*(s[t-2].S-s[t-1].S)) {s.pop_back(); t=s.size();}
    s.push_back(p);
}
P query(int id,ll x){
    ll l=-1,r=st[id].size()-1;
    if(l==r) return P(0,0);
    auto &s=st[id];
    while(r-l>1){
        ll mid=(l+r)/2;
        if(s[mid].F*x+s[mid].S<=s[mid+1].F*x+s[mid+1].S) l=mid;
        else r=mid;
    }
    return P(r,s[r].F*x+s[r].S);
}
signed main(){
    scanf("%lld",&n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add_edge(u,v,w);
    }
    dfs(1,0);
    dfs2(1,0);
    scanf("%lld",&q); 
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%lld%lld",&x,&y); y--;
        qry[x].push_back(P(y,i));
    }
    for(int i=1;i<=n;i++){
        vector<P> lines;
        for(auto e:G[i]){
            int to=e.F,cost=e.S;
            ll res;
            if(to==fa[i]) res=g[i]; else res=cost+f1[to].F;
            lines.push_back(P(cost,res));
        }
        sort(lines.begin(),lines.end());
        for(auto p:lines) add(0,p.F,p.S);
        int cur=0;
        for(auto p:lines){
            if(cur<(int)st[0].size()&&p==st[0][cur]){
                if(cur>0) add(cur,p.F,p.S);
                cur++;
                if(cur<(int)st[0].size()) add(cur+1,p.F,p.S);
                continue;
            }
            //printf("cur=%d\n",cur);
            if(cur>0) add(cur,p.F,p.S);
            if(cur<(int)st[0].size()) add(cur+1,p.F,p.S);
        }
        for(auto p:qry[i]){
            P res=query(0,p.F);
            //printf("F=%lld S=%lld resF=%lld resS=%lld\n",p.F,p.S,res.F,res.S);
            ans[p.S]=max(diam,res.S+query(res.F+1,p.F).S);
        }
        int sz=(int)st[0].size();
        for(int i=0;i<=sz;i++) st[i].clear();
    }
    for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}

