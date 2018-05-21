#include<bits/stdc++.h>
#define MAXN 20000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN],cnt[MAXN];
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
int main()
{
    int p=sieve(20000000);
    memset(cnt,0,sizeof(cnt));
    for(int i=15000001;i<=20000000;i++)
    {
    	int t=i;
    	while(t>1)
    	{
    		for(int j=0;j<p;j++)
    		{
    			while (t%prime[j]==0) {cnt[prime[j]]++; t=t/prime[j];}
    			if(t==1) break;
	    		if(is_prime[t])
	    		{
	    			cnt[t]++;
	    			t=1;
	    			break;
	    		}
	    	}
    	}
    }
    for(int i=1;i<=5000000;i++)
    {
    	int t=i;
    	while(t>1)
    	{
    		for(int j=0;j<p;j++)
    		{
    			while (t%prime[j]==0) {cnt[prime[j]]--; t=t/prime[j];}
    			if(t==1) break;
	    		if(is_prime[t])
	    		{
	    			cnt[t]--;
	    			t=1;
	    			break;
	    		}
	    	}
    	}
    }
    ll ans=0;
    for(int i=0;i<p;i++)
    	ans+=(ll)cnt[prime[i]]*prime[i];
    printf("%I64d\n",ans);
    return 0;
}

