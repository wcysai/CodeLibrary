#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 19
#define MAXM 8000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p[MAXN];
int pa[MAXLOGN+1][MAXN],depth[MAXN];
int l[MAXM],r[MAXM];
int ans[MAXN];
vector<int> G[MAXN];
vector<pair<P,P> > save[MAXLOGN];
int fa[MAXM],rk[MAXM];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void init_dsu(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        rk[i]=0;
    }
}
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {fa[x]=y; l[y]=max(l[y],l[x]); r[y]=min(r[y],r[x]);}
    else{
        fa[y]=x;
        l[x]=max(l[x],l[y]); r[x]=min(r[x],r[y]);
        if(rk[x]==rk[y]) rk[x]++;
    }
}
bool same(int u,int v){
    return find(u)==find(v);
}
void dfs(int v,int p,int d){
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V){
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++){
        for(int v=1;v<=n;v++){
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x){
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--){
        if(pa[k][u]!=pa[k][v]){
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
void add_chain(int u,int v,int len,int t,int rev){
    if(!len) return;
    //printf("chain %d %d %d %d\n",u,v,len,t);
    if(!rev){
        for(int k=MAXLOGN-1;k>=0;k--){
            if(len&(1<<k)){
                //printf("u=%d v=%d\n",u,v);
                save[k].push_back(make_pair(P(t,0),P(u,v)));
                u=pa[k][u]; v=pa[k][v];
            }
        }
    }
    else{
        for(int k=MAXLOGN-1;k>=0;k--){
            if(len&(1<<k)){
                //printf("u=%d v=%d\n",u,v);
                int z=get(v,len-(1<<k));
                save[k].push_back(make_pair(P(t,1),P(u,z)));
                u=pa[k][u]; 
                len-=(1<<k);
            }
        }
    }
}
void add_cons(int a,int b,int c,int d,int t){
    int u=lca(a,b),v=lca(c,d);
    int l1=depth[a]-depth[u]+1,l2=depth[c]-depth[v]+1;
    //printf("l1=%d l2=%d\n",l1,l2);
    if(l1<=l2) {swap(a,c); swap(b,d); swap(l1,l2); swap(u,v);}
    add_chain(a,c,l2,t,0);
    int l3=depth[d]-depth[v],l4=depth[b]-depth[u];
    add_chain(get(a,l2),get(d,l3-(l1-l2)),l1-l2,t,1);
    add_chain(b,d,l4,t,0);
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&p[i]);
        G[p[i]].push_back(i); G[i].push_back(p[i]);
    }
    init(n);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]); 
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add_cons(a,b,c,d,i);
    }
    init_dsu(38*n);
    for(int k=18;k>=0;k--){
        sort(save[k].begin(),save[k].end());
        if(k){
            for(auto p:save[k]){
                int t=p.F.F,type=p.F.S,u=p.S.F,v=p.S.S;
                //printf("k=%d u=%d v=%d type=%d t=%d\n",k,u,v,type,t);
                if(!type){
                    if(!same(k*2*n+u,k*2*n+v)){
                        assert(!same(k*2*n+n+u,k*2*n+n+v));
                        unite(k*2*n+u,k*2*n+v);
                        unite(k*2*n+n+u,k*2*n+n+v);
                        save[k-1].push_back(make_pair(P(t,type),P(u,v)));
                        save[k-1].push_back(make_pair(P(t,type),P(get(u,(1<<(k-1))),get(v,1<<(k-1)))));
                    }
                }
                else{
                    if(!same(k*2*n+u,k*2*n+n+v)){
                        assert(!same(k*2*n+n+u,k*2*n+v));
                        unite(k*2*n+u,k*2*n+n+v);
                        unite(k*2*n+n+u,k*2*n+v);
                        save[k-1].push_back(make_pair(P(t,type),P(get(u,1<<(k-1)),v)));
                        save[k-1].push_back(make_pair(P(t,type),P(u,get(v,1<<(k-1)))));
                    }
                }
            }
        }
    }
    memset(ans,-1,sizeof(ans));
    int res=1;
    for(int i=1;i<=n;i++) res=1LL*res*(r[i]-l[i]+1)%MOD;
    //printf("res=%d\n",res);
    ans[0]=res;
    sort(save[0].begin(),save[0].end());
    for(auto p:save[0]){
        //printf("k=%d F=%d S=%d t=%d\n",0,p.S.F,p.S.S,p.F.F);
        if(!same(p.S.F,p.S.S)){
            if(res){
                int x=find(p.S.F),y=find(p.S.S);
                res=1LL*res*pow_mod(r[x]-l[x]+1,MOD-2)%MOD;
                res=1LL*res*pow_mod(r[y]-l[y]+1,MOD-2)%MOD;
            }
            unite(p.S.F,p.S.S);
            int x=find(p.S.F);
            if(l[x]<=r[x]) res=1LL*res*(r[x]-l[x]+1)%MOD; else res=0;
            ans[p.F.F]=res;
            //printf("res=%d\n",res);
        }
    }
    for(int i=1;i<=m;i++) if(ans[i]==-1) ans[i]=ans[i-1];
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}

