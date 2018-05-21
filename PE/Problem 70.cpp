#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN],phi[MAXN];
bool is_prime[MAXN];
void genphi(int n)
{
    int p=0;
    memset(phi,0,sizeof(phi));
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
}
bool is_perm(int x,int y)
{
	int cnt[10];
	memset(cnt,0,sizeof(cnt));
	while(x)
	{
		cnt[x%10]++;
		x=x/10;
	}
	while(y)
	{
		cnt[y%10]--;
		y=y/10;
	}
	for(int i=0;i<10;i++)
		if(cnt[i]!=0) return false;
	return true;
}
int main()
{
	genphi(10000000);
	double ans=10000000;
	int t=-1;
	for(int i=2;i<10000000;i++)
	{
		if(is_perm(i,phi[i]))
		{
			if((double)i/phi[i]<ans)
			{
				ans=(double)i/phi[i];
				t=i;
			}
		}
	}
	printf("%d %.10f\n",t,ans);
	return 0;
}