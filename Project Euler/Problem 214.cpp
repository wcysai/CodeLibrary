#include<bits/stdc++.h>
#define MAXN 40000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
ll prime[MAXN],phi[MAXN],ans[MAXN];
bool is_prime[MAXN];
void genphi(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1;}
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
}
ll find_ans(ll x)
{
    if(ans[x]!=-1) return ans[x];
    if(x==1) return ans[x]=1;
    return ans[x]=find_ans(phi[x])+1;
}
int main()
{
    genphi(40000000);
    memset(ans,-1,sizeof(ans));
    for(ll i=1;i<=40000000;i++)
        if(ans[i]==-1) find_ans(i);
    ll res=0;
    for(ll i=1;i<=40000000;i++)
        if(is_prime[i]&&ans[i]==25) res+=i;
    printf("%I64d\n",res);
    return 0;
}

