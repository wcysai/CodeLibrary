#include<bits/stdc++.h>
#define MAXN 100000005
#define MAXP 5800005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXP];
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
int extgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int mod_inverse(int a,int m)
{
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
int main()
{
	int p=sieve(100000000);
	ll sum=4;
	for(int i=3;i<p;i++)
	{
		ll res=prime[i]-1,now=prime[i]-1;
		for(int j=prime[i]-1;j>=prime[i]-4;j--)
		{
			now=now*mod_inverse(j,prime[i])%prime[i];
			res=(res+now)%prime[i];
		}
		sum+=res;
	}
	printf("%I64d\n",sum);
	return 0;
}