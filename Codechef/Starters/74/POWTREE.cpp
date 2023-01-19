#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 100005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,A[MAXN];
ll X,s;
vector<int> G[MAXN];
int val[MAXN];
ll ans;
vector<int> st;
vector<ll> cost;
struct segtree{
    ll sum[4*MAXN],ans[4*MAXN];
    int lazy[4*MAXN];
    void build(int k,int l,int r){
        lazy[k]=sum[k]=ans[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void add(int k,int v){
        lazy[k]+=v; ans[k]+=v*sum[k];
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void pushup(int k){
        sum[k]=sum[k*2]+sum[k*2+1]; ans[k]=ans[k*2]+ans[k*2+1];
    }
    void update(int k,int l,int r,int pos,int v){
        if(l==r) {sum[k]+=v;  ans[k]+=1LL*lazy[k]*v; return;}
        int mid=(l+r)/2;
        pushdown(k);
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    void update2(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        int mid=(l+r)/2;
        pushdown(k);
        update2(k*2,l,mid,x,y,v); update2(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    pair<int,ll> find_last(int k,int l,int r,ll need)
    {
        if(ans[k]<need) return make_pair(l,need-ans[k]);
        if(l==r) return make_pair(l+1,need);
        int mid=(l+r)/2;
        pushdown(k);
        if(ans[k*2+1]<need) return find_last(k*2,l,mid,need-ans[k*2+1]);
        return find_last(k*2+1,mid+1,r,need);
    }
}seg;
void dfs(int v,int p){
    val[v]=A[v];
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v); val[v]=max(val[v],val[to]);
    }
}
void check(int val){
    int sz=(int)st.size();
    auto p=seg.find_last(1,1,N+1,X);
    //printf("all=%lld s=%lld\n",seg.ans[1],seg.sum[1]);
    //printf("F=%d S=%lld\n",p.F,p.S);
    ll need=st[p.F-1]-val;
    need+=(p.S+sz-p.F)/(sz-p.F+1);
    ans=min(ans,need);
}
void dfs2(int v,int p){
    if(!st.size()) cost.push_back(0); else {
        int sz=(int)st.size();
        ll c=(st.back()-val[v]);
        cost.push_back(c);
        seg.update(1,1,N+1,sz,c);
        seg.update2(1,1,N+1,1,sz,1);
    }
    st.push_back(val[v]); 
    /*printf("v=%d\n",v);
    for(auto x:st) printf("%d ",x);
    puts("");
    for(auto x:cost) printf("%lld ",x);
    puts("");*/
    check(A[v]);
    for(auto to:G[v]){
        if(to==p) continue;
        dfs2(to,v);
    }
    int sz=(int)st.size();
    if(sz>=2){
        ll c=cost.back();
        seg.update(1,1,N+1,sz-1,-c);
        seg.update2(1,1,N+1,1,sz-1,-1);
    }
    st.pop_back(); cost.pop_back();
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&N,&X);
        for(int i=1;i<=N;i++) scanf("%d",&A[i]);
        for(int i=1;i<=N;i++) G[i].clear();
        for(int i=0;i<N-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(1,0);
        s=0;
        for(int i=1;i<=N;i++) s+=val[i];
        if(s>=X){
            printf("0\n"); continue;
        }
        seg.build(1,1,N+1);
        X-=s;
        ans=X;
        dfs2(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}

