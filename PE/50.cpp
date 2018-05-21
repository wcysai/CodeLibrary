#include<bits/stdc++.h>
#define MAXN 2000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN],ans=0;
bool is_prime[MAXN];
bool C(int x,int p)
{
    if(x>p) return false;
    int sum=0;
    for(int i=0;i<x;i++)
        sum+=prime[i];
    if(sum>=1000000) return false;
    bool f=false;
    if(is_prime[sum])
    {
        ans=sum;
        f=true;
    }
    for(int i=1;i+x<=p;i++)
    {
        sum+=prime[i+x-1];
        sum-=prime[i-1];
        if(sum>=1000000) return f;
        if(is_prime[sum])
        {
            ans=sum;
            f=true;
        }
    }
    return f;
}
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
    int p=sieve(1000005);
    int t=-1;
    for(int i=1;i<=1000;i++)
    {
        if(C(i,p)) t=i;
        printf("%d\n",i);
    }
    printf("%d %d\n",t,ans);
    return 0;
}


