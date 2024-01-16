#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,k,a[MAXN],sz[MAXN];
int n,m,N,tot,t,bcc_cnt,mcnt;
int cnt[MAXN];
vector<int> G[MAXN],bcc[MAXN];
int st[MAXN],dfn[MAXN],low[MAXN],bccno[MAXN];
int U[MAXM],V[MAXM],fa[MAXN];
bool isbridge[MAXM];
vector<int> tree[MAXN];
//bridge tree:
//edge-biconnected components are connected by bridges
void add_edge(int u,int v){
    U[++mcnt]=u;V[mcnt]=v;
    G[u].push_back(mcnt);G[v].push_back(mcnt);
}
int adj(int u,int e){
    return U[e]==u?V[e]:U[e];
}
void _assert(bool x){
    if (!x) exit(0);
}
void dfs1(int v,int edge)
{
    dfn[v]=low[v]=++tot;
    st[t++]=v;
    for(auto e:G[v]){
        if(e==edge) continue;
        int to=adj(v,e);
        if(!dfn[to]){
            dfs1(to,e);
            low[v]=min(low[v],low[to]);
        }
        else low[v]=min(low[v],dfn[to]);
    }
    if(low[v]==dfn[v]&&edge!=-1) isbridge[edge]=true;
}
void dfs2(int v){
    dfn[v]=1;
    bccno[v]=bcc_cnt;
    bcc[bcc_cnt].push_back(v);
    for(auto e:G[v]){
        int to=adj(v,e);
        if(isbridge[e]) continue;
        if(!dfn[to]) dfs2(to);
    }
}
int tarjan(){
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs1(i,-1);
    for(int i=1;i<=n;i++) dfn[i]=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            bcc_cnt++;
            dfs2(i);
        }
    }
    return bcc_cnt;
}
int build_bridge_tree(){
    tarjan();
    for(int i=1;i<=mcnt;i++){
        if(isbridge[i]){
            int u=bccno[U[i]],v=bccno[V[i]];
            tree[u].push_back(v);tree[v].push_back(u);
        }
    }
    return bcc_cnt;
}
int pre_dp[MAXN],suf_dp[MAXN],sum[MAXN],pre[MAXN],suf[MAXN],pre_son[MAXN],suf_son[MAXN];
int tt,bg[MAXN],ed[MAXN];
void dfs_dp(int v,int p){
    bg[v]=++tt; fa[v]=p;
    sz[v]=(int)bcc[v].size();
    for(auto to:tree[v]){
        if(to==p) continue;
        dfs_dp(to,v);
        sz[v]+=sz[to];
    }
    pre_dp[v]=suf_dp[v]=-1;
    if(sz[v]<=sum[suf[1]]) pre_dp[v]=suf[1];
    if(sz[v]<=sum[n]-sum[pre[n]-1]) suf_dp[v]=pre[n];
    for(auto to:tree[v]){
        if(to==p) continue;
        if(pre_dp[to]!=-1) {
            int rem=sum[pre_dp[to]]-sz[to];
            if(rem==0){
                int val=suf[pre_dp[to]+1];
                int now=sz[v]-sz[to];
                if(now<=cnt[val]) {pre_dp[v]=val; pre_son[v]=to;}
            }
            else{
                int now=sz[v]-sz[to];
                if(now<=rem) {pre_dp[v]=pre_dp[to]; pre_son[v]=to;}
            }
        }
        if(suf_dp[to]!=-1) {
            int rem=sum[n]-sum[suf_dp[to]-1]-sz[to];
            if(rem==0){
                _assert(suf_dp[to]!=0);
                int val=pre[suf_dp[to]-1];
                int now=sz[v]-sz[to];
                if(now<=cnt[val]) {suf_dp[v]=val; suf_son[v]=to;}
            }
            else{
                int now=sz[v]-sz[to];
                if(now<=rem) {suf_dp[v]=suf_dp[to]; suf_son[v]=to;}
            }
        }
    }
    /*printf("v=%d p=%d sz=%d\n",v,p,sz[v]);
    printf("predp=%d sufdp=%d\n",pre_dp[v],suf_dp[v]);
    printf("preson=%d sufson=%d\n",pre_son[v],suf_son[v]);*/
    ed[v]=tt;
}
bool done[MAXN];
vector<int> pre_pos[MAXN],suf_pos[MAXN];
int ans[MAXN];
bool is_ancestor(int u,int v){
    return bg[u]<=bg[v]&&ed[u]>=ed[v];
}
void fill_rest(int v,int val){
    //printf("v=%d p=%d val=%d\n",v,p,val);
    if(done[v]) return;
    done[v]=true;
    for(auto x:bcc[v]) ans[x]=val;
    for(auto to:tree[v]){
        if(to==fa[v]) continue;
        fill_rest(to,val);
    }
}
void construct_pre(int v){
    //if(pre_dp[v]==-1) exit(0);
    if(pre_dp[v]==suf[1]){
        fill_rest(v,pre_dp[v]);
        return;
    }
    if(done[v]) return;
    done[v]=true;
    for(auto x:bcc[v]) ans[x]=pre_dp[v];
    for(auto to:tree[v]){
        if(to==fa[v]) continue;
        if(to==pre_son[v]) construct_pre(to);
        else fill_rest(to,pre_dp[v]);
    }
}
void construct_suf(int v){
    //printf("suf %d %d\n",v,p);
    //if(suf_dp[v]==-1) exit(0);
    if(suf_dp[v]==pre[n]){
        fill_rest(v,suf_dp[v]);
        return;
    }
    if(done[v]) return;
    done[v]=true;
    for(auto x:bcc[v]) ans[x]=suf_dp[v];
    for(auto to:tree[v]){
        if(to==fa[v]) continue;
        if(to==suf_son[v]) construct_suf(to);
        else fill_rest(to,suf_dp[v]);
    }
}
void clear(){
    mcnt=bcc_cnt=tot=t=tt=0; 
    for(int i=1;i<=n;i++){
        tree[i].clear(); G[i].clear(); dfn[i]=0;
        bcc[i].clear(); cnt[i]=0; 
    }
    for(int i=1;i<=m;i++) isbridge[i]=0;
    for(int i=1;i<=n;i++) {pre_pos[i].clear(); suf_pos[i].clear();}
}
int upre[MAXN];
int ffind(int x){
    if (upre[x]==x) return x;
    return upre[x]=ffind(upre[x]);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        _assert(n>=2&&n<=100000);
        _assert(m>=n-1&&m<=200000);
        for (int i=1;i<=n;i++) upre[i]=i;
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            _assert(u!=v);
            _assert(u>=1&&u<=n&&v>=1&&v<=n);
            add_edge(u,v);
            upre[ffind(v)]=ffind(u);
        }
        for (int i=1;i<=n;i++) _assert(ffind(1)==ffind(i));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            _assert(a[i]>=1&&a[i]<=n);
            //printf("%d ",a[i]);
            cnt[a[i]]++;
        }
        //printf("\n");
        if(cnt[a[1]]==n){
            printf("Yes\n");
            for(int i=1;i<=n;i++) printf("%d%c",a[1],i==n?'\n':' ');
            clear();
            continue;
        }
        suf[n+1]=n+1; pre[0]=0;
        for(int i=n;i>=1;i--){
            if(cnt[i]) suf[i]=i;
            else suf[i]=suf[i+1];
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]) pre[i]=i;
            else pre[i]=pre[i-1];
        }
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+cnt[i];
        N=build_bridge_tree();
        dfs_dp(1,0);
        for(int i=1;i<=N;i++){
            if(pre_dp[i]!=-1){
                int val=pre_dp[i];
                if(sz[i]==sum[val]) pre_pos[val].push_back(i);
            }
            if(suf_dp[i]!=-1){
                int val=suf_dp[i];
                _assert(val!=0);
                if(sz[i]==sum[n]-sum[val-1]) suf_pos[val].push_back(i);
            }
        }
        for(int i=1;i<=N;i++) done[i]=false;
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(flag) break;
            if(cnt[i]){
                int x=pre[i-1],y=suf[i+1];
                if(x==0&&suf_pos[y].size()){
                    construct_suf(suf_pos[y][0]);
                    fill_rest(1,i);
                    flag=true; break;
                }
                else if(y==n+1&&pre_pos[x].size()){
                    construct_pre(pre_pos[x][0]);
                    fill_rest(1,i);
                    flag=true; break;
                }
                else if(x!=0&&y!=n+1){
                    for(auto xx:pre_pos[x]){
                        if(flag) break;
                        for(auto yy:suf_pos[y]){
                            if(flag) break;
                            if(is_ancestor(xx,yy)||is_ancestor(yy,xx)) continue;
                            construct_pre(xx);
                            construct_suf(yy);
                            fill_rest(1,i);
                            flag=true; break;
                        }
                    }
                }
            }
        }
        if(!flag) puts("No");
        else{
            puts("Yes");
            for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
        }
        clear();
    }
    return 0;
}
