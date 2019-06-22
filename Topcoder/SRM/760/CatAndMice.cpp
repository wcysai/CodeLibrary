#include<bits/stdc++.h>
#define MAXN 5000005
using namespace std;
typedef long long ll;
int prime[MAXN],phi[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
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
            phi[prime[j]*i]=phi[i]*(i%prime[j]==0?prime[j]:prime[j]-1);
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
class CatAndMice {
	public:
	long long countDirections(int N, int C) {
        sieve(5000000);
	    ll ans=0;
        for(int i=1;i<=N;i++)
            if(N/i==C) ans+=8*phi[i];    
        return ans;
	}
};


// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]

// Powered by CodeProcessor
