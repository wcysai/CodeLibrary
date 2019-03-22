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
int m,k,a[MAXN];
double dp[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
double solve(int x)
{
    if(x==1) return 0;
    if(dp[x]!=-1) return dp[x];
    int cnt=0;
    double res=0;
    for(int i=1;i<=m;i++)
    {
        if(i%x==0) cnt++;
        else res+=solve(__gcd(i,x));
    }
    res+=m;
    res=res/(m-cnt);
    return dp[x]=res;
}
int main()
{
    //for(int i=1;i<=100000;i++) inv[i]=pow_mod(i,MOD-2);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) dp[i]=-1;
    for(int i=1;i<=m;i++) printf("%.10f\n",solve(i));
    return 0;
}

