#include<bits/stdc++.h>
#define MAXN 5000005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
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
	int p=sieve(5000000);
	int res=0,t=0;
	for(int i=-1000;i<=1000;i++)
		for(int j=-1000;j<=1000;j++)
		{
			int cnt=0;
			for(int n=0;;n++)
			{
				int ans=n*n+i*n+j;
				if(ans<0||!is_prime[ans]) break;
				//printf("%d\n",ans);
				cnt++; 
			}
			if(cnt>res)
			{
				res=cnt;
				t=i*j;
			}
		}
	printf("%d\n",t);
	return 0;
}