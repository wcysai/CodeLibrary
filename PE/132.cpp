#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k,a[MAXN];
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
int find_ans(int x)
{
	int cnt=1,t=1;
	if(x==1) return 0;
	while(t!=0)
	{
		t=(t*10+1)%x;
		cnt++;
	}
	return cnt;
}
int main()
{
	int p=sieve(100000);
	int sum=7;
	for(int i=0;i<p;i++)
	{
		int num=prime[i];
		if(num%2==0||num%5==0) continue;
		int x=find_ans(num);
		while(x%2==0) x=x/2;
		while(x%5==0) x=x/5;
		if(x!=1)
		{
			printf("%d\n",num);
			sum+=num;
		}
	}
	printf("%d\n",sum);
	return 0;
}