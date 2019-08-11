#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN];
bool is_prime[MAXN];
int n,sum2[MAXN];
int sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(i*prime[j]>n) break;
            is_prime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    freopen("fourprimes.in","r",stdin);
    freopen("fourprimes.out","w",stdout);
    int p=sieve(100000);
    for(int i=0;i<p;i++)
        for(int j=0;j<p;j++)
        {
            if(prime[i]+prime[j]>=100000) break;
            sum2[prime[i]+prime[j]]++;
        }
    scanf("%d",&n);
    ll ans=0;
    for(int i=4;i<=n-4;i++) ans+=1LL*sum2[i]*sum2[n-i];
    printf("%lld\n",ans);
    return 0;
}
