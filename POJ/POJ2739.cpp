#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 10001
using namespace std;
int prime[MAXN],cnt[MAXN];
bool is_prime[MAXN+1];
int sum[MAXN];
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
	int x,cnt;
	int p=sieve(10000);
    sum[1]=prime[1];
    for(int i=2;i<=p;i++)
      sum[i]=prime[i]+sum[i-1];
    sum[0]=0;
    scanf("%d",&x);
    while(x!=0)
    {
    	cnt=0;
    int l=0,r=1;
    while(r<p)
    {
    	while(sum[r]-sum[l]<x)
    	  	r++;
    	if(sum[r]-sum[l]==x) 
    	{
    	  cnt++;
    	  l++;
        }
    	while(sum[r]-sum[l]>x)
    	  l++;
	}
	printf("%d\n",cnt);
	scanf("%d",&x);
   }
	return 0;
} 