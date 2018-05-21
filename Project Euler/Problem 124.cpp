#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
P a[MAXN];
int main()
{
	int p=sieve(100000);
	for(int i=1;i<=100000;i++)
	{
		int t=i,res=1;
		for(int j=0;j<p;j++)
		{
			if(t==1) break;
			if(t%prime[j]==0) res=res*prime[j];
		}
		a[i].F=res;
		a[i].S=i;
	}
	sort(a+1,a+100000+1);
	printf("%d %d %d\n",a[4].S,a[6].S,a[10000].S);
	return 0;
}