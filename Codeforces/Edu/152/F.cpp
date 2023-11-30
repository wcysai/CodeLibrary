#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 20000005
#define INF (1<<30)
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
P a[MAXN];
int tot=1;
int trie[MAXM][2];
int cnt[MAXM];
int num[MAXN];
vector<int> save[MAXN];
void clear(){
    for(int i=1;i<=tot;i++) trie[i][0]=trie[i][1]=cnt[i]=0;
    tot=1;
}
void insert(int v,int val){
    int rt=1; cnt[rt]+=val;
    for(int i=29;i>=0;i--){
        int x=(v>>i)&1;
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x]; cnt[rt]+=val;
    }
}
int get_min(int v){
    int ans=0,rt=1;
    for(int i=29;i>=0;i--){
        int x=(v>>i)&1;
        if(cnt[trie[rt][x]]){
            rt=trie[rt][x];
        }
        else {rt=trie[rt][x^1]; ans+=(1<<i);}
    }
    return ans;
}
int p[MAXN],r[MAXN];
void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i;
        r[i]=0;
    }
}
int find(int x){
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
vector<P> edges;
void add_edge(int u,int v){
    if(same(u,v)) return;
    edges.push_back(P(u,v)); unite(u,v);
}
void boruvka(){
    init(n);
    while(true){
        int t=0;
        for(int i=1;i<=n;i++) if(find(i)==i) num[i]=++t; else num[i]=0;
        if(t==1) break;
        for(int i=1;i<=n;i++) {
            if(!num[i]) num[i]=num[find(i)];
            save[num[i]].push_back(i);
        }
        vector<P> upd;
        for(int i=1;i<=t;i++){
            for(auto x:save[i]) insert(a[x].F,-1);
            P p=P(INF,INF);
            for(auto x:save[i]){
                int val=get_min(a[x].F);
                p=min(p,P(val,x));
            }
            p.F^=a[p.S].F;
            upd.push_back(p);
            for(auto x:save[i]) insert(a[x].F,1);
        }
        sort(upd.begin(),upd.end(),greater<P>());
        for(int i=1;i<=n;i++){
            while(upd.size()&&a[i].F==upd.back().F) {add_edge(i,upd.back().S); upd.pop_back();}
        }
        for(int i=1;i<=t;i++) save[i].clear();
    }
}
vector<int> G[MAXN];
int col[MAXN];
vector<int> part[2];
void dfs(int v,int p,int c){
    col[v]=c; part[c].push_back(v);
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v,1-c);
    }
}
int ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i].F); a[i].S=i;}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) insert(a[i].F,1);
    
    boruvka();
    for(auto p:edges) {G[p.F].push_back(p.S); G[p.S].push_back(p.F);}
    dfs(1,0,0);
    for(int i=1;i<=n;i++) ans[a[i].S]=col[i];
    for(int i=1;i<=n;i++) printf("%d",ans[i]);
    printf("\n");
    return 0;
}

