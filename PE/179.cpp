#include<bits/stdc++.h>
#define MAXN 10000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN],d[MAXN],num[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    memset(d,0,sizeof(d));
    memset(num,0,sizeof(num));
    num[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; num[i]=2; d[i]=1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) 
            {
                num[i*prime[j]]=num[i]/(d[i]+1)*(d[i]+2);
                d[i*prime[j]]=d[i]+1;
                break;
            }
            num[i*prime[j]]=num[i]*2;
            d[i*prime[j]]=1;
        }
    }
    return p;
}
int main()
{
    sieve(10000000);
    int cnt=0;
    for(int i=2;i<10000000;i++)
        if(num[i]==num[i+1]) cnt++;
    printf("%d\n",cnt);
    return 0;
}

