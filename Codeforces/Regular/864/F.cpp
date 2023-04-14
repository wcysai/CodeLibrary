#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p[MAXN],r[MAXN],sz[MAXN];
void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i; r[i]=0;
        sz[i]=1;
    }
}
int find(int x){
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; sz[y]+=sz[x];}
    else{
        p[y]=x; sz[x]+=sz[y];
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y){
    return find(x)==find(y);
}
int low[MAXN],high[MAXN],ext[MAXN];
vector<int> G[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    init(n);
    for(int i=n;i>=1;i--){
        for(auto to:G[i])
            if(to>=i) unite(i,to);
        low[i]=sz[find(i)]-1;
    }
    init(n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(auto to:G[i]) 
            if(to<=i) 
            {
                unite(i,to);
                ext[i]+=(ext[to]+1);
            }
        high[i]=sz[find(i)]-1;
    }
    for(int i=1;i<=n;i++) 
        ans+=low[i]+high[i]-2*ext[i];
    printf("%lld\n",ans);
    scanf("%d",&m);
    for(int i=n+1;i<=n+m;i++){
        int x; scanf("%d",&x);
        ext[i]+=(ext[x]+1);
        ans+=(i-1-ext[i]);
        printf("%lld\n",ans);
    }
    return 0;
}

