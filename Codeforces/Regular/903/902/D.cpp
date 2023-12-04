#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int p2[MAXN];
vector<int> v[MAXN];
int id[MAXN];
vector<P> G[MAXN];
vector<pair<P,int> > cons;
int color[MAXN];
int p[MAXN],r[MAXN];
void add_edge(int u,int v,int c){
    G[v].push_back(P(u,c));
    G[u].push_back(P(v,c));
}
void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i;
        c[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else {
        int fa=find(p[x]);
        p[x]=fa; c[x]^=c[p[x]]; 
        return p[x];
    }
}
void unite(int x,int y,int c)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
}
int state[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    p2[0]=1;
    for(int i=1;i<=200000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        id[i]=(int)v[a[i]].size();
        v[a[i]].push_back(i);
    }
    bool f=true;
    int cnt=0;
    for(int i=1;i<=200000;i++) {
        if(v[i].size()&1) f=false;
        if(v[i].size()) cnt++;
    }
    if(!f) {printf("%d\n",p2[cnt-1]); return 0;}
    set<int> open;
    for(int i=1;i<=n;i++){
        state[a[i]]^=1;
        if(state[a[i]]){
            if(open.size()>=2){
                f=false;
                break;
            }
            for(auto x:open){

            }
        }
    }
    init(200000);
    for(auto p:cons){
        if(find(p.F.F)!=find(p.F.S)){
            unite(p.F.F,p.F.S);
            add_edge(p.F.F,p.F.S,p.S);
        }
    }
    memset(color,-1,sizeof(color));
    int comp=0;
    for(int i=1;i<=200000;i++){
        if(!v[i].size()) continue;
        if(color[i]==-1) {
            dfs(i,1); comp++;
        }
    }
    for(auto p:cons){
        if((color[p.F.F]^color[p.F.S])!=p.S) f=false;
    }
    int ans=p2[cnt-1]; dec(ans,p2[comp-1]);
    printf("%d\n",ans);
    return 0;
}

