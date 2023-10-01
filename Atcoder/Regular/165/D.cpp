#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN],len[MAXN];
int cur[MAXN];
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
bool done[MAXN];
int cmp[MAXN],backup[MAXN];
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
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=n;v++) if(!used[v]) dfs(v);
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],++k);
    return k;
}
bool solve(){
    while(true){
        for(int i=1;i<=n;i++) G[i].clear(),rG[i].clear();
        for(int i=1;i<=m;i++){
            if(done[i]) continue;
            if(cur[i]>len[i]){
                if(b[i]-a[i]+1==len[i]&&d[i]-c[i]+1>len[i]) {
                    done[i]=true;
                }
                else return false;
            }
            else add_edge(cmp[a[i]+cur[i]-1],cmp[c[i]+cur[i]-1]);
        }
        for(int i=1;i<=n;i++) backup[i]=cmp[i];
        scc();
        for(int i=1;i<=n;i++) backup[i]=cmp[backup[i]];
        for(int i=1;i<=n;i++) cmp[i]=backup[i];
        //for(int i=1;i<=n;i++) printf("%d %d\n",i,cmp[i]);
        bool upd=false;
        for(int i=1;i<=m;i++){
            if(done[i]) continue;
            if(cmp[a[i]+cur[i]-1]==cmp[c[i]+cur[i]-1]) {cur[i]++; upd=true;}
        }
        if(!upd) return true;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        len[i]=min(b[i]-a[i]+1,d[i]-c[i]+1);
    }
    for(int i=1;i<=m;i++) cur[i]=1;
    for(int i=1;i<=n;i++) cmp[i]=i;
    if(solve()) printf("Yes\n"); else printf("No\n");
    return 0;
}

