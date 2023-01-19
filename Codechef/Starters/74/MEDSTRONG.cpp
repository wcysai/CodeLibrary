#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MOD 1000000007
using namespace std;
int t,n,m;
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
int cmp[MAXN],u[MAXN],v[MAXN],deg[MAXN],cnt[MAXN];
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
    for(int v=1;v<=m;v++) used[v]=false;
    vs.clear();
    for(int v=1;v<=m;v++) if(!used[v]) dfs(v);
    int k=0;
    for(int v=1;v<=m;v++) used[v]=false;
    for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=m;i++) {G[i].clear();rG[i].clear();deg[i]=0;cnt[i]=0;}
        for(int i=0;i<n;i++){
            scanf("%d%d",&u[i],&v[i]);
            add_edge(u[i],v[i]);
        }
        int k=scc();
        int ans=1;
        for(int i=0;i<n;i++){
            if(cmp[u[i]]!=cmp[v[i]]) deg[cmp[u[i]]]++;
        }
        for(int i=1;i<=m;i++) cnt[cmp[i]]++;
        for(int i=0;i<k;i++){
            if(deg[i]>0) ans=1LL*ans*pow_mod(2,cnt[i])%MOD;
            else ans=1LL*ans*(pow_mod(2,cnt[i])-1)%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}
