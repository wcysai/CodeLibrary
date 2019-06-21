#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN];
int f[MAXN],g[MAXN];
vector<int> G[MAXN];
int fact[MAXN],cnt[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dfs(int v,int p)
{
    f[v]=1; cnt[v]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        cnt[v]++;
        dfs(to,v);
        f[v]=1LL*f[v]*f[to]%MOD;
    }
    if(v==1) f[v]=1LL*f[v]*fact[cnt[v]]%MOD;
    else f[v]=1LL*f[v]*fact[cnt[v]+1]%MOD;
}
int main()
{
    fact[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    f[1]=1LL*f[1]*n%MOD;
    printf("%d\n",f[1]);
    return 0;
}

