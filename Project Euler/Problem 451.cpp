#include<bits/stdc++.h>
#define MAXN 20000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int ans[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
vector<int> G[MAXN];
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
int main()
{
	int p=sieve(20000000);
	for(int i=2;i<=20000000;i++)
	{
		for(int j=2*i;j<=20000000;j+=i)
			G[j].push_back(i);
	}
	for(int i=3;i<=20000000;i++)
		ans[i]=1;
	for(int i=2;i<=19999999;i++)
	{
		 for(int j=0;j<G[i-1].size();j++)
		 {
		     for(int k=0;k<G[i+1].size();k++)
		     {
		     	if((ll)G[i-1][j]*G[i+1][k]>20000000||(ll)G[i-1][j]*G[i+1][k]>=2*i) break;
		     	if(G[i-1][j]*G[i+1][k]>i+1&&G[i-1][j]*G[i+1][k]<2*i) ans[G[i-1][j]*G[i+1][k]]=max(ans[G[i-1][j]*G[i+1][k]],i);
		     }
		 }
	}
	for(int i=3;i<=100;i++)
		printf("%d %d\n",i,ans[i]);
	return 0;
}
