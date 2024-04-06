#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
int n,m,V;
vector<int> G[MAXN];
int match[MAXN];
bool used[MAXN];
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w)){
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching(){
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=1;v<=V;v++){
        if(match[v]<0){
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    V=n+m;
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int x; scanf("%d",&x);
            add_edge(i,n+x);
        }
    }
    printf("%d\n",bipartite_matching());
    return 0;
}
