#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-8
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN];
bool is_prime[MAXN];
double sum[100];
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
int solve(double res,int num)
{
	if(res>sum[num]) return 0;
	if(num>=7&&is_prime[num]) return solve(res,num+1);
	if(max(res,-res)<EPS) return 1;
	if(res<0||num>35) return 0;
	return solve(res,num+1)+solve(res-1.0/(num*num),num+1);
}
int main()
{
	sieve(100);
	memset(sum,0,sizeof(sum));
	for(int i=80;i>=2;i--)
		sum[i]=1.0/(i*i)+sum[i+1];
	printf("%d\n",solve(0.5,2));
	return 0;
}