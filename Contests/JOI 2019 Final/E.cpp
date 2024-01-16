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
int n,m,val[MAXN];
vector<int> G[MAXN];
int dep[2][MAXN];
int ans[2][MAXN];
int maxdep[2][2][MAXN];
int maxson[2][MAXN];
int v1,v2;
void dfs(int v,int p,int d,int id){
    dep[id][v]=d;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v,d+1,id);
    }
}
void dfs2(int v,int p,int id){
    for(auto to:G[v]){
        if(to==p) continue;
        dfs2(to,v,id);
        if(maxdep[id][0][to]+1>maxdep[id][0][v]){
            maxson[id][v]=to;
            maxdep[id][1][v]=maxdep[id][0][v];
            maxdep[id][0][v]=maxdep[id][0][to]+1;
        }
        else if(maxdep[id][0][to]+1>maxdep[id][1][v]) maxdep[id][1][v]=maxdep[id][0][to]+1;
    }
    //printf("v=%d p=%d id=%d maxson=%d dep=%d dep0=%d dep1=%d\n",v,p,id,maxson[id][v],dep[id][v],maxdep[id][0][v],maxdep[id][1][v]);
}
void get_diameter(){
    dfs(1,0,0,0);
    v1=1;
    for(int i=1;i<=n;i++) if(dep[0][i]>dep[0][v1]) v1=i;
    dfs(v1,0,0,0);
    v2=1;
    for(int i=1;i<=n;i++) if(dep[0][i]>dep[0][v2]) v2=i;
    dfs(v2,0,0,1);
    //printf("v1=%d v2=%d\n",v1,v2);
}
int res,st[MAXN],cnt[MAXN],t;
vector<pair<int&,int> > ret;
void modify(int &a,int b){
    //ret.push_back({a,a});
    a=b;
}
void rollback(int tt){
    while(ret.size()>tt){
        ret.back().F=ret.back().S;
        ret.pop_back();
    }
}
void add(int a){
    //printf("add %d\n",a);
    if(!cnt[val[a]]) modify(res,res+1);
    modify(cnt[val[a]],cnt[val[a]]+1);
}
void del(int a){
    //printf("del %d\n",a);
    modify(cnt[val[a]],cnt[val[a]]-1);
    if(!cnt[val[a]]) modify(res,res-1);
}
void dfs3(int v,int p,int id){
    //printf("v=%d p=%d id=%d\n",v,p,id);
    //int tt=(int)ret.size();
    if(p){
        modify(st[t],p);
        modify(t,t+1);
        add(p);
    }
    while(t>0&&dep[id][st[t-1]]>=dep[id][v]-maxdep[id][1][v]){
        del(st[t-1]);
        modify(t,t-1);
    }
    if(maxson[id][v]){
        //assert(maxson[id][v]!=p);
        dfs3(maxson[id][v],v,id);
    }
    while(t>0&&dep[id][st[t-1]]>=dep[id][v]-maxdep[id][0][v]){
        del(st[t-1]);
        modify(t,t-1);
    }
    ans[id][v]=res;
    for(auto to:G[v]){
        if(to==p||to==maxson[id][v]) continue;
        dfs3(to,v,id);
    }
    if(p&&G[v].size()==1&&t>0&&st[t-1]==p) {
        del(st[t-1]);
        t--;
    }
    //printf("tt=%d sz=%d\n",tt,(int)ret.size());
    //rollback(tt);    
}
void prepare(int v,int id){
    dfs2(v,0,id);
    dfs3(v,0,id);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    //puts("done");
    get_diameter();
    //puts("done");
    prepare(v1,0); prepare(v2,1);
    for(int i=1;i<=n;i++) if(dep[0][i]>=dep[1][i]) printf("%d\n",ans[0][i]); else printf("%d\n",ans[1][i]);
    return 0;
}

