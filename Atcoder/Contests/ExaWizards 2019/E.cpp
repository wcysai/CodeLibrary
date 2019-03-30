#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
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
int n,m,a[MAXN];
int fact[MAXN],invf[MAXN];
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int s1=0,s2=0,denom=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+m;i++)
    {
        int res=denom; dec(res,s1); add(res,s2);
        denom=2LL*denom%MOD;
        res=1LL*res*pow_mod(denom,MOD-2)%MOD;
        printf("%d\n",res);
        s1=2LL*s1%MOD; s2=2LL*s2%MOD;
        if(i>=n) add(s1,comb(i-1,i-n));
        if(i>=m) add(s2,comb(i-1,i-m));
    }
    return 0;
}

