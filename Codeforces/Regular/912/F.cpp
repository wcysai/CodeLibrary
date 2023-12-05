#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
int cmp[MAXN];
void add_graph_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}
void add_edge(int u,int shift,int k,int l,int r,int x,int y){
    if(l>y||x>r) return;
    if(l>=x&&r<=y){
        add_graph_edge(u,shift+k);
        return;
    }
    int mid=(l+r)/2;
    add_edge(u,shift,k*2,l,mid,x,y); add_edge(u,shift,k*2+1,mid+1,r,x,y);
}
void add_edge2(int u,int shift,int k,int l,int r,int x,int y){
    if(l>y||x>r) return;
    if(l>=x&&r<=y){
        add_graph_edge(shift+k,u);
        return;
    }
    int mid=(l+r)/2;
    add_edge2(u,shift,k*2,l,mid,x,y); add_edge2(u,shift,k*2+1,mid+1,r,x,y);
}
void dfs(int v){
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k){
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<(int)rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=8*n;v++) if(!used[v]) dfs(v);
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}
int id1[MAXN],id2[MAXN];
void build(int shift,int k,int l,int r){
    if(l==r) {if(shift) id2[l]=shift+k; else id1[l]=shift+k; return;}
    int mid=(l+r)/2;
    build(shift,k*2,l,mid); build(shift,k*2+1,mid+1,r);
    if(!shift) add_graph_edge(k+shift,k*2+shift); else add_graph_edge(k*2+shift,k+shift);
    if(!shift) add_graph_edge(k+shift,k*2+1+shift); else add_graph_edge(k*2+1+shift,k+shift);
}
int u[MAXN],v[MAXN];
bool check(int val){
    for(int i=1;i<=8*n;i++) {G[i].clear(); rG[i].clear();}
    build(0,1,1,n);
    build(4*n,1,1,n);
   // for(int i=1;i<=n;i++) printf("%d %d %d\n",i,id1[i],id2[i]);
    for(int i=0;i<m;i++){
        add_graph_edge(id1[u[i]],id2[v[i]]);
        add_graph_edge(id1[v[i]],id2[u[i]]);
    }
    for(int i=1;i<=n;i++){
        int l=max(1,i-val+1),r=i-1;
        if(l<=r) {add_edge(id2[i],0,1,1,n,l,r); add_edge2(id1[i],4*n,1,1,n,l,r);}
        l=i+1; r=min(n,i+val-1);
        if(l<=r) {add_edge(id2[i],0,1,1,n,l,r); add_edge2(id1[i],4*n,1,1,n,l,r);}
    }
    scc();
    //printf("val=%d\n",val);
    for(int i=1;i<=n;i++) 
    {
       // printf("%d %d %d %d %d\n",i,id1[i],id2[i],cmp[id1[i]],cmp[id2[i]]);
        if(cmp[id1[i]]==cmp[id2[i]]) return false;
    }
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&u[i],&v[i]);
        }
        int l=1,r=n+1;
        while(r-l>1){
            int mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        for(int i=1;i<=8*n;i++) {G[i].clear(); rG[i].clear();}
        printf("%d\n",l);
    }
    return 0;
}

