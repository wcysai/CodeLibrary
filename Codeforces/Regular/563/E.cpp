#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
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
int dp[MAXN];
vector<int> divi[MAXN];
int fact[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    int mx=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=1;
        mx=max(mx,f[i]);
        for(int j=2*i;j<=n;j++)
        {
            divi[j].push_back(i);
            f[j]=max(f[j],f[i]+1);
        }
    }
    for(int i=n;i>=2;i--)
    {
        if(f[i]==mx) add(g[i],1);
        if(!g[i]) continue;
        for(auto to:divi[i])
        {
            if(f[to]!=f[i]-1) continue;
            add(g[to],1LL*g[i]*(i/to-1)%MOD);
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++) if(f[i]==1) add(ans,g[i]);
    ans=1LL*ans*fact[n-mx]%MOD;
    printf("%d\n",ans); 
    return 0;
}

