#include<bits/stdc++.h>
#define MAXN 10000005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
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
    int p=sieve(10000000);
    int cnt=0;
    for(int i=647;;i++)
    {
        int t=i,num=0;
        for(int j=0;j<p;j++)
        {
            if(t%prime[j]==0)
            {
                num++;
                while(t%prime[j]==0) t=t/prime[j];
                if(is_prime[t])
                {
                    num++;
                    break;
                }
                if(t==1) break;
            }
        }
        if(num==4) cnt++; else cnt=0;
        if(cnt==4)
        {
            printf("%d %d %d %d\n",i-3,i-2,i-1,i);
            break;
        }
    }
    return 0;
}


