#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,a[MAXN];
int u[MAXN],v[MAXN];
int l[MAXN],r[MAXN],col[MAXN];
int pa[MAXN],rk[MAXN];
int last[MAXN];
int bip;
vector<pair<int&,int> > backup;
void modify(int &ref,int v){
    backup.push_back({ref,ref});
    ref=v;
}
void init(int n){
    for(int i=1;i<=n;i++){
        pa[i]=i; rk[i]=0; col[i]=0;
    }
    bip=1;
}
P find(int x){
    if(pa[x]==x) return P(x,col[x]);
    P q=find(pa[x]); if(col[x]) q.S^=1;
    return q;
}
void unite(int x,int y){
    if(!x||!y) return;
    P p=find(x); P q=find(y);
    if(p.F==q.F){
        if(p.S==q.S) modify(bip,0);
        return;
    }
    if(rk[p.F]<rk[q.F]){
        if(p.S==q.S) modify(col[p.F],col[p.F]^1);
        modify(pa[p.F],q.F); 
    }
    else{
        modify(pa[q.F],p.F);
        if(p.S==q.S) modify(col[q.F],col[q.F]^1);
        if(rk[p.F]==rk[q.F]) modify(rk[p.F],rk[p.F]+1);
    }
}
void rollback(int t){
    while(backup.size()>t) {
        backup.back().F=backup.back().S;
        backup.pop_back();
    }
}
void solve(int l1,int l2,int r1,int r2){//pos in [l1,l2] answer in [r1,r2]
    //printf("l1=%d l2=%d r1=%d r2=%d\n",l1,l2,r1,r2);
    if(l1>l2) return;
    if(!bip) {for(int i=l1;i<=l2;i++) last[i]=r2; return;}
    int mid=(l1+l2)/2;
    int t=(int)backup.size();
    for(int i=l1;i<=mid;i++){
        unite(u[i],v[i]);
    }
    if(!bip)
    {
        for(int i=mid;i<=l2;i++) last[i]=r2+1;
        rollback(t);
        solve(l1,mid-1,r1,r2);
        return;
    }
    int now=r2,res;
    while(now>mid&&bip){
        unite(u[now],v[now]);
        if(!bip) break; else now--; 
    }
    last[mid]=now;
    rollback(t);
    for(int i=now+1;i<=r2;i++) unite(u[i],v[i]);
    solve(l1,mid-1,r1,now);
    rollback(t);
    for(int i=l1;i<=mid;i++) unite(u[i],v[i]);
    solve(mid+1,l2,now,r2);
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    init(n);
    solve(0,m,1,m);
    for(int i=1;i<=q;i++){
        if(last[l[i]-1]>r[i]) puts("YES"); else puts("NO"); 
    }
    return 0;
}

