#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4005
#define MAXM 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,tot,t,bcc_cnt,mcnt;
vector<int> G[MAXN],H[MAXN],bcc[MAXN];
int st[MAXN],dfn[MAXN],low[MAXN],bccno[MAXN],sz[MAXN];
int U[MAXM],V[MAXM];
bool isbridge[MAXM];
//bridge tree:
//edge-biconnected components are connected by bridges
void add_edge(int u,int v)
{
    U[++mcnt]=u;V[mcnt]=v;
    G[u].push_back(mcnt);G[v].push_back(mcnt);
}
int adj(int u,int e)
{
    return U[e]==u?V[e]:U[e];
}
void dfs1(int v,int edge)
{
    dfn[v]=low[v]=++tot;
    st[t++]=v;
    for(auto e:G[v])
    {
        if(e==edge) continue;
        int to=adj(v,e);
        if(!dfn[to])
        {
            dfs1(to,e);
            low[v]=min(low[v],low[to]);
        }
        else low[v]=min(low[v],dfn[to]);
    }
    if(low[v]==dfn[v]&&edge!=-1) isbridge[edge]=true;
}
void dfs2(int v)
{
    dfn[v]=1;
    bccno[v]=bcc_cnt;
    for(auto e:G[v])
    {
        int to=adj(v,e);
        if(isbridge[e]) continue;
        if(!dfn[to]) dfs2(to);
    }
}
int tarjan()
{
    bcc_cnt=t=tot=0;
    memset(dfn,0,sizeof(dfn));
    memset(isbridge,false,sizeof(isbridge));
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs1(i,-1);
    memset(bccno,0,sizeof(bccno));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            bcc_cnt++;
            dfs2(i);
        }
    }
    return bcc_cnt;
}
int ban1,ban2,ban3,ban4,fa[MAXN],col[MAXN];
bool found;
vector<P> ans;
void dfs3(int v,int p){
    if(found) return;
    fa[v]=p; col[v]=1;
    if(v==ban4){
        found=true; 
        while(v!=ban3){
            ans.push_back(P(v,fa[v]));
            v=fa[v];
        }
        return;
    }
   // printf("v=%d p=%d\n",v,p);
    for(auto to:H[v]){
        if(to==p||to==ban1||to==ban2||(v==ban3&&to==ban4)) continue;
        if(col[to]==0) dfs3(to,v);
        if(found) return;
    }
    col[v]=2;
}
void try_find(int v,int u,int w){
    ban1=u; ban2=w; ban4=v;
    for(auto to:H[v]){
        if(to==u||to==w) continue;
        ban3=to;
        for(int i=1;i<=n;i++) col[i]=fa[i]=0;
    //    puts("here");
        dfs3(to,0);
        if(found) {ans.push_back(P(v,u)); ans.push_back(P(v,w)); ans.push_back(P(v,to)); return;}
    }
    //puts("done");
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m); mcnt=0;
        for(int i=1;i<=m;i++){
            int u,v; scanf("%d%d",&u,&v); add_edge(u,v);
            H[u].push_back(v); H[v].push_back(u);
        }
        tarjan();
       // puts("done");
        for(int i=1;i<=n;i++) sz[i]=0;
        for(int i=1;i<=n;i++) sz[bccno[i]]++;
        //for(int i=1;i<=n;i++)  printf("i=%d sz=%d\n",i,bccno[i]);
        ans.clear();
        found=false;
        for(int i=1;i<=n;i++){
            if(found) break;
            if(sz[bccno[i]]==1) continue;
            if((int)H[i].size()<4) continue;
            for(int j=0;j<(int)H[i].size();j++){
                if(found) break;
                for(int k=j+1;k<(int)H[i].size();k++){
                    try_find(i,H[i][j],H[i][k]);
                    if(found) break;
                }
            }
            assert(found);
        }
        if(!found) puts("NO");
        else{
            puts("YES");
            printf("%d\n",(int)ans.size());
            for(auto p:ans) printf("%d %d\n",p.F,p.S);
        }
        for(int i=1;i<=n;i++) G[i].clear(),H[i].clear();
    }
    return 0;
}


