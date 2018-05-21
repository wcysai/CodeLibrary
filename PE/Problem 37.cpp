#include<bits/stdc++.h>
#define MAXN 10000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
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
    int p=sieve(10000000);
    int ans=0,cnt=0;
    for(int i=0;i<p;i++)
    {
        if(prime[i]<10) continue; 
        int t=prime[i];
        bool f=true;
        while(t>=10)
        {
            t=t/10;
            if(!is_prime[t]) {f=false; break;}
        }
        if(!f) continue;
        int mod=1;
        while(mod<prime[i])
        {
            mod=mod*10;
            if(!is_prime[prime[i]%mod]) {f=false; break;}
        }
        if(f)
        {
            cnt++;
            ans+=prime[i];
            printf("%d\n",prime[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}


