#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long 
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> PP;
int T,n,k,a[MAXN];
vector<PP> G[MAXN];
multiset<P> s[MAXN];
ll sum[MAXN];
int off[MAXN];
void truncate(int v,ll cap){
    while(sum[v]>cap){
        auto it=(--s[v].end());
        if(sum[v]-cap>=(it->S)){
            sum[v]-=(it->S);
            s[v].erase(it); continue;
        }
        else{
            int val=(it->F);
            int left=(it->S)-(sum[v]-cap);
            s[v].erase(it); s[v].insert(P(val,left));
            sum[v]=cap;
            break;
        }
    }
}
void merge(int v,int to){
    if(s[v].size()<s[to].size()){
        swap(s[v],s[to]);
        swap(off[v],off[to]); swap(sum[v],sum[to]);
    }
    for(auto p:s[to]){
        sum[v]+=p.S;
        s[v].insert(P(p.F+off[to]-off[v],p.S));
    }
}
void dfs(int v){
    for(auto p:G[v]){
        int to=p.F.F,cap=p.F.S,cost=p.S;
        dfs(to); s[to].insert(P(-off[to],cap)); sum[to]+=cap; 
        truncate(to,cap); 
        off[to]+=cost;
        merge(v,to);
    }
    //printf("v=%d sum=%lld\n",v,sum[v]);
    //for(auto p:s[v]) printf("(%d %d)\n",p.F,p.S);
}
signed main()
{
    scanf("%lld",&T);
    for(int t=1;t<=T;t++){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) s[i].clear();
        for(int i=1;i<=n;i++) off[i]=sum[i]=0;
        for(int i=0;i<n-1;i++){
            int u,v,w,c;
            scanf("%lld%lld%lld%lld",&u,&v,&w,&c);
            G[u].push_back(make_pair(P(v,w),c));
        }
        dfs(1);
        ll num=0,ans=0;
        for(auto x:s[1]){
            num+=x.S;
            ans+=1LL*x.S*(x.F+off[1]);
        }
        printf("Case #%lld: %lld %lld\n",t,num,ans);
    }
    return 0;
}

