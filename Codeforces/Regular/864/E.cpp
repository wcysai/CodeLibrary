#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int prime[MAXM],phi[MAXM],dep[MAXM];
bool is_prime[MAXM];
vector<int> G[MAXM];
int sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    phi[1]=1; 
    for(int i=2;i<=n;i++){
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1;}
        for(int j=0;j<p;j++){
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            phi[prime[j]*i]=(i%prime[j]==0?phi[i]*prime[j]:phi[i]*phi[prime[j]]);
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int get(int u,int v){
    if(u==0||v==0) return u+v;
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v]) u=phi[u];
    while(u!=v) {u=phi[u]; v=phi[v];}
    return u;
}
struct segtree{
    int val[4*MAXN],sum[4*MAXN];
    void pushup(int k){
        val[k]=get(val[k*2],val[k*2+1]);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void upd(int k){
        if(min(dep[val[k*2]],dep[val[k*2+1]])<dep[val[k]]) val[k]=phi[val[k]];
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(int k,int l,int r){
        if(l==r){
            val[k]=a[l]; sum[k]=dep[a[l]];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y){
        if(l>y||x>r) return;
        if(sum[k]==0) return;
        if(l==r){
            val[k]=phi[val[k]];
            sum[k]--;
            return;
        }
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y); update(k*2+1,mid+1,r,x,y);
        upd(k);
    }
    int query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return val[k];
        int mid=(l+r)/2;
        return get(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
    int query_sum(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        return query_sum(k*2,l,mid,x,y)+query_sum(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    sieve(5000000);
    dep[1]=0;
    for(int i=2;i<=5000000;i++) dep[i]=dep[phi[i]]+1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,1,n);
    for(int i=0;i<m;i++){
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1) seg.update(1,1,n,l,r);
        else {
            int z=seg.query(1,1,n,l,r);
            int s=seg.query_sum(1,1,n,l,r);
            printf("%d\n",s-dep[z]*(r-l+1));
        }
    }
    return 0;
}

