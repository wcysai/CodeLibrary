#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int n,m,q,tot,a[MAXN];
int u[MAXN],v[MAXN],st[MAXN],ed[MAXN];
vector<P> cp;
vector<int> G[MAXN];
int pa[MAXLOGN][MAXN];
ll bit[2][MAXN];
int depth[MAXN];
ll sum(int id,int i){
    ll s=0;
    while(i>0){
        s+=bit[id][i];
        i-=i&-i;
    }
    return s;
}
void add(int id,int i,int x){
    while(i<=n){
        bit[id][i]+=x;
        i+=i&-i;
    }
}
int get_fa(int id){
    if(depth[u[id]]>depth[v[id]]) return u[id]; else return v[id];
}
void add_edge(int u,int v){
    G[u].push_back(v); G[v].push_back(u);
}
struct query{
    int s,t,x;
    ll y;
    int id;
};
vector<query> vq;
void dfs(int v,int p,int d)
{
    pa[0][v]=p; st[v]=++tot;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    ed[v]=tot;
}
void init(int V){
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++){
        for(int v=1;v<=V;v++){
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x){
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--){
        if(pa[k][u]!=pa[k][v]){
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int dis(int u,int v){
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void add_cp(int c,int p,int d){
    int v=get_fa(p);
    add(0,st[v],d); add(0,ed[v]+1,-d);
    add(1,st[v],c*d); add(1,ed[v]+1,-c*d);
}
P query_path(int u,int v){
    int l=lca(u,v);
    ll c=sum(1,st[u])+sum(1,st[v])-2*sum(1,st[l]);
    int cnt=sum(0,st[u])+sum(0,st[v])-2*sum(0,st[l]);
    return make_pair(cnt,c);
}
int num[MAXN];
void solve(int l,int r,vector<query> &vq){//all values<l has been added
    if(l>r) return;
    int mid=(l+r)/2;
    for(int i=l;i<=mid;i++) add_cp(cp[i].F,cp[i].S,1);
    vector<query> lhs,rhs;
    for(auto qq:vq){
        P p=query_path(qq.s,qq.t);
        if(p.S>qq.y) lhs.push_back(qq);
        else{
            //printf("l=%d r=%d id=%d F=%d S=%lld\n",l,r,qq.id,p.F,p.S);
            num[qq.id]=max(num[qq.id],p.F);
            rhs.push_back(qq);
        }
    }
    solve(mid+1,r,rhs);
    for(int i=l;i<=mid;i++) add_cp(cp[i].F,cp[i].S,-1);
    solve(l,mid-1,lhs);
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&u[i],&v[i]);
        add_edge(u[i],v[i]);
    }
    init(n);
    for(int i=0;i<m;i++){
        int p,c;
        scanf("%d%d",&p,&c);
        cp.push_back(P(c,p));
    }
    sort(cp.begin(),cp.end());
    for(int i=0;i<q;i++){
        int s,t,x;
        ll y;
        scanf("%d%d%d%lld",&s,&t,&x,&y);
        vq.push_back((query){s,t,x,y,i});
    }
    int sz=(int)cp.size();
    solve(0,sz-1,vq);
    for(int i=0;i<sz;i++) add_cp(cp[i].F,cp[i].S,1);
    for(int i=0;i<q;i++){
        //printf("i=%d num=%d\n",i,num[i]);
        auto qq=vq[i];
        //printf("i=%d s=%d t=%d\n",i,qq.s,qq.t);
        P p=query_path(qq.s,qq.t);
        //printf("F=%d S=%lld\n",p.F,p.S);
        if(p.F-num[i]>qq.x) num[i]=-1;
        else num[i]=qq.x-(p.F-num[i]);
        printf("%d\n",num[i]);
    }
    return 0;
}

