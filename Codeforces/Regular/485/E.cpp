#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 10000005
#define MAXK 700000
#define MAXLOGN 19
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot,a[MAXN];
vector<int> G[MAXN];
int st[MAXN],ed[MAXN];
int vv[MAXN];
int u[MAXN],v[MAXN],x[MAXN];
int prime[MAXM],fact[MAXM],sid[MAXM];
bool is_prime[MAXM];
int ans[MAXN];
vector<int> upd[MAXK],qry[MAXK];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int spt[MAXLOGN+1][4*MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
int bit[MAXN+1];
vector<int> save[MAXM];
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v; st[v]=++tot;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
    ed[v]=tot;
}
int getMin(int x, int y)
{
    return depth[x]<depth[y]?x:y;
}

void rmq_init(int n)
{
    for(int i=1;i<=n;++i) spt[0][i]=i;
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            spt[i][j]=getMin(spt[i-1][j],spt[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(1,0,0,k);
    rmq_init(V*2-1);
}
int query(int l, int r)
{
    int k=31-__builtin_clz(r-l+1);
    return getMin(spt[k][l],spt[k][r-(1<<k)+1]);
}
int lca(int u,int v)
{
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
void update(int v,int val){
    add(st[v],val); if(ed[v]!=n) add(ed[v]+1,-val); vv[v]+=val;
}
int qsum(int v){
    return sum(st[v]);
}
int tquery(int u,int v){
    int l=lca(u,v);
    int res=qsum(u)+qsum(v)-2*qsum(l);
    if(vv[l]) res++;
    return res;
}
int sieve(int n){
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]) {prime[p++]=i; fact[i]=i;}
        for(int j=0;j<p;j++){
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            fact[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<P> factorize(int v)
{
    vector<P> tmp;
    int last=1,cnt=0;
    while(v>1){
        int p=fact[v];
        if(p==last) cnt++;
        else {if(last!=1) tmp.push_back(P(last,cnt)); last=p; cnt=1;}
        v/=p;
    }
    if(last!=1) tmp.push_back(P(last,cnt));
    return tmp;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    init(n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {ans[i]=1; scanf("%d%d%d",&u[i],&v[i],&x[i]);}
    sieve(10000000);
    int cnt=0;
    for(int i=2;i<=10000000;i++)
    {
        if(!is_prime[i]) continue;
        ll y=i;
        while(y<=10000000){
            cnt++;
            sid[y]=cnt;
            y=y*i;
        }
    }
    for(int i=1;i<=n;i++){
        auto v=factorize(a[i]);
        for(auto p:v){
            int y=1;
            for(int j=0;j<p.S;j++){
                y*=p.F;
                upd[sid[y]].push_back(i);
            }
        }
    }
    for(int i=1;i<=q;i++){
        auto v=factorize(x[i]);
        for(auto p:v){
            int y=1;
            for(int j=0;j<p.S;j++){
                y*=p.F;
                qry[sid[y]].push_back(i);
            }
        }
    }
    for(int i=2;i<=10000000;i++){
        if(!is_prime[i]) continue;
        ll y=i;
        while(y<=10000000){
            int r=sid[y];
            //if(!upd[y].size()||!qry[y].size()) break;
            for(auto z:upd[r]) update(z,1); 
            for(auto z:qry[r]) 
            {
                ans[z]=1LL*ans[z]*pow_mod(i,tquery(u[z],v[z]))%MOD;
            }
            for(auto z:upd[r]) update(z,-1);
            y*=i;
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}

