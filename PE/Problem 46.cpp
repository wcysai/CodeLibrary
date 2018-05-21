#include<bits/stdc++.h>
#define MAXN 10000005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN],issqr[MAXN];
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
    sieve(10000000);
    memset(issqr,false,sizeof(issqr));
    for(int i=1;i*i<=10000000;i++)
        issqr[i*i]=true;
    for(int i=33;;i+=2)
    {
        if(is_prime[i]) continue;
        bool f=false;
        for(int j=0;prime[j]<i;j++)
        {
            if((i-prime[j])%2==0&&issqr[(i-prime[j])/2])
            {
                f=true;
                break;
            }
        }
        if(!f) {printf("%d\n",i); break;}
    }
    return 0;
}


