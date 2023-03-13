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
int t,n,k,a[MAXN];
vector<int> G[MAXN];
int l1,l2,cur;
P dp[MAXN];
void dfs(int v,int p){
    int cnt=0,son=0;
    vector<int> save;
    P maxi=P(-1,0);
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        son++;
        if(dp[to].F>0) {cnt++; if(dp[to].F!=INF) save.push_back(dp[to].S);}
        maxi=max(maxi,dp[to]);
    }
    if(son==0){
        dp[v]=P(cur-1,v);
    }
    else if(cnt>=2||maxi.F==INF) 
    {
        dp[v]=P(INF,maxi.S);
        if(l1==-1&&l2==-1&&cnt>=2){
            l1=save[0]; l2=save[1];
        }
    }
    else {
        dp[v]=maxi; if(dp[v].F>0) dp[v].F--;
    }
}
bool check(int x){
    l1=l2=-1; cur=x;
    dfs(1,0);
    if(dp[1].F==0) return true;
    if(l1>=1&&l1<=n)
    {
        dfs(l1,0);
        if(dp[l1].F==0) return true;
    }
    if(l2>=1&&l2<=n)
    {
        dfs(l2,0);
        if(dp[l2].F==0) return true;
    }
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        int l=1,r=n+1;
        while(r-l>1){
            int mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}

