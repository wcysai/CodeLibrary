#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int n,k,prime[MAXN],phi[MAXN];
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
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main(){
    scanf("%d%d",&n,&k);
    if(k==1) {puts("3"); return 0;}
    sieve(n);
    vector<int> v;
    for(int i=3;i<=n;i++){
        v.push_back(phi[i]);
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=0;i<k;i++) ans+=v[i];
    printf("%lld\n",ans+2);
    return 0;
}
