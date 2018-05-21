#include<bits/stdc++.h>
#define MAXN 100000005
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
            if(1LL*prime[j]*i>n) break;
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
    for(int i=1;i<=100000000;i++)
        cnt[i]=is_prime[i]?cnt[i-1]+1:cnt[i-1];
    int ans=0,cnt1=0;
    for(int i=0;i<p;i++)
    {
        ans+=cnt[100000000/prime[i]];
        if(1LL*prime[i]*prime[i]<100000000) cnt1++;
    }
    printf("%d\n",(ans-cnt1)/2+cnt1);
    return 0;
}