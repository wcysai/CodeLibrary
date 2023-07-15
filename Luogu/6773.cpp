#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 120000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int dep[MAXN],val[MAXN],root[MAXN];
int tot,ls[MAXM],rs[MAXM],sum[MAXM],mul[MAXM];
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void pushup(int k){
    sum[k]=sum[ls[k]]; add(sum[k],sum[rs[k]]);
}
void mult(int k,int v){
    if(!k) return;
    mul[k]=1LL*mul[k]*v%MOD;
    sum[k]=1LL*sum[k]*v%MOD;
}
void pushdown(int k){
    if(!k) return;
    if(mul[k]==1) return;
    mult(ls[k],mul[k]); mult(rs[k],mul[k]);
    mul[k]=1;
}
void update(int &k,int l,int r,int pos,int v){
    if(!k) {k=++tot; mul[k]=1; sum[k]=0;}
    if(l==r){
        sum[k]=v; return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) update(ls[k],l,mid,pos,v); else update(rs[k],mid+1,r,pos,v);
    pushup(k);
}
void dfs(int v,int p,int d){
    dep[v]=d;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v,d+1);
    }
}
int query(int k,int l,int r,int x,int y){
    if(l>y||x>r) return 0;
    if(!k) return 0;
    if(l>=x&&r<=y) return sum[k];
    int mid=(l+r)/2;
    pushdown(k);
    int a=query(ls[k],l,mid,x,y),b=query(rs[k],mid+1,r,x,y);
    add(a,b);
    return a;
}
//f(u,i)<--f(u,i)(g(v,dep[u])+g(v,i)))+g(u,i-1)f(v,i)
//s1 records g(v,dep[u])+sum_{0<=i<=l-1} f(v,i)
//s2 records sum_{0<=i<=l-1} f(u,i)
int merge(int &k1,int &k2,int l,int r,int &s1,int &s2){
    if(!k1&&!k2) return 0;
    if(!k1||!k2){
        if(!k1){
            add(s1,sum[k2]);
            mult(k2,s2);
            return k2;
        }
        else{
            add(s2,sum[k1]);
            mult(k1,s1);
            return k1;
        }
    }
    if(l==r){
        int tmp=sum[k1];
        sum[k1]=(1LL*sum[k1]*(s1+sum[k2])+1LL*s2*sum[k2])%MOD;
        add(s1,sum[k2]); add(s2,tmp);
        return k1;
    }
    pushdown(k1); pushdown(k2);
    int mid=(l+r)/2;
    ls[k1]=merge(ls[k1],ls[k2],l,mid,s1,s2);
    rs[k1]=merge(rs[k1],rs[k2],mid+1,r,s1,s2);
    pushup(k1);
    return k1;
}
void dfs2(int v,int p){
    update(root[v],0,n,val[v],1); 
    for(auto to:G[v]){
        if(to==p) continue;
        dfs2(to,v);
        int s1=query(root[to],0,n,0,dep[v]),s2=0;
        merge(root[v],root[to],0,n,s1,s2);
    }
    //printf("v=%d root=%d sum=%d\n",v,root[v],query(root[v],0,n,0,n));
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0,1);
    for(int i=1;i<=n;i++) val[i]=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int u,v; scanf("%d%d",&u,&v);
        val[v]=max(val[v],dep[u]);
    }
    dfs2(1,0);
    printf("%d\n",query(root[1],0,n,0,0));
    return 0;
}

