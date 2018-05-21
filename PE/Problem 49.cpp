#include<bits/stdc++.h>
#define MAXN 10005
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
bool isperm(int n,int m)
{
	int num[10];
	memset(num,0,sizeof(num));
	while(n>0)
	{
		num[n%10]++;
		n/=10;
	}
	while(m>0)
	{
		num[m%10]--;
		m/=10;
	}
	for(int i=0;i<9;i++)
		if(num[i]!=0) return false;
	return true;
}
int main()
{
	int p=sieve(10000);
	for(int i=0;i<p;i++)
		for(int j=i+1;j<p;j++)
		{
			if(prime[i]<1000||prime[j]<1000) continue;
			int k=2*prime[j]-prime[i];
			if(k>10000||k<1000||!is_prime[k]) continue;
			if(!isperm(prime[i],prime[j])||!isperm(prime[j],k)) continue;
			printf("%d%d%d\n",prime[i],prime[j],k);
		}
	return 0;
}


