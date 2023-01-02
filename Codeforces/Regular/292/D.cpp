#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,q,a[MAXN],id;
vector<P> G[MAXN]; 
ll f[MAXN],g[MAXN],h[MAXN];
int ans[MAXN];
void dfs1(int v,int p){
    f[v]=0;
    for(auto e:G[v]){
        int to=e.F,cost=e.S;
        if(to==p) continue;
        dfs1(to,v);
        f[v]=max(f[v],f[to]+cost);
    }
}
void dfs2(int v,int p){
    vector<ll> tmp;
    for(auto e:G[v]){
        int to=e.F,cost=e.S;
        if(to==p) continue;
        tmp.push_back(cost+f[to]);
    }
    int sz=(int)tmp.size();
    vector<ll> pre(sz+1,0),suf(sz+1,0);
    pre[0]=suf[sz]=0;
    for(int i=1;i<=sz;i++) pre[i]=max(pre[i-1],tmp[i-1]);
    for(int i=sz-1;i>=0;i--) suf[i]=max(suf[i+1],tmp[i]);
    int tot=0;
    for(auto e:G[v]){
        int to=e.F,cost=e.S;
        if(to==p) continue;
        g[to]=cost+max(g[v],max(pre[tot],suf[tot+1]));
        tot++;
    }
    for(auto e:G[v]){
        int to=e.F,cost=e.S;
        if(to==p) continue;
        dfs2(to,v);
    }
}
vector<P> st;
void dfs(int v,int p,ll maxi){
    ans[v]++;
    if(st.size()){
        if(st[0].F<h[v]-maxi){
            int pos=lower_bound(st.begin(),st.end(),P(h[v]-maxi,0))-st.begin()-1;
            ans[st[pos].S]--;
        }
    }
    st.push_back(P(h[v],v));
    for(auto e:G[v]){
        int to=e.F,cost=e.S;
        if(to==p) continue;
        dfs(to,v,maxi);
        ans[v]+=ans[to];
    }
    st.pop_back();
}
void solve(ll maxi){
    for(int i=1;i<=n;i++) ans[i]=0;
    dfs(id,0,maxi);
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,ans[i]);
    printf("%d\n",res);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(P(v,w));G[v].push_back(P(u,w));
    }
    if(n==2) {h[1]=h[2]=G[1][0].S;}
    else{
        int root=0;
        for(int i=1;i<=n;i++) if(G[i].size()!=1) {root=i; break;}
        dfs1(root,0); g[root]=-INF; dfs2(root,0);
        for(int i=1;i<=n;i++) h[i]=max(f[i],g[i]);
    }
    id=1;
    for(int i=2;i<=n;i++) if(h[i]<h[id]) id=i;
    scanf("%d",&q);
    while(q--){
        ll x;
        scanf("%lld",&x); solve(x);
    }
    return 0;
}

