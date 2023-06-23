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
int n,m,ans[MAXN],L[MAXN],R[MAXN];
vector<int> G[MAXN];
vector<int> order;
bool flag;
int color[MAXN];
void dfs(int v)
{
    color[v]=1;
    for(auto to:G[v]){
        if(!color[to]) dfs(to);
        else if(color[to]==1) flag=false;
    }
    color[v]=2;
    order.push_back(v);
}
vector<P> add[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) scanf("%d%d",&L[i],&R[i]);
    flag=true;
    order.clear();
    for(int i=1;i<=n;i++) if(!color[i]) dfs(i);
    reverse(order.begin(),order.end());
    for(auto x:order){
        for(auto to:G[x]){
            L[to]=max(L[to],L[x]+1);
        }
    }
    for(int i=(int)order.size()-1;i>=0;i--){
        int x=order[i];
        for(auto to:G[x]){
            R[x]=min(R[x],R[to]-1);
        }
    }
    set<P> s;
    for(int i=1;i<=n;i++) {
        if(L[i]>R[i]) {flag=false; break;}
        add[L[i]].push_back(P(R[i],i));
    }
    if(!flag) {puts("No"); return 0;}
    for(int i=1;i<=n;i++){
        for(auto p:add[i]) s.insert(p);
        if(!s.size()){
            flag=false; break;
        }
        P p=*s.begin(); s.erase(s.begin());
        if(i>R[p.S]||i<L[p.S]) {flag=false; break;}
        ans[p.S]=i;
    }
    if(!flag) {puts("No"); return 0;}
    puts("Yes");
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}
