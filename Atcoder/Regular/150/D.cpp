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
int inv[MAXN],sum[MAXN],dep[MAXN],ans;
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dfs(int v)
{
    add(ans,sum[dep[v]]);
    for(auto to:G[v])
    {
        dep[to]=dep[v]+1;
        dfs(to);
    }
}
int main()
{
    inv[1]=1;
    for(int i=2;i<=200000;i++) inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    sum[1]=1;
    for(int i=2;i<=200000;i++) {sum[i]=sum[i-1]; add(sum[i],inv[i]);}
    scanf("%d",&n);
    for(int i=2;i<=n;i++) 
    {
        int x;
        scanf("%d",&x);
        G[x].push_back(i);
    }
    dep[1]=1; dfs(1);
    printf("%d\n",ans);
    return 0;
}

