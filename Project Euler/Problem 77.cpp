#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN];
int dp[MAXN];
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
    int p=sieve(10000);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<p;i++)
        for(int j=prime[i];j<10000;j++)
            dp[j]+=dp[j-prime[i]];
    for(int i=0;i<=10000;i++)
        if(dp[i]>5000) 
        {
            printf("%d\n",i);
            return 0;
        }
    return 0;
}