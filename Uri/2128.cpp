#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int u[MAXM],v[MAXM],color[MAXM];
int n,m,k;
struct ColorfulMatroid{
    vector<int> cnt;
    void clear(){
        cnt.clear(); cnt.resize(k+1);
        for(int i=1;i<=k;i++) cnt[i]=0;
    }
    void add(int x){
        cnt[x]++;
    }
    void dec(int x){
        cnt[x]--;
    }
    bool test(int x){
        return (cnt[x]<=0);
    }
};

struct GraphMatroid{
    vector<int> p;
    int find(int x){
        if(p[x]==x) return x;
        else return p[x]=find(p[x]);
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        p[x]=y;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    void clear(){
        p.clear(); p.resize(n+1);
        for(int i=1;i<=n;i++) p[i]=i;
    }
    void add(int u,int v){
        unite(u,v);
    }
    bool test(int u,int v){
        return !same(u,v);
    }
};


template <typename MT1, typename MT2>
struct MatroidIntersection{
    int n;
    MatroidIntersection(int _n):n(_n){}
    int pre[MAXM],id[MAXM];
    vector<int> cur;
    bool vis[MAXM],has[MAXM];
    bool init1[MAXN];
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
    void enqueue(int v,int p){
        vis[v]=true; pre[v]=p;
        que.push(v);
    }
    bool check(int x,int y){
        return vmt1[id[x]].test(u[y],v[y]);
    }
    void init(int x){
        if(init1[id[x]]) return;
        vmt1[id[x]].clear();
        for(int j=0;j<(int)cur.size();j++){
            if(id[x]==j) continue;
            vmt1[id[x]].add(u[cur[j]],v[cur[j]]);
        }
        init1[id[x]]=true;
    }
    vector<int> run(){
        for(int i=1;i<=n;i++) has[i]=false;
        MT1 allmt1; MT2 allmt2; 
        allmt1.clear(); allmt2.clear();
        for(int i=1;i<=n;i++){
            if(allmt2.test(color[i])&&allmt1.test(u[i],v[i])) {
                //printf("add %d\n",i);
                allmt1.add(u[i],v[i]);
                allmt2.add(color[i]);
                has[i]=true;
            }
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
            for(auto x:cur) allmt1.add(u[x],v[x]);
            for(int i=1;i<=n;i++){
                vis[i]=false;
                if(has[i]) continue;
                if(allmt1.test(u[i],v[i])) {que.push(i); vis[i]=true; pre[i]=0; } 
            }
            int last=-1;
            while(que.size()){
                int x=que.front(); que.pop();
                if(!has[x]&&allmt2.test(color[x])) {last=x; break;}
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
                        if(color[i]==color[x]||allmt2.test(color[i])) enqueue(i,x);
                    }
                }
            }
            if(last==-1) return move(cur);
            //++cnt;
            //printf("cnt=%d\n",cnt);
            while(last){
                if(has[last]) allmt2.add(color[last]); else allmt2.dec(color[last]);
                has[last]^=1;
                last=pre[last];
            }
        }
    }
};
int tot=0;
int main(){
    //freopen("in.txt","r",stdin);
    double st = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){
        cin>>m>>k;
        ++tot;
        set<int> cc;
        for(int i=1;i<=m;i++){cin>>u[i]>>v[i]>>color[i];  if(u[i]==v[i]) {i--; m--;} else cc.insert(color[i]);}
        cout<<"Instancia "<<tot<<endl;;
        if(m<n-1||cc.size()<n-1) cout<<"nao\n"<<endl;
        else{
            MatroidIntersection<GraphMatroid,ColorfulMatroid> matint(m);
            vector<int> res=matint.run();
            if(res.size()==n-1) cout<<"sim\n"<<endl; else cout<<"nao\n"<<endl;
        }
        //if(tot>=4) {cout<<n<<" "<<m<<" "<<k<<endl; cout<<"time="<<(clock()-st)/CLOCKS_PER_SEC<<endl; break;}
    }
    return 0;
}

