#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000003
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int q,x[MAXN],d[MAXN],n[MAXN];
int fact[MAXN],invf[MAXN];
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
int get_ans(int l,int r)
{
    if(l==0) return fact[r];
    return 1LL*fact[r]*invf[l-1]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<MOD;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[MOD-1]=pow_mod(fact[MOD-1],MOD-2);
    for(int i=MOD-2;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&q);
    for(int i=1;i<=q;i++) scanf("%d%d%d",&x[i],&d[i],&n[i]);
    for(int i=1;i<=q;i++)
    {
        if(d[i]==0) printf("%d\n",pow_mod(x[i],n[i]));
        else if(x[i]==0) puts("0");
        else
        {
            int mult=1LL*x[i]*pow_mod(d[i],MOD-2)%MOD;
            int ans=pow_mod(d[i],n[i]);
            if(n[i]>=MOD) puts("0");
            else
            {
                int l=mult,r=(mult+n[i]-1)%MOD;
                int res;
                if(l<=r) res=get_ans(l,r);
                else res=0;
                ans=1LL*res*ans%MOD;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

