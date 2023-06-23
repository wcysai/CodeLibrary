#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,m;
ll k;
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
vector<int> comp[MAXN];
bool used[MAXN];
int g,cmp[MAXN];
int color[MAXN],dep[MAXN],dist[MAXN],fa[MAXN],cnt[MAXN];
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
void dfs2(int v,int root,int d){
    color[v]=1; dep[v]=d; 
    for(auto to:G[v]){
        if(cmp[to]!=cmp[root]) continue;
        if(color[to]==1){
            g=gcd(g,dep[v]-dep[to]+1);
        }
        else if(color[to]==0) dfs2(to,root,d+1);
        else g=gcd(g,dep[to]-dep[v]-1);
    }
    color[v]=2;
}
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=0;i<m;i++){
        int u,v; scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    int num=scc();
    for(int i=1;i<=n;i++) color[i]=0;
    for(int i=1;i<=n;i++) comp[cmp[i]].push_back(i);
    ll ans=0;
    for(int i=0;i<num;i++){
        g=0;
        if(comp[i].size()==1) continue;
        dfs2(comp[i][0],comp[i][0],0);
        int z=(k%g);
        if((2*z)%g!=0) continue;
        map<int,int> mp;
        for(auto x:comp[i]) mp[dep[x]%g]++;
        if(z==0)
        {
            ans+=(int)comp[i].size();
            for(auto p:mp) ans+=1LL*p.S*(p.S-1)/2;
        }
        else{
            ll res=0;
            for(auto p:mp) res+=1LL*p.S*mp[(z+p.F)%g];
            ans+=res/2;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
