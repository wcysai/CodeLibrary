#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define y1 daskodsako
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN];
int x[MAXN],y[MAXN];
int st[MAXN];
int u[MAXN],v[MAXN];
int ans[MAXN];
bool cmp(int i,int j){
    if(x[i]!=x[j]) return x[i]<x[j];
    return y[i]<y[j];
}
bool cmp2(int i,int j){
    return 1LL*u[i]*(u[j]+v[j])<1LL*u[j]*(u[i]+v[i]);
}
ll calc(int id,int i){
    return 1LL*u[i]*x[id]+1LL*(u[i]+v[i])*y[id];
}
void add(int id){
    while(t>0){
        if(x[st[t-1]]==x[id]) {t--; continue;}
        if(t>1){
            int x1=x[st[t-1]],y1=y[st[t-1]],x2=x[st[t-2]],y2=y[st[t-2]],x3=x[id],y3=y[id];
            if(1LL*(x1-x2)*(y3-y1)>1LL*(x1-x3)*(y2-y1)) {t--; continue;}
            if(1LL*(x1-x2)*(y3-y1)==1LL*(x1-x3)*(y2-y1)&&st[t-1]>min(id,st[t-2])) {t--; continue;}
        }
        break;
    }
    st[t++]=id;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {scanf("%d%d",&x[i],&y[i]); x[i]-=y[i];}
    vector<int> vv;
    for(int i=1;i<=n;i++) vv.push_back(i);
    sort(vv.begin(),vv.end(),cmp);
    for(auto x:vv) add(x);
    vv.clear();
    for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
    //for(int i=0;i<t;i++) printf("%d ",st[i]);
    //printf("\n");
    for(int i=1;i<=m;i++) vv.push_back(i);
    sort(vv.begin(),vv.end(),cmp2);
    int now=0;
    for(auto i:vv){
        while(now+1<t){
            ll val1=calc(st[now],i),val2=calc(st[now+1],i);
            if(val1<val2||(val1==val2&&st[now]>st[now+1])) now++; else break;
        }
        ans[i]=st[now];
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}

