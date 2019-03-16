#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
ll T,n;
ll a[MAXN];
ll f[MAXN],g[MAXN];
//f[i]: number of sequences if we start from i
//g[i]: number of sequences if we start from i and end with i+1
//f[i]=1+f[i+1]+[a[i]==2]*(f[i+2]+1+(a[i+1]==2)*f[i+3]+(a[i+3]==2)*g[i+2])
//g[i]=[i!=n]*(1+[a[i]==2]*(1+[a[i+3]==2]*(g[i+2])))
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
        memset(f,0,sizeof(f));memset(g,0,sizeof(g));
        for(ll i=n;i>=1;i--)
        {
            if(i!=n) g[i]=1+(a[i]==2&&i+2<=n)*(1+(a[i+3]==2)*g[i+2]);
            f[i]=1+f[i+1]+(a[i]==2&&i+2<=n)*(f[i+2]+1+(a[i+1]==2)*f[i+3]+(a[i+3]==2)*g[i+2]);
            f[i]%=MOD; g[i]%=MOD;
        }
        printf("%lld\n",f[1]);
    }
    return 0;
}

