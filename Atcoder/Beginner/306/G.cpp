#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int T,n,m;
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
int g,cmp[MAXN];
int color[MAXN],dep[MAXN],fa[MAXN],cnt[MAXN];
bool flag;
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<(int)rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    for(int i=1;i<=n;i++) used[i]=0;
    vs.clear();
    for(int v=1;v<=n;v++) if(!used[v]) dfs(v);
    int k=0;
    for(int i=1;i<=n;i++) used[i]=0;
    for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}
void dfs2(int v,int d){
    color[v]=1; dep[v]=d; 
    for(auto to:G[v]){
        if(cmp[to]!=cmp[1]) continue;
        if(color[to]==1){
            g=gcd(g,dep[v]-dep[to]+1);
        }
        else if(color[to]==0) dfs2(to,d+1);
        else g=gcd(g,dep[to]-dep[v]-1);
    }
    color[v]=2;
}
void dfs3(int v){
    color[v]=1;
    for(auto to:G[v]){
        if(cmp[to]!=cmp[1]) continue;
        if(color[to]==0) {dfs3(to); cnt[v]+=cnt[to];}
    }
    if(cnt[v]>=2) flag=true; 
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {G[i].clear(); rG[i].clear();}
        for(int i=0;i<m;i++){
            int u,v; scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        scc();
        for(int i=1;i<=n;i++) color[i]=0;
        g=0;
        for(int i=1;i<=n;i++) cnt[i]=0;
        flag=false;
        dfs2(1,0);
        for(int i=1;i<=n;i++) cnt[i]=0;
        //dfs3(1);
        if(g==0) {puts("No"); continue;}
        if(flag) {puts("Yes"); continue;}
        while(g>0&&(g%2==0)) g/=2;
        while(g>0&&(g%5==0)) g/=5;
        if(g==1) puts("Yes"); else puts("No");
    }
    return 0;
}
