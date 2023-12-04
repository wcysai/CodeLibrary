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
int t,n,k,b[MAXN];
vector<int> G[MAXN];
int d[MAXN],color[MAXN],maxi;
int ans;
bool flag;
void dfs(int v,int z){
    color[v]=1; ans=max(ans,z);
    for(auto to:G[v]){
        if(color[to]==1) {flag=true; return;}
        if(color[to]==0) dfs(to,z+1);
    }
    color[v]=2;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=0;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++){
            if(b[i]>n) continue;
            int need=(b[i]-i+n)%n;
            G[n-i].push_back(need);
        }
        flag=false;
        for(int i=0;i<=n;i++) color[i]=d[i]=0;
        ans=0;
        dfs(0,0);
        //printf("ans=%d\n",ans);
        if(flag||ans>=k) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}

