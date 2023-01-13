#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
vector<int> G[MAXN];
int vs[MAXN*2-1],depth[MAXN*2-1],id[MAXN],f[2*MAXN-1];
void dfs(int v,int p,int d,int &k){
    id[v]=k; vs[k]=v; depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++){
        if(G[v][i]!=p){
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
//max f[i]-2depth[j]+f[k] i<=j<=k
struct segtree{
    int a[8*MAXN],b[8*MAXN],c[8*MAXN],ab[8*MAXN],bc[8*MAXN],abc[8*MAXN];
    void pushup(int k){
        a[k]=max(a[k*2],a[k*2+1]); b[k]=max(b[k*2],b[k*2+1]); c[k]=max(c[k*2],c[k*2+1]);
        ab[k]=max(a[k*2]+b[k*2+1],max(ab[k*2],ab[k*2+1]));
        bc[k]=max(b[k*2]+c[k*2+1],max(bc[k*2],bc[k*2+1]));
        abc[k]=max(max(a[k*2]+bc[k*2+1],ab[k*2]+c[k*2+1]),max(abc[k*2],abc[k*2+1]));
    }
    void build(int k,int l,int r){
        if(l==r){
            a[k]=c[k]=f[l]; b[k]=-2*depth[l];
            ab[k]=bc[k]=a[k]+b[k];
            abc[k]=ab[k]+c[k];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int v){
        if(l==r){
            a[k]+=v; c[k]+=v; ab[k]+=v; bc[k]+=v; abc[k]+=2*v;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    int tot=0;
    dfs(1,0,0,tot);
    for(int i=0;i<tot;i++) f[i]=depth[i];
    for(int i=1;i<=n;i++) f[id[i]]+=a[i];
    seg.build(1,0,tot-1);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int v,x;
        scanf("%d%d",&v,&x);
        int d=x-a[v];
        seg.update(1,0,tot-1,id[v],d);
        a[v]=x;
        printf("%d\n",(seg.abc[1]+1)/2);
    }
    return 0;
}

