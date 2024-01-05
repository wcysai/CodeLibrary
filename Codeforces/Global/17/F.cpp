#pragma GCC optimize(3)
#pragma comment(linker,"/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
struct edge{int to,del,rev,id;};
vector<edge> G[MAXN];
int ans[MAXN],now[MAXN];
bool vis[MAXN];
int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
void add_edge(int u,int v,int id){
    G[u].push_back((edge){v,0,(int)G[v].size(),id});
    G[v].push_back((edge){u,0,(int)G[u].size()-1,-id});
}
int tot=0;
void hierholzer(int v){
    vis[v]=true;
    while(now[v]<(int)G[v].size()){
        auto &e=G[v][now[v]];
        if(e.del) {now[v]++; continue;}
        if(e.id>0) ans[e.id]=1; else if(e.id<0) ans[-e.id]=2;
        e.del=1; G[e.to][e.rev].del=1;
        hierholzer(e.to);
        now[v]++;
    }
    //tot--;
}
int main(){
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read(); v=read(); w=read();
        if(w==2) add_edge(n+u,n+v,i);
        else add_edge(u,v,i);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        int d1=(int)G[i].size(),d2=(int)G[n+i].size();
        d1&=1; d2&=1;
        if(d1) res++;
        if(d1&&d2){
            add_edge(i,n+i,0);
        }
        else if(d1){
            add_edge(i,2*n+1,0);
        }
        else if(d2){
            add_edge(n+i,2*n+1,0);
        }
    }
    for(int i=1;i<=2*n+1;i++) if(!vis[i]) hierholzer(i);
    printf("%d\n",res);
    for(int i=1;i<=m;i++) printf("%d",ans[i]);
    printf("\n");
    return 0;
}

