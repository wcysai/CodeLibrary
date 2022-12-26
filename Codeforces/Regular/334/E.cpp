#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 300005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p[MAXN],par[MAXN],r[MAXN];
int a[MAXM],b[MAXM],L[MAXM],ans[MAXM];
int num;
vector<pair<int&,int> > backup;
bool cmp(int x,int y){
    return L[x]<L[y]; 
}
void modify(int &ref,int v){
    backup.push_back({ref,ref});
    ref=v;
}
void rollback(int t){
    while((int)backup.size()>t){
        backup.back().F=backup.back().S;
        backup.pop_back();
    }
}
void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i; r[i]=0; par[i]=1;
    }
    num=n;
}
int find(int x){
    while(p[x]!=x) x=p[x];
    return x;
}
bool unite(int x,int y){
    x=find(x); y=find(y);
    if(!num||x==y) return false;
    if(par[x]&&par[y]) modify(num,num-2);
    if(r[x]<r[y]){
        modify(p[x],y); if(par[x]) modify(par[y],par[y]^1);
    }
    else{
        modify(p[y],x); if(r[x]==r[y]) modify(r[x],r[x]+1);
        if(par[y]) modify(par[x],par[x]^1);
    }
    return true;
}
void solve(int l,int r,int cl,int cr,vector<int> &id){
    if(l>r||cl>cr) return;
    if(num==0||(cl==cr)) {for(int i=l;i<=r;i++) ans[i]=cl; return;}
    if(!id.size()) return;
    int t=(int)backup.size();
    int mid=(l+r)/2;
    vector<int> lhs,rhs;
    int last=0;
    for(auto x:id){
        if(num==0){
            break;
        }
        if(x<=mid) {unite(a[x],b[x]); last=x;}
    }
    int cm=(num==0?max(cl,L[last]):INF);
   // printf("l=%d r=%d cl=%d cr=%d num=%d mid=%d cm=%d\n",l,r,cl,cr,num,mid,cm);
   // assert(cm>=cl&&cm<=cr);
   // assert(last);
    ans[mid]=cm;
    rollback(t);
    if(l==r) return;
    for(auto x:id) {
        if(x>=mid) continue;
        if(x<l&&L[x]<=cm) unite(a[x],b[x]);
        else lhs.push_back(x);
    }
    solve(l,mid-1,cm,cr,lhs);
    rollback(t);
    for(auto x:id) {
        if(L[x]>cm) continue;
        if(x<=mid&&L[x]<=cl) unite(a[x],b[x]);
        else rhs.push_back(x);
    }
    solve(mid+1,r,cl,cm,rhs);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i],&b[i],&L[i]);
    if(n&1) {for(int i=1;i<=m;i++) puts("-1"); return 0;}
    init(n);
    vector<int> tmp; for(int i=1;i<=m;i++) tmp.push_back(i);
    for(int i=1;i<=m;i++) ans[i]=INF;
    sort(tmp.begin(),tmp.end(),cmp);
    solve(1,m,L[tmp[0]],INF,tmp);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]==INF?-1:ans[i]);
    return 0;
}

