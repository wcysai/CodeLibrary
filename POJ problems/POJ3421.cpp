#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 1048577
using namespace std;
int prime[82026],lhy[MAXN],zjy[MAXN];
bool is_prime[MAXN+1];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
        if(is_prime[i])
    {
        prime[++p]=i;
        for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
    }
    return p;
}

int main()
{
    int num,x;
    num=sieve(MAXN);
    memset(zjy,0,sizeof(zjy));
    memset(lhy,0,sizeof(lhy));
    zjy[1]=1;
    for(int i=1;i<=MAXN/2;i++)
    {
        int j=1;
        while(prime[j]*i<=MAXN&&j<=num)
        {
            lhy[prime[j]*i]=lhy[i]+1;
            zjy[prime[j]*i]+=zjy[i];
            j++;
        }
    }
    while(scanf("%d",&x)==1)
        printf("%d %d\n",lhy[x],zjy[x]);
    return 0;
}
