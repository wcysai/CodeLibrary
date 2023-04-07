#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 6000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,tot,l[MAXN],r[MAXN];
vector<P> edges[4*MAXN];
int p[MAXN],rk[MAXN],id[MAXN];
vector<int> G[MAXM];
bool mark[MAXM];
int ans[MAXN];
vector<pair<int&,int> > backup;
void modify(int &ref,int v){
    backup.push_back({ref,ref});
    ref=v;
}
void rollback(int t){
    while((int)backup.size()>t){
        backup.back().F=backup.back().S;
        backup.pop_back();
    }
}
int t;
void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i; id[i]=i;
        rk[i]=0;
    }
    mark[1]=true; tot=n;
}
int find(int x){
   while(p[x]!=x) x=p[x];
   return x;
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    int uid=id[x],vid=id[y];
    ++tot; G[tot].push_back(uid); G[tot].push_back(vid);
    if(rk[x]<rk[y]){
        modify(p[x],y); modify(id[y],tot); 
    }
    else{
        modify(p[y],x); modify(id[x],tot);
        if(rk[x]==rk[y]) modify(rk[x],rk[x]+1); 
    }
    int z=find(1); if(id[z]==tot) mark[tot]=true;
    //printf("%d %d %d %d\n",tot,uid,vid,mark[tot]?1:0);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void add_edge(int k,int l,int r,int x,int y,int u,int v)
{
    if(x>r||l>y) return;
    if(l>=x&&r<=y){
        edges[k].push_back(P(u,v));
        return;
    }
    int mid=(l+r)/2;
    add_edge(k*2,l,mid,x,y,u,v);add_edge(k*2+1,mid+1,r,x,y,u,v);
}
void solve(int k,int l,int r)
{
    if(l>r) return;
    int t=(int)backup.size();
    for(auto e:edges[k]) unite(e.F,e.S);
    if(l==r){
        rollback(t);
        return;
    }
    int mid=(l+r)/2;
    solve(k*2,l,mid);solve(k*2+1,mid+1,r);
    //printf("cnt %d %d %d\n",l,r,cnt);
    rollback(t);
}
bool vis[MAXM];
void dfs(int v){
    vis[v]=true;
    for(auto to:G[v]) {
        if(!vis[to]) dfs(to);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        int lb=max(l[u],l[v]),rb=min(r[u],r[v]);
        if(lb<=rb) add_edge(1,1,200000,lb,rb,u,v);
    }
    solve(1,1,200000);
    for(int i=1;i<=tot;i++){
        if(!vis[i]&&mark[i]) dfs(i);
    }
    for(int i=1;i<=n;i++) if(vis[i]) printf("%d ",i);
    printf("\n");
    return 0;
}


