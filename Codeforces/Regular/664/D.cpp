#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t[MAXN],h[MAXN];
vector<int> G[MAXN];
ll dp[MAXN][3];//0: nothing 1: father down 2: father up
void dfs(int v,int p){
    ll alldown=0,allup=0,downup=-INF;
    int x=0,y=0; //all down initially
    ll sum=0;
    vector<ll> vec;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        if(h[to]<h[v]) {
            x++; sum+=dp[to][1];
        }
        else if(h[to]>h[v]){
            y++; sum+=dp[to][2];
        }
        else{
            x++; sum+=dp[to][1]; vec.push_back(dp[to][2]-dp[to][1]);
        }
    }
    sort(vec.begin(),vec.end(),greater<int>());
    dp[v][0]=dp[v][1]=dp[v][2]=0;
    ll s=0;
    for(int i=0;i<=(int)vec.size();i++){
        dp[v][0]=max(dp[v][0],1LL*min(x-i,y+i)*t[v]+(sum+s));
        dp[v][1]=max(dp[v][1],1LL*min(x-i,y+i+1)*t[v]+(sum+s));
        dp[v][2]=max(dp[v][2],1LL*min(x-i+1,y+i)*t[v]+(sum+s));
        if(i!=(int)vec.size()) s+=vec[i];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=1LL*(int)G[i].size()*t[i];
    ans-=dp[1][0];
    printf("%lld\n",ans);
    return 0;
}

