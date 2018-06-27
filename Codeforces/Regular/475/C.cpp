#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,k,a[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
int low[MAXN],high[MAXN],tt[MAXN];
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
ll w,h,c;
int main()
{
	int p=sieve(1000000);
	scanf("%d",&n);
	memset(low,0,sizeof(low));
	for(int i=0;i<MAXN;i++) high[i]=INF;
	vector<int> fact;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&w,&h,&c);
		fact.clear();
		for(int j=0;j<p;j++)
	}
	return 0;
}