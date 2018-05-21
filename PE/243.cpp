#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
    int p=sieve(100000);
    ll ans=1000000000000000000;
    for(int i=0;i<10;i++)
    {
        ll res=1,l=15499,r=94744;
        for(int j=0;j<i;j++)
        {
            res=res*prime[j];
            l=l*prime[j];
            r=r*(prime[j]-1);
        }
        if(l<=r) continue;
        ll mult=(15499-1)/(l-r)+1;
        ans=min(ans,res*mult);
    }
    printf("%lld\n",ans);
    return 0;
}

