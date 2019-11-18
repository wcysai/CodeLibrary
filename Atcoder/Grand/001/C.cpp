#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,K,ans;
vector<int> G[MAXN];
int f[2][MAXN];
int dfs(int id,int v,int p,int k)
{
    f[id][v]=1;
    if(k==0) return f[id][v];
    for(auto to:G[v]) if(to!=p) f[id][v]+=dfs(id,to,v,k-1);
    return f[id][v];
}
int main()
{
    int ans=0;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int root=1;root<=N;root++)
    {
        dfs(0,root,0,K/2);
        dfs(1,root,0,(K+1)/2);
        int res=f[0][root],maxi=0;
        for(auto v:G[root]) maxi=max(maxi,f[1][v]-f[0][v]);
        if(K&1) ans=max(ans,res+maxi); else ans=max(ans,res);
    }
    printf("%d\n",N-ans);
    return 0;
}
