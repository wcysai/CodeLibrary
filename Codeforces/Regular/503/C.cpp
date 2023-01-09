#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> G[MAXN],rG[MAXN],ans;
int removed[MAXN];
bool chosen[MAXN];
void solve(int now){
    if(now==n+1) return;
    if(removed[now]) {solve(now+1); return;}
    removed[now]=now;
    for(auto to:G[now]){
        if(!removed[to]) removed[to]=now;
    }
    solve(now+1);
    bool f=true;
    for(auto to:rG[now]) if(chosen[to]) f=false;
    if(f) {chosen[now]=true; ans.push_back(now);}
    for(auto to:G[now]) if(removed[to]==now) removed[to]=0;
    removed[now]=0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); rG[v].push_back(u);
    }
    solve(1);
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}

