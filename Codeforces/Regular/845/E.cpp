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
int t,n,m;
vector<int> G[MAXN],rG[MAXN];
int deg[MAXN];
vector<int> vs;
int u[MAXN],v[MAXN],w[MAXN],rk[MAXN];
bool used[MAXN];
int cmp[MAXN];
bool ccmp(int x,int y){
    return w[x]<w[y];
}
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
    for(int i=1;i<=n;i++) used[i]=false;
    vs.clear();
    for(int v=1;v<=n;v++) if(!used[v]) dfs(v);
    int k=0;
    for(int i=1;i<=n;i++) used[i]=false;
    for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}
bool check(int x)
{
    for(int i=1;i<=n;i++) G[i].clear(),rG[i].clear();
    for(int i=1;i<=m;i++) add_edge(u[i],v[i]);
    for(int i=1;i<=x;i++) add_edge(v[rk[i]],u[rk[i]]);
    int z=scc();
    for(int i=0;i<z;i++) deg[i]=0;
    for(int i=x+1;i<=m;i++){
        if(cmp[u[rk[i]]]!=cmp[v[rk[i]]]) deg[cmp[v[rk[i]]]]++;
    }
    int cnt=0;
    for(int i=0;i<z;i++) if(!deg[i]) {cnt++;}
    //printf("x=%d z=%d cnt=%d\n",x,z,cnt);
    return (cnt==1);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]);
        for(int i=1;i<=m;i++) rk[i]=i;
        sort(rk+1,rk+m+1,ccmp);
        int l=-1,r=m+1;
        while(r-l>1){
            int mid=(l+r)/2;
            if(check(mid)) r=mid; else l=mid;
        }
        if(r==m+1) puts("-1"); else if(r==0) puts("0"); else printf("%d\n",w[rk[r]]);
    }
    return 0;
}

