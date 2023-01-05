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
int n,k,a[MAXN];
vector<int> G[MAXN];
int sz[MAXN];
int dp[MAXN];
int need[MAXN];
vector<int> ans;
void dfs(int v)
{
    sz[v]=1;
    dp[v]=(1<<a[v]);
    for(auto to:G[v]){
        dfs(to);
        sz[v]^=sz[to];
        ll tmp=0;
        for(int i=0;i<=31;i++)
        {
            if(!(dp[v]&(1<<i))) continue;
            for(int j=0;j<=31;j++)
                if(dp[to]&(1<<j)) tmp|=(1<<(i^j));
        }
        dp[v]=tmp;
    }
    if(!sz[v]) dp[v]|=1;
}
void dfs2(int v){
    if(need[v]==0&&sz[v]==0){
            ans.push_back(v); ans.push_back(v);
            return;
    }
    vector<int> predp;
    int cur=(1<<a[v]);
    predp.push_back(cur);
    for(auto to:G[v]){
        ll tmp=0;
        for(int i=0;i<=31;i++)
        {
            if(!(cur&(1<<i))) continue;
            for(int j=0;j<=31;j++)
                if(dp[to]&(1<<j)) tmp|=(1<<(i^j));
        }
        cur=tmp;
        predp.push_back(cur);
    }
    int t=(int)G[v].size();
    for(int i=t-1;i>=0;i--){
        int to=G[v][i];
        for(int j=0;j<=31;j++){
            if((dp[to]&(1<<j))&&(predp[i]&(1<<(j^need[v])))){
                need[to]=j;
                need[v]^=j;
                break;
            }
        }
    }
    assert(need[v]==a[v]);
    for(auto to:G[v]) dfs2(to);
    if(v==1) ans.push_back(v);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        int p;
        scanf("%d",&p);
        G[p].push_back(i);
    }
    dfs(1);
    if(!(dp[1]&1)) {puts("-1"); return 0;}
    need[1]=0; dfs2(1);
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}

