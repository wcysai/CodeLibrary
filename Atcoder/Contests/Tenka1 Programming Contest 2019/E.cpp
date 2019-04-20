#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 10005
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
int n,a[MAXN],poly[MAXN];
set<int> ans;
int prime[10*MAXN];
bool is_prime[10*MAXN];
int sieve(int n)
{
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    int p=0;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
mt19937 wcy(time(NULL));
int main()
{
    int p=sieve(100000);
    scanf("%d",&n);
    for(int i=0;i<=n;i++) scanf("%d",&a[i]);
    reverse(a,a+n+1);
    int g=0;
    for(int i=0;i<=n;i++) g=__gcd(g,a[i]);
    g=abs(g);
    for(int i=0;i<p;i++) 
    {
        int cnt=0;
        while(g%prime[i]==0) g/=prime[i],cnt++;
        if(cnt) ans.insert(prime[i]);
    }
    if(g!=1) ans.insert(g);
    for(int i=0;i<p;i++)
    {
        if(prime[i]>n) break;
        if(ans.count(prime[i])) continue;
        bool f=true;
        memset(poly,0,sizeof(poly));
        if(a[0]%prime[i]!=0) continue;
        for(int j=0;j<=n;j++) poly[j%(prime[i]-1)]=(poly[j%(prime[i]-1)]+a[j])%prime[i];
        for(int j=0;j<10;j++)
        {
            int x=0;
            while(x==0) x=wcy()%prime[i];
            int res=1,sum=0;
            for(int k=0;k<=prime[i]-2;k++)
            {
                sum=(sum+1LL*poly[k]*res)%prime[i];
                res=1LL*res*x%prime[i];
            }
            if(sum!=0) {f=false; break;}
        }
        if(f)
        {
            for(int x=1;x<=prime[i]-1;x++)
            {
                int res=1,sum=0;
                for(int k=0;k<=prime[i]-2;k++)
                {
                    sum=(sum+1LL*poly[k]*res)%prime[i];
                    res=1LL*res*x%prime[i];
                }
                if(sum!=0) {f=false; break;}
            }
        }
        if(f) ans.insert(prime[i]);
    }
    for(auto x:ans) printf("%d\n",x);
    return 0;
}

