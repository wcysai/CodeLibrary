#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define MAXM 1305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int d[MAXN];
int E,u[MAXM],v[MAXM],w[MAXM],cost[MAXM];
ll val[MAXM];
int T,n,k;
vector<pair<P,int> > save;
vector<P> need;
struct GraphMatroid{
    vector<int> p;
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
    bool same(int x,int y){
        return find(x)==find(y);
    }
    bool clear(){
        p.clear(); p.resize(n+1);
        for(int i=1;i<=n;i++) p[i]=i;
        for(auto q:need) if(!unite(q.F,q.S)) return false;
        return true;
    }
    void add(int x){
        unite(u[x],v[x]);
    }
    bool test(int x){
        return !same(u[x],v[x]);
    }
};
struct PartitionMatroid{
    vector<int> cnt;
    bool clear(){
        cnt.clear(); cnt.resize(k+1);
        for(int i=1;i<=k;i++) cnt[i]=0;
        for(auto q:need) {cnt[q.F]++; cnt[q.S]++;}
        for(int i=1;i<=k;i++) if(cnt[i]>d[i]) return false;
        return true;
    }
    void add(int x){
        if(u[x]<=k) cnt[u[x]]++;
        if(v[x]<=k) cnt[v[x]]++;
    }
    void dec(int x){
        if(u[x]<=k) cnt[u[x]]--;
        if(v[x]<=k) cnt[v[x]]--;
    }
    bool test(int x){
        if(u[x]<=k&&cnt[u[x]]==d[u[x]]) return false;
        if(v[x]<=k&&cnt[v[x]]==d[v[x]]) return false;
        return true;
    }
};


template <typename MT1, typename MT2>
struct MatroidIntersection
{
    int n,S,T;
    MatroidIntersection(int _n):n(_n){}
    int pre[MAXM],d[MAXM];
    bool inque[MAXM],has[MAXM];
    vector<int> g[MAXM];
    queue<int> que;
    void clear_all()
    {
        for(int i=1;i<=n+2;i++){
            inque[i]=false;
            pre[i]=0;
            d[i]=INF;
            if(has[i]) cost[i]=-w[i]; else cost[i]=w[i];
            g[i].clear();
        }
        while(que.size()) que.pop();
    }
    void add_edge(int u,int v)
    {
        g[u].push_back(v);
    }
    vector<int> getcur()
    {
        vector<int> ret;
        for(int i=1;i<=n;i++) if(has[i]) ret.push_back(i);
        return ret;
    }
    void enqueue(int v,int p)
    {
        pre[v]=p;
        if(!inque[v])
        {
            inque[v]=true;
            que.push(v);
        }
    }
    pair<vector<int>,ll> run()
    {
        ll ans=0;
        memset(has,false,sizeof(has));
        MT1 allmt1;  MT2 allmt2;
        allmt1.clear(); allmt2.clear();
        /*for(int i=1;i<=n;i++){
            if(allmt1.test(i)&&allmt2.test(i)){
                allmt1.add(i); allmt2.add(i);
                ans+=w[i];
                has[i]=true;
            }
        }*/
        S=n+1; T=n+2;
        while(true)
        {
            clear_all();
            auto cur=getcur();
            allmt1.clear(); allmt2.clear();
            for(auto x:cur) {allmt1.add(x); allmt2.add(x);}
            vector<MT1> vmt1; vector<MT2> vmt2;
            vmt1.resize(cur.size()); vmt2.resize(cur.size());
            for(auto &x:vmt1) x.clear();
            for(auto &x:vmt2) x.clear();
            for(int i=0;i<(int)cur.size();i++)
                for(int j=0;j<(int)cur.size();j++){
                    if(i==j) continue;
                    vmt1[i].add(cur[j]);
                    vmt2[i].add(cur[j]);
                }
            for(int i=0;i<(int)cur.size();i++){
                for(int j=1;j<=n;j++){
                    if(has[j]) continue;
                    if(vmt1[i].test(j)) add_edge(cur[i],j);
                    if(vmt2[i].test(j)) add_edge(j,cur[i]);
                }
            }
            for(int i=1;i<=n;i++){
                if(!has[i]){
                    if(allmt1.test(i)) add_edge(S,i);
                    if(allmt2.test(i)) add_edge(i,T);
                }
            }
            d[S]=0; que.push(S); inque[S]=true;
            cost[S]=cost[T]=0;
            while(que.size()){
                int u=que.front(); que.pop();
                for(auto to:g[u])
                    if(d[to]>d[u]+cost[to])
                    {
                        d[to]=d[u]+cost[to];
                        enqueue(to,u);
                    }
                inque[u]=false;
            }
            if(d[T]==INF) return make_pair(getcur(),ans);
            ans+=d[T];
            //printf("d=%d\n",d[T]);
            int last=pre[T];
            while(last!=S)
            {
                has[last]^=1;
                last=pre[last];
            }
        }
    }
};
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++) scanf("%d",&d[i]);
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++){
            if(i<=k&&j<=k){
                int x; scanf("%d",&x);
                save.push_back(make_pair(P(i,j),x));
                continue;
            }
            E++;
            u[E]=i; v[E]=j;
            scanf("%d",&w[E]);
        }
    ll ans=INF;
    int sz=(int)save.size();
    for(int i=0;i<(int)(1<<sz);i++){
        need.clear();
        int sum=0,cnt=0;
        for(int j=0;j<sz;j++){
            if(i&(1<<j)){
                sum+=save[j].S;
                need.push_back(save[j].F);
                cnt++;
            }
        }
        GraphMatroid gm; if(!gm.clear()) continue;
        PartitionMatroid pm; if(!pm.clear()) continue;
        MatroidIntersection<GraphMatroid,PartitionMatroid> matint(E);
        auto res=matint.run();
        if((int)res.F.size()+cnt!=n-1) continue;
        else ans=min(ans,sum+res.S);
        //printf("i=%d sum=%d ans=%d\n",i,sum,ans);
    }
    printf("%lld\n",ans);
    return 0;
}

