#include<bits/stdc++.h>
#define MAXN 1000005
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
	sieve(1000000);
	int sum=0,res=0;
	for(int i=91;i<=1000000;i+=2)
	{
		if(is_prime[i]||i%5==0) continue;
		int num=find_ans(i);
		if((i-1)%num==0)
		{
			printf("%d\n",i);
			res++;
			sum+=i;
		}
		if(res==25) break;
	}
	printf("%d\n",sum);
	return 0;
}