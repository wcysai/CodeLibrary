#include<bits/stdc++.h>
#define MAXN 20005
using namespace std;
int T,n,m,n1,n2,tot;
string str[MAXN];
vector<int> G[MAXN];
int mx[MAXN],my[MAXN];
queue<int> que;
int dx[MAXN],dy[MAXN];
bool vis[MAXN];
void add_edge(int u,int v){
    G[u].push_back(v); G[v].push_back(u);
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
    for(int i=1;i<=tot;i++) mx[i]=my[i]=0;
    int ans=0;
    while(true){
        bool flag=false;
        while(!que.empty()) que.pop();
        for(int i=1;i<=tot;i++) dx[i]=dy[i]=0;
        for(int i=1;i<=n1;i++)
            if(!mx[i]) que.push(i);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int i=0;i<G[u].size();i++)
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
        for(int i=1;i<=tot;i++) vis[i]=false;
        for(int i=1;i<=n1;i++)
            if(!mx[i]&&find(i)) ans++;
    }
    return ans;
}
void dfs2(int u){
    vis[u]=true;
    for(auto to:G[u]){
        if(mx[to]&&!vis[mx[to]]){
            vis[to]=true;
            dfs2(mx[to]);
        }
    }
}
int wid[105][105],bid[105][105];
bool check(int x,int y,int c){
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(str[x+i][y+j]!='?'&&str[x+i][y+j]!=(c==0?'W':'B')) return false;
    return true;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) cin>>str[i];
        if(n==1||m==1){
            puts("0");
            for(int i=0;i<n;i++){ 
                for(int j=0;j<m;j++)
                    if(str[i][j]=='?') str[i][j]='B';
                cout<<str[i]<<endl;
            }
            continue;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(((i+j)&1)&&(str[i][j]!='?')) str[i][j]='B'+'W'-str[i][j];
        tot=0;
        for(int i=0;i<n-1;i++)
            for(int j=0;j<m-1;j++){
                wid[i][j]=0;
                if(check(i,j,0)) wid[i][j]=++tot; 
            }
        n1=tot;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                bid[i][j]=0;
                if(check(i,j,1)) bid[i][j]=++tot;
            }
        }
        for(int i=1;i<=tot;i++) G[i].clear();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(!wid[i][j]) continue;
                for(int dx=-1;dx<=1;dx++)
                    for(int dy=-1;dy<=1;dy++){
                        if(i+dx>=0&&i+dx<n-1&&j+dy>=0&&j+dy<m-1&&bid[i+dx][j+dy]) add_edge(wid[i][j],bid[i+dx][j+dy]);
                    }
            }
        }
        printf("%d\n",tot-matching());
        for(int i=1;i<=tot;i++) vis[i]=false;
        for(int i=n1+1;i<=tot;i++) if(!my[i]&&!vis[i]) dfs2(i);
        for(int i=0;i<n-1;i++)
            for(int j=0;j<m-1;j++){
                if(wid[i][j]&&!vis[wid[i][j]]){
                    str[i][j]=str[i][j+1]=str[i+1][j]=str[i+1][j+1]='W';
                }
                if(bid[i][j]&&vis[bid[i][j]]){
                    str[i][j]=str[i][j+1]=str[i+1][j]=str[i+1][j+1]='B';
                }
            }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(((i+j)&1)&&(str[i][j]!='?')) str[i][j]='B'+'W'-str[i][j];
                
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]=='?') str[i][j]='B';
        for(int i=0;i<n;i++) cout<<str[i]<<endl;
    }
    return 0;
}

