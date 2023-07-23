#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 25
#define MAXM 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,u[MAXM],v[MAXM];
int deg[MAXM];
int col[MAXM];
int T,n,m,E,k;
char mp[MAXN][MAXN];
int num[MAXN][MAXN];
void add_edge(int x,int y){
    E++;
    if(col[x]) {deg[x]++; u[E]=x; v[E]=y;} else {deg[y]++; u[E]=y; v[E]=x;}
}
struct PartitionMatroid{
    vector<int> cnt;
    void clear(){
        cnt.clear(); cnt.resize(tot+1);
        for(int i=1;i<=tot;i++) cnt[i]=0;
    }
    void add(int x){
        cnt[u[x]]++;
    }
    void dec(int x){
        cnt[u[x]]--;
    }
    bool test(int x){
        return (u[x]==1||cnt[u[x]]+1<deg[u[x]]-1);
    }
};

struct GraphMatroid{
    vector<int> p;
    bool has[MAXM];
    int find(int x){
        if(p[x]==x) return x;
        else return p[x]=find(p[x]);
    }
    bool unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return false;
        p[x]=y;
        return true;
    }
    void init(){
        p.clear(); p.resize(tot+1);
        for(int i=1;i<=tot;i++) p[i]=i;
    }
    void clear(){
        init();
        for(int i=1;i<=E;i++) has[i]=false;
    }
    void add(int id){
        has[id]=true;
    }
    void dec(int id){
        has[id]=false;
    }
    bool test(){
        init();
        int cnt=0;
        for(int i=1;i<=E;i++){
            if(!has[i]){
                if(unite(u[i],v[i])) cnt++;
            }
        }
        return cnt==tot-1;
    }
};


template <typename MT1, typename MT2>
struct MatroidIntersection{
    int n;
    MatroidIntersection(int _n):n(_n){}
    int pre[MAXM],id[MAXM];
    vector<int> cur;
    bool vis[MAXM],has[MAXM];
    bool init1[MAXM];
    queue<int> que;
    vector<MT1> vmt1;
    void clear_all(){
        while(que.size()) que.pop();
    }
    vector<int> getcur(){
        vector<int> ret;
        for(int i=1;i<=n;i++) if(has[i]) ret.push_back(i);
        return move(ret);
    }
    void init(int x){
        if(init1[id[x]]) return;
        vmt1[id[x]].clear();
        for(int j=0;j<(int)cur.size();j++){
            if(id[x]==j) continue;
            vmt1[id[x]].add(cur[j]);
        }
        init1[id[x]]=true;
    }
    void enqueue(int v,int p){
        vis[v]=true; pre[v]=p;
        que.push(v);
    }
    bool check(int x,int y){
        vmt1[id[x]].add(y);
        bool f=vmt1[id[x]].test();
        vmt1[id[x]].dec(y);
        return f;
    }
    vector<int> run(){
        for(int i=1;i<=n;i++) has[i]=false;
        MT1 allmt1; MT2 allmt2; 
        allmt1.clear(); allmt2.clear();
        for(int i=1;i<=n;i++){
            allmt1.add(i);
            if(allmt2.test(i)&&allmt1.test()) {
                allmt2.add(i);
                has[i]=true;
            }
            else allmt1.dec(i); 
        }
        int cnt=0;
        while(true){
            cur=getcur();
            int cnt=0;
            vmt1.clear(); vmt1.resize(cur.size()); 
            for(int i=0;i<(int)cur.size();i++) init1[i]=false;
            for(int i=1;i<=n;i++) pre[i]=0;
            for(int i=1;i<=n;i++) if(has[i]) id[i]=cnt++;
            clear_all();
            allmt1.clear(); 
            for(auto x:cur) allmt1.add(x);
            for(int i=1;i<=n;i++){
                vis[i]=false;
                if(has[i]) continue;
                allmt1.add(i);
                if(allmt1.test()) {que.push(i); vis[i]=true; } 
                allmt1.dec(i);
            }
            int last=-1;
            while(que.size()){
                int x=que.front(); que.pop();
                if(!has[x]&&allmt2.test(x)) {last=x; break;}
                if(has[x]){
                    for(int i=1;i<=n;i++)
                    {
                        if(vis[i]||has[i]) continue;
                        if(!init1[id[x]]) init(x);
                        if(check(x,i)) enqueue(i,x);
                    }
                }
                else{
                    for(auto i:cur){
                        if(vis[i]) continue;
                        if(u[i]==u[x]||allmt2.test(x)) enqueue(i,x);
                    }
                }
            }
            if(last==-1) return move(cur);
            //++cnt;
            //printf("cnt=%d\n",cnt);
            while(last){
                if(has[last]) allmt2.dec(last); else allmt2.add(last);
                has[last]^=1;
                last=pre[last];
            }
        }
    }
};
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
        tot=E=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='O'){
                    num[i][j]=++tot; deg[tot]=0; 
                    col[tot]=((i+j)&1?0:1);//1:black 0: white
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) if(j<m&&mp[i][j]=='O'&&mp[i][j+1]=='O') add_edge(num[i][j],num[i][j+1]);
            for(int j=1;j<=m;j++) if(i<n&&mp[i][j]=='O'&&mp[i+1][j]=='O') add_edge(num[i][j],num[i+1][j]);
        }
        bool f=true;
        for(int i=2;i<=tot;i++) if(col[i]&&deg[i]<=1) {puts("NO"); f=false; break;}
        if(!f) continue;
        MatroidIntersection<GraphMatroid,PartitionMatroid> matint(E);
        auto ret=matint.run();
        if(E-ret.size()==tot-1) {
            vector<bool> has(E+1,true);
            for(auto x:ret) has[x]=false;
            puts("YES");   
            int e=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    printf("%c",mp[i][j]);
                    if(j==m) printf("\n");
                    else if(mp[i][j]=='O'&&mp[i][j+1]=='O'){
                        e++;
                        if(has[e]) printf("O"); else printf(" ");
                    }
                    else printf(" ");
                }
                if(i==n) break;
                for(int j=1;j<=m;j++){
                    if(mp[i][j]=='O'&&mp[i+1][j]=='O'){
                        e++;
                        if(has[e]) printf("O"); else printf(" ");
                    }
                    else printf(" ");
                    if(j==m) printf("\n"); else printf(" ");
                }
            }
        }
        else printf("NO\n");
    }
        //if(tot>=4) {cout<<n<<" "<<m<<" "<<k<<endl; cout<<"time="<<(clock()-st)/CLOCKS_PER_SEC<<endl; break;}
    return 0;
}
