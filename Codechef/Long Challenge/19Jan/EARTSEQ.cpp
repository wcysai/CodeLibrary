#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,N;
ll prime[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
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
    scanf("%lld",&T);
    ll p=sieve(100000);
    while(T--)
    {
        scanf("%lld",&N);
        if(N==3) {puts("6 10 15"); continue;}
        if(N==4) {puts("374 595 1365 858"); continue;}
        if(N==5) {puts("10 15 21 77 22"); continue;}
        ll k=3;
        for(ll i=2;i<p;i++) if((prime[i]-1)*prime[i]/2<=N-3) k=prime[i]; else break;
        for(ll i=1;i<=(k-1)/2;i++)
        {
            ll cur=0;
            for(ll j=0;j<k;j++) 
            {
                printf("%lld ",prime[cur]*prime[(cur+i)%k]);
                cur=(cur+i)%k;
            }
        }
        ll rem=N-k*(k-1)/2-1;
        printf("%lld ",2*prime[k]);
        ll now=k,pos=1;
        if(rem%2==0) {printf("%lld ",prime[now]*prime[now+1]); rem--; now++;}
        while(rem>2)
        {
            printf("%lld ",prime[now]*prime[pos]);
            printf("%lld ",prime[pos]*prime[now+1]);
            now++;rem-=2;pos++;
        }
        printf("%lld\n",prime[now]*2);
    }
    return 0;
}

