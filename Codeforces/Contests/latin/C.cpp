#include<bits/stdc++.h>
#define MAXN 2505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
char mp[55][55];
vector<int> G[MAXN];
int mx[MAXN],my[MAXN];
queue<int> que;
int dx[MAXN],dy[MAXN];
bool vs[MAXN],vis[MAXN];
int sx[4]={-1,1,0,0};
int sy[4]={0,0,-1,1};
vector<int> L,R;
void add_edge(int u,int v){
    G[u].push_back(v); G[v].push_back(u);
}
int get_id(int x,int y){
    return (x-1)*m+y;
}
void dfsx(int v){
    vis[v]=true;
    for(auto to:G[v])
        if(mx[v]!=to&&!vis[my[to]]) dfsx(my[to]);
}
void dfsy(int v){
    vis[v]=true;
    for(auto to:G[v])
        if(my[v]!=to&&!vis[mx[to]]) dfsy(mx[to]);
}
bool find(int u){
    for(int i=0;i<G[u].size();i++){
        if(!vis[G[u][i]]&&dy[G[u][i]]==dx[u]+1){
            vis[G[u][i]]=true;
            if(!my[G[u][i]]||find(my[G[u][i]])){
                mx[u]=G[u][i];
                my[G[u][i]]=u;
                return true;
            }
        }
    }
    return false;
}
int matching(){
    memset(mx,0,sizeof(mx));
    memset(my,0,sizeof(my));
    int ans=0;
    while(true){
        bool flag=false;
        while(!que.empty()) que.pop();
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        for(auto i:L) if(!mx[i]) que.push(i);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int i=0;i<(int)G[u].size();i++)
                if(!dy[G[u][i]]){
                    dy[G[u][i]]=dx[u]+1;
                    if(my[G[u][i]]){
                        dx[my[G[u][i]]]=dy[G[u][i]]+1;
                        que.push(my[G[u][i]]);
                    }
                    else flag=true;
                }
        }
        if(!flag) break;
        memset(vis,false,sizeof(vis));
        for(auto i:L) if(!mx[i]&&find(i)) ans++;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]=='.')
                if((i+j)&1) L.push_back(get_id(i,j)); else R.push_back(get_id(i,j));
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]=='.'&&mp[i+1][j]=='.')
                add_edge(get_id(i,j),get_id(i+1,j));
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++)
            if(mp[i][j]=='.'&&mp[i][j+1]=='.')
                add_edge(get_id(i,j),get_id(i,j+1));
    matching();
    memset(vis,false,sizeof(vis));
    for(auto x:L) if(!mx[x]) dfsx(x);
    for(auto x:R) if(!my[x]) dfsy(x);
    int ans=0;
    for(auto x:L) if(vis[x]) ans++;
    for(auto x:R) if(vis[x]) ans++;
    printf("%d\n",ans);
    return 0;
}

