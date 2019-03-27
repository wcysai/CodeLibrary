#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n;
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
vector<int> poly;
int main()
{
    scanf("%d",&n);
    poly.push_back(1);
    for(int i=0;i<=n-1;i++)
    {
        int sz=(int)poly.size();
        poly.push_back(poly[sz-1]);
        for(int j=sz-1;j>=1;j--)
        {
            poly[j]=(poly[j-1]-1LL*poly[j]*i)%MOD;
            if(poly[j]<0) poly[j]+=MOD;
        }
        poly[0]=-1LL*poly[0]*i%MOD;
        if(poly[0]<0) poly[0]+=MOD;
    }
    int ans=0,now=2;
    for(int i=n-1;i>=0;i--)
    {
        dec(ans,1LL*pow_mod(now-1,MOD-2)*poly[i]%MOD);
        now=2LL*now%MOD;
    }
    printf("%d\n",ans);
    return 0;
}

