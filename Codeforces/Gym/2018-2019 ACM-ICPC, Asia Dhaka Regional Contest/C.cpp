#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 10000007
#define INV 5000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
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
int main()
{
    int p=sieve(1000000);
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        int ans=1;
        for(int i=0;i<p;i++)
        {
            int cnt=0,dummy=n;
            while(dummy>=prime[i]) cnt+=dummy/prime[i],dummy/=prime[i];
            if(cnt)
            {
                ans=1LL*ans*(cnt+1)%MOD*(cnt+2)%MOD*INV%MOD;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

