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
vector<pair<int&,int> > backup;
int p[MAXN],r[MAXN],val[MAXN];
vector<pair<P,int> > edges[4*MAXN];
vector<pair<P,int> > qry[MAXN];
int bas[30],ans[MAXN];
map<P,P> mp;
void modify(int &a,int b){
    backup.push_back({a,a});
    a=b;
}
void rollback(int t){
    while(backup.size()>t) {
        backup.back().F=backup.back().S;
        backup.pop_back();
    }
}
void add_basis(int x){
    //printf("add basis %d\n",x);
    for(int i=29;i>=0;i--){
        if(x&(1<<i)){
            if(!bas[i]){
                modify(bas[i],x);
                return;
            }
            else x^=bas[i];
        }
    }
}
int query(int x){
    //printf("query x=%d\n",x);
    for(int i=29;i>=0;i--){
        if(x&(1<<i)){
            if(bas[i]) x^=bas[i];
        }
    }
    return x;
}
void init(){
    for(int i=1;i<=n;i++){
        p[i]=i; r[i]=0; val[i]=0;
    }
}
P find(int x){
    if(p[x]==x) return P(x,0);
    P fa=find(p[x]);
    fa.S^=val[x];
    return fa;
}
void add_edge(int x,int y,int d){
    //printf("add edge %d %d %d\n",x,y,d);
    P px=find(x),py=find(y);
    if(px.F==py.F){
        add_basis(px.S^py.S^d);
    }
    int res=px.S^py.S^d;
    x=px.F,y=py.F;
    if(r[x]<r[y]){
       modify(p[x],y); modify(val[x],val[x]^res);
    }
    else{
       modify(p[y],x); modify(val[y],val[y]^res);
       if(r[x]==r[y]) modify(r[x],r[x]+1);
    }
}
void add_edge_all(int k,int l,int r,int x,int y,int u,int v,int d){
    //if(k==1) printf("x=%d y=%d u=%d v=%d d=%d\n",x,y,u,v,d);
    if(l>y||x>r) return;
    if(l>=x&&r<=y){
        edges[k].push_back(make_pair(P(u,v),d));
        return;
    }
    int mid=(l+r)/2;
    add_edge_all(k*2,l,mid,x,y,u,v,d);
    add_edge_all(k*2+1,mid+1,r,x,y,u,v,d);
}
void solve(int k,int l,int r){
    int t=(int)backup.size();
    for(auto p:edges[k]) add_edge(p.F.F,p.F.S,p.S);
    if(l==r){
        for(auto p:qry[l]) {
            int u=p.F.F,v=p.F.S;
            int d=find(u).S^find(v).S;
            ans[p.S]=query(d);
        }
        rollback(t);
        return;
    }
    int mid=(l+r)/2;
    solve(k*2,l,mid); solve(k*2+1,mid+1,r);
    rollback(t);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        mp[P(x,y)]=P(d,1);
    }
    scanf("%d",&q);
    int cnt=0;
    for(int i=2;i<=q+1;i++){
        int type,x,y,d;
        scanf("%d%d%d",&type,&x,&y);
        if(type==1){
            scanf("%d",&d);
            mp[P(x,y)]=P(d,i);
        }
        else if(type==2){
            P p=mp[P(x,y)];
            if(p.S) add_edge_all(1,1,q+1,p.S,i-1,x,y,p.F);
            mp[P(x,y)]=P(0,0);
        }
        else{
            qry[i].push_back(make_pair(P(x,y),++cnt));
        }
    }
    for(auto p:mp){
        if(p.S.S==0) continue;
        add_edge_all(1,1,q+1,p.S.S,q+1,p.F.F,p.F.S,p.S.F);
    }
    init();
    solve(1,1,q+1);
    for(int i=1;i<=cnt;i++) printf("%d\n",ans[i]);
    return 0;
}

