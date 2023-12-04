#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
vector<P> G[MAXN];
void add_edge(int u,int v,int c){
    G[u].push_back(P(v,c));
    G[v].push_back(P(u,c));
}
int color[MAXN],col[MAXN],fa[MAXN];
vector<P> cyc;
void dfs(int v,int p,int fc){
    color[v]=1; fa[v]=p; col[v]=fc; if(cyc.size()) return;
    for(auto q:G[v]){
        int to=q.F,c=q.S;
        if(to==p) continue;
        if(cyc.size()) return;
        if(color[to]==0) dfs(to,v,c);
        else if(color[to]==1){
            cyc.push_back(P(v,col[c]));
            int now=v;
            do{
                now=fa[now];
                if(now==to) cyc.push_back(P(now,c)); else cyc.push_back(P(now,col[now]));
            }while(now!=to);
        }
    }
}
void go(){
    int sz=(int)cyc.size();
    int len=(sz+2)/2;
    if(len&1) len--; 
    int u=cyc[0].F,v=cyc[len-1].F;
    int x,y;
    if(u>n) {y=u-n; x=v;} else {y=v-n; x=u;}
    printf("? %d %d\n",x,y); fflush(stdout);
    int c;
    scanf("%d",&c);
    bool fst=true;
    for(int i=0;i<len;i++) if(cyc[i].S==c) fst=false;
    if(fst){
        while(cyc.back().F!=v) cyc.pop_back();
        cyc.back().S=c;
    }
    else{
        reverse(cyc.begin(),cyc.end());
        while(cyc.back().F!=v) cyc.pop_back();
        cyc.push_back(P(u,c));
    }
}
void answer(){
    vector<int> x,y;
    for(auto p:cyc){
        if(p.F>n) y.push_back(p.F-n); else x.push_back(p.F);
    }
    printf("! %d %d %d %d\n",x[0],x[1],y[0],y[1]); fflush(stdout);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) G[i].clear();
        for(int i=1;i<=2*n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(x,n+y,i);
        }
        for(int i=1;i<=2*n;i++) color[i]=0;
        cyc.clear();
        for(int i=1;i<=2*n;i++) if(!color[i]) dfs(i,0,0);
        for(auto p:cyc) printf("%d %d\n",p.F,p.S);
        while(cyc.size()>4) go();
        answer();
    }
    return 0;
}

