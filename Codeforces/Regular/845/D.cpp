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
int f[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dfs(int v,int p){
    f[v]=1;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v); f[v]=max(f[v],f[to]+1);
    }
}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(1,0);
        int ans=0;
        for(int i=1;i<=n;i++) add(ans,f[i]);
        ans=1LL*ans*pow_mod(2,n-1)%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

