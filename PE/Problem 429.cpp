#include<bits/stdc++.h>
#define MAXN 100000005
#define MAXP 5800005
#define INF 1000000000
#define MOD 1000000009
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXP],cnt[MAXP];
bool is_prime[MAXN];
int save[MAXN];
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
	int p=sieve(100000000);
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<p;i++)
		save[prime[i]]=i;
	puts("Phase1 complete!");
	for(int i=2;i<=100000000;i++)
	{
		int t=i;
		for(int j=0;j<p;j++)
		{
			if(is_prime[t]) {cnt[save[t]]++; break;}
			if(t==1) break;
			while(t%prime[j]==0) {cnt[j]++; t=t/prime[j];}
		}
	}
	puts("Phase2 complete!");
	ll ans=1;
	for(int i=0;i<p;i++)
	{
		ll s=1;
		for(int j=0;j<cnt[i];j++)
			s=s*prime[i]%MOD;
		s=s*s%MOD;
		if(s>1) ans=ans*(s+1)%MOD;
	}
	puts("Phase3 complete!");
	printf("%I64d\n",ans);
	return 0;
}