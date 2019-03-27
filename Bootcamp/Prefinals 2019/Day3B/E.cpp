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
int n,p[MAXN],q[MAXN];
int k[MAXN],b[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
//E[i]=kE[1]+b
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&q[i]);
    for(int i=n;i>=1;i--)
    {
        int pr=1LL*p[i]*pow_mod(q[i],MOD-2)%MOD;
        int qr=1-pr; if(qr<0) qr+=MOD;
        k[i]=1LL*k[i+1]*pr%MOD; add(k[i],qr);
        b[i]=1LL*pr*b[i+1]%MOD; add(b[i],1);
    }
    int ans=1; dec(ans,k[1]);
    ans=1LL*b[1]*pow_mod(ans,MOD-2)%MOD;
    printf("%d\n",ans);
    return 0;
}

