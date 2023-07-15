#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 100000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
struct edge{
    int to,cost;
};
vector<edge> G[MAXN];
int n,m;
ll d[MAXN][MAXN];
bool vis[MAXN];
void dfs(int v){
    vis[v]=true;
    for(int i=1;i<=n;i++){
        if(d[v][i]!=INF&&!vis[i]) dfs(i);
    }
}
vector<pair<string,ll> > v;
bool in[MAXN];
void bfs(){
    for(int i=1;i<=n;i++) in[i]=false;
    in[1]=true;
    queue<int> que; que.push(1);
    while(que.size()){
        int v=que.front(); que.pop();
        for(int i=1;i<=n;i++){
            if(d[v][i]==0&&!in[i]){
                in[i]=true;
                que.push(i);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=INF;
        }
        d[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        d[u][v]=d[v][u]=w;
    }
    dfs(1);
    if(!vis[n]) {puts("inf"); return 0;}
    ll ans=0;
    while(true){
        bfs();
        if(in[n]) break;
        string str="";
        for(int i=1;i<=n;i++) if(in[i]) str+='1'; else str+='0';
        ll res=INF;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(in[i]&&!in[j]) res=min(res,d[i][j]);
        v.push_back(make_pair(str,res));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(in[i]&&!in[j]) d[i][j]-=res;
        ans+=res;
    }
    printf("%lld %d\n",ans,(int)v.size());
    for(auto p:v) cout<<p.F<<" "<<p.S<<endl;
    return 0;
}

