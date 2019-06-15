#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 100000000000LL
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
int p[10]={2,3,5,7,11,13,17,19,23,29};
ll w[10][10];
int perm[MAXN];
set<ll> s;
bool check()
{
    for(int i=0;i<n;i++) perm[i]=i;
    s.clear();
    do
    {
        if(perm[0]>perm[n-1]) continue;
        ll ss=0;
        for(int i=0;i<n-1;i++) ss+=w[perm[i]][perm[i+1]];
        if(ss>INF) return false;
        if(ss==5549756) 
        {
            printf("%lld\n",ss); 
            for(int i=0;i<n;i++) printf("%d ",perm[i]);
            puts("");
            //return false;
        }
        s.insert(ss);
    }while(next_permutation(perm,perm+n));
    return true;
}
int main()
{
    scanf("%d",&n);
    ll sum=1;
    for(int i=0;i<n;i++) sum=sum*p[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j) 
            {
                ll r=sum/p[i]/p[j];
                ll x=0;
                while(x%p[i]!=(j+1)%p[i]||x%p[j]!=(i+1)%p[j]) x+=r; 
                w[i][j]=x+((j+1)/p[i]+(i+1)/p[j])*sum;
            }
    if(check()) puts("chuochuo"); else puts("shangshang");
    return 0;
}

