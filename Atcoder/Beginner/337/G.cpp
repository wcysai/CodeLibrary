#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> G[MAXN];
int sz[MAXN],wson[MAXN],fa[MAXN],bit[MAXN],res[MAXN];
ll dp[MAXN],ans[MAXN];
void dfs(int v,int p){
    sz[v]=1;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
    //printf("v=%d wson=%d\n",v,wson[v]);
}
int sum(int i){
    //printf("sum %d\n",i);
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    //printf("add %d %d\n",i,x);
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
void add_sub(int v,int p){
    add(v,1);
    for(auto to:G[v]){
        if(to==p) continue;
        add_sub(to,v);
    }
}
void del_sub(int v,int p){
    add(v,-1);
    for(auto to:G[v]){
        if(to==p) continue;
        del_sub(to,v);
    }
}
void dfs2(int v,int p){
    //printf("v=%d p=%d\n",v,p);
    for(auto to:G[v]){
        if(to==p||to==wson[v]) continue;
        dfs2(to,v);
        dp[v]+=dp[to];
        fa[to]=sum(v-1);
        del_sub(to,v);
    }
    if(wson[v]){
        dfs2(wson[v],v);
        dp[v]+=dp[wson[v]];
        fa[wson[v]]=sum(v-1);
    }
    for(auto to:G[v]){
        if(to==p||to==wson[v]) continue;
        add_sub(to,v);
    }
    add(v,1);
    res[v]=sum(v-1);
    dp[v]+=res[v];
    //printf("v=%d dp=%lld\n",v,dp[v]);
}
void dfs3(int v,int p){
    for(auto to:G[v]){
        if(to==p) continue;
        ans[to]=ans[v]-fa[to]+to-1-res[to];
        dfs3(to,v);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    ans[1]=dp[1];
    //for(int i=1;i<=n;i++) printf("%d %lld %lld\n",i,dp[i],fa[i]);
    dfs3(1,0);
    for(int i=1;i<=n;i++) printf("%lld%c",ans[i],i==n?'\n':' ');
    return 0;
}

